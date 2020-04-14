#include "Board.h"

using namespace Core;

//----------------------------------------
//----------------public------------------
//----------------------------------------

Board::Board(int _dimension)
    :
        pointScoredLastRound(0),
        tileCollisionLastRound(false),
        dimension(_dimension)
{
    init();
}

Board::Board(const Board& other)
{
    dimension = other.dimension;
    init();
    for(int i = 0; i < dimension; ++i)
    {
        for(int j = 0; j < dimension; ++j)
        {
            if(other.board[i][j] == nullptr)
            {
                board[i][j] = nullptr;
            }
            else
            {
                board[i][j] = new Tile(*other.board[i][j]);
            }
        }
    }
}

Board::~Board()
{
    for(int i = 0; i < dimension; ++i)
    {
        for(int j = 0; j < dimension; ++j)
        {
            delete board[i][j];
        }
    }
}

void Board::reset()
{
    pointScoredLastRound = 0;
    tileCollisionLastRound = false;

    for(int i = 0; i < dimension; ++i)
    {
        for(int j = 0; j < dimension; ++j)
        {
            delete board[i][j];
            board[i][j] = nullptr;
        }
    }

    //重新开始出现两个砖块
    QPair<int, int> pos = getFreePosition();
    board[pos.first][pos.second] = new Tile();
    pos = getFreePosition();
    board[pos.first][pos.second] = new Tile();
}

Tile* Board::getTile(const int x, const int y) const
{
    return board[x][y];
}

int Board::getDimension() const
{
    return dimension;
}

void Board::move(const Direction direction)
{
    Board pre_move_board(*this);

    prepareForNextMove();

    switch (direction)
    {
        case Direction::UP:
            for(int i = 0; i < dimension; ++i)
            {
                for(int j = 0; j < dimension; ++j)
                {
                    moveVertically(i, j, Direction::UP);
                }
            }
            break;
        case Direction::DOWN:
            for(int i = 0; i < dimension; ++i)
            {
                for(int j = 0; j < dimension; ++j)
                {
                    moveVertically(i, j, Direction::DOWN);
                }
            }
            break;
        case Direction::LEFT:
            for(int i = 0; i < dimension; ++i)
            {
                for(int j = 0; j < dimension; ++j)
                {
                    moveHorizontally(i, j, Direction::LEFT);
                }
            }
            break;
        case Direction::RIGHT:
            for(int i = 0; i < dimension; ++i)
            {
                for(int j = 0; j < dimension; ++j)
                {
                    moveHorizontally(i, j, Direction::RIGHT);
                }
            }
            break;
        default:
            ;
    }

    if(isChanged(pre_move_board))
    {
        //每次移动增加新的砖块
        QPair<int, int> new_pos = getFreePosition();
        //每次新建有 1/10 几率新建 4，有 9/10 几率新建 2
        int r = rand() % 10;
        if(r == 9)
        {
            board[new_pos.first][new_pos.second] = new Tile(4);
        }
        else
        {
            board[new_pos.first][new_pos.second] = new Tile();
        }
    }

    notifyObservers();
}

bool Board::isFull() const
{
    for(int i = 0; i < dimension; ++i)
    {
        for(int j = 0; j < dimension; ++j)
        {
            if(board[i][j] == nullptr)
            {
                return false;
            }
        }
    }
    return true;
}

int Board::getPointsScoredLastRound() const
{
    return pointScoredLastRound;
}

bool Board::isTileCollisionLastRound() const
{
    return tileCollisionLastRound;
}

bool Board::canMove() const
{
    if(isFull())
    {
        //如果满了就要判断移动是否可以造成砖块升级(合并)
        Board new_board(*this);

        new_board.move(Direction::UP);
        if(isChanged(new_board))
        {
            return true;
        }
        new_board.move(Direction::DOWN);
        if(isChanged(new_board))
        {
            return true;
        }
        new_board.move(Direction::LEFT);
        if(isChanged(new_board))
        {
            return true;
        }
        new_board.move(Direction::RIGHT);

        //如果移动不会造成改变那么就无法再移动了
        return isChanged(new_board);
    }
    return true;
}

//----------------------------------------
//----------------private------------------
//----------------------------------------

void Board::init()
{
    board.resize(dimension);
    for(int i = 0; i < dimension; ++i)
    {
        board[i].resize(dimension);
        for(int j = 0; j < dimension; ++j)
        {
            board[i][j] = nullptr;
        }
    }
}

QPair<int, int> Board::getFreePosition()
{
    if(isFull())
    {
        return qMakePair(-1, -1);
    }
    else
    {
        int x;
        int y;
        do
        {
            x = rand() % dimension;
            y = rand() % dimension;
        }while(board[x][y] != nullptr);
        return qMakePair(x, y);
    }
}

bool Board::isChanged(Board &other) const
{
    if(dimension != other.dimension)
    {
        return false;
    }
    for(int i = 0; i < dimension; ++i)
    {
        for(int j = 0; j < dimension; ++j)
        {
            if(     //一个为空且另一个不为空
                    ((board[i][j] == nullptr && other.board[i][j] != nullptr) || (board[i][j] != nullptr && other.board[i][j] == nullptr))
                    ||
                    //两个都不为空且值不相同
                    (board[i][j] != nullptr && other.board[i][j] != nullptr && board[i][j]->getValue() != other.board[i][j]->getValue())
            )
                return true;
        }
    }
    return false;
}

bool Board::isInBounds(const int x, const int y)
{
    return x >= 0 && y >= 0 && x < dimension && y < dimension;
}

void Board::moveHorizontally(const int x, const int y, const Direction direction)
{
    if(board[x][y] != nullptr)
    {
        bool tile_collision = false;
        int new_y;
        if(direction == Direction::LEFT)
        {
            new_y = y - 1;
        }
        else
        {
            new_y = y + 1;
        }

        while(isInBounds(x, new_y) && board[x][new_y] == nullptr)
        {
            if(direction == Direction::LEFT)
            {
                --new_y;
            }
            else
            {
                ++new_y;
            }
        }

        //一路畅通直到越界
        if(!isInBounds(x, new_y))
        {
            if(direction == Direction::LEFT)
            {
                board[x][0] = board[x][y];
            }
            else
            {
                board[x][dimension - 1] = board[x][y];
            }
        }
        else
        {
            //被别的砖块挡住
            if(board[x][new_y]->getValue() == board[x][y]->getValue() && !board[x][new_y]->isUpgradedThisMove())
            {
                //值相同且不是多次折叠(一次移动最多折叠一次)
                tile_collision = true;
                handleCollision(x, new_y);
            }
            else
            {
                //不然就停在旁边
                if(direction == Direction::LEFT)
                {
                    board[x][new_y + 1] = board[x][y];
                }
                else
                {
                    board[x][new_y - 1] = board[x][y];
                }
            }
        }

        //去掉原来位置的砖块
        if((direction == Direction::LEFT && new_y + 1 != y) || (direction == Direction::RIGHT && new_y - 1 != y) || tile_collision)
        {
            board[x][y] = nullptr;
        }
        if(tile_collision)
        {
            tileCollisionLastRound = true;
        }
    }
}

void Board::moveVertically(const int x, const int y, const Direction direction)
{
    if(board[x][y] != nullptr)
    {
        bool tile_collision = false;
        int new_x;
        if(direction == Direction::UP)
        {
            new_x = x - 1;
        }
        else
        {
            new_x = x + 1;
        }

        while(isInBounds(new_x, y) && board[new_x][y] == nullptr)
        {
            if(direction == Direction::UP)
            {
                --new_x;
            }
            else
            {
                ++new_x;
            }
        }

        //一路畅通直到越界
        if(!isInBounds(new_x, y))
        {
            if(direction == Direction::UP)
            {
                board[0][y] = board[x][y];
            }
            else
            {
                board[dimension - 1][y] = board[x][y];
            }
        }
        else
        {
            //被别的砖块挡住
            if(board[new_x][y]->getValue() == board[x][y]->getValue() && !board[new_x][y]->isUpgradedThisMove())
            {
                //值相同且不是多次折叠(一次移动最多折叠一次)
                tile_collision = true;
                handleCollision(new_x, y);
            }
            else
            {
                //不然就停在旁边
                if(direction == Direction::UP)
                {
                    board[new_x + 1][y] = board[x][y];
                }
                else
                {
                    board[new_x - 1][y] = board[x][y];
                }
            }
        }

        //去掉原来位置的砖块
        if((direction == Direction::UP && new_x + 1 != x) || (direction == Direction::DOWN && new_x - 1 != x) || tile_collision)
        {
            board[x][y] = nullptr;
        }
        if(tile_collision)
        {
            tileCollisionLastRound = true;
        }
    }
}

void Board::handleCollision(const int x, const int y)
{
    //让位置处的砖块升级
    board[x][y]->upgrade();
    //这个位置标识为已经升级过了
    board[x][y]->setUpgradedThisMove(true);
    pointScoredLastRound += board[x][y]->getValue();
}

void Board::prepareForNextMove()
{
    tileCollisionLastRound = false;
    pointScoredLastRound = 0;
    for(int i = 0; i < dimension; ++i)
    {
        for(int j = 0; j < dimension; ++j)
        {
            if(board[i][j] != nullptr)
            {
                board[i][j]->setUpgradedThisMove(false);
            }
        }
    }
}

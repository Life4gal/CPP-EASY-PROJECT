#include "Board.h"

using namespace Core;

Board::Board(int _width, int _height) : width(_width), height(_height)
{
    init();
}

Board::Board(const Board& other) : width(other.width), height(other.height)
{
    init();

    for(int i = 0; i < height; ++i)
    {
        for(int j = 0; j < width; ++j)
        {
            if(other.grid[i][j] != nullptr)
            {
                grid[i][j] = new Tile(i, j);
            }
        }
    }
}

Board::~Board()
{
    for(int i = 0; i < height; ++i)
    {
        for(int j = 0; j < width; ++j)
        {
            delete grid[i][j];
        }
    }
}

void Board::init()
{
    // 有多少行
    grid.resize(height);
    for(int i = 0; i < height; ++i)
    {
        // 有多少列
        grid[i].resize(width);
        // 重设所有砖块状态
        for(int j = 0; j < width; ++j)
        {
            delete grid[i][j];
            grid[i][j] = nullptr;
        }
    }
}

bool Board::isExist(const Tetris &tetris) noexcept
{
    // 先检查位置，因为位置可能超界，没有超界再检查位置处有没有别的砖块
    for(Tile* tile : tetris.position)
    {
        auto [row, col] = *tile;
        if(row < 0 || row >= height || col < 0 || col >= width || grid[row][col] != nullptr)
        {
            return true;
        }
    }

    return false;
}

void Board::removeTetrisFromBoard(const Tetris& tetris)
{
    for(Tile* tile : tetris.position)
    {
        auto [row, col] = *tile;
        delete grid[row][col];
        grid[row][col] = nullptr;
    }
}

void Board::addTetrisIntoBoard(const Tetris &tetris)
{
    for(Tile* tile : tetris.position)
    {
        auto [row, col] = *tile;
        grid[row][col] = new Tile(row, col);
    }
}

int Board::clearLines()
{
    // 消除的行数
    int lines = 0;
    // 基线(最后一行不能消除的行，从下往上算)
    int base_row = height - 1;
    // 从下到上每一行
    for(int row = height - 1; row >= 0; --row)
    {
        LineState state = lineState(row);
        if(state == LineState::empty)
        {
            // 有一行空的就没必要往上了
            break;
        }
        else if(state == LineState::full)
        {
            for(int col = 0; col < width; ++col)
            {
                delete grid[row][col];
                grid[row][col] = nullptr;
            }
            ++lines;
        }
        else
        {
            // 不能消除，移动到基线上
            if(row != base_row)
            {
                for(int col = 0; col < width; ++col)
                {
                    if(grid[row][col] != nullptr)
                    {
                        auto [x, y] = *grid[row][col];
                        delete grid[row][col];
                        grid[row][col] = nullptr;
                        grid[base_row][col] = new Tile(x, y);
                    }
                }
            }
            // 基线上升一行
            --base_row;
        }
    }
    return lines;
}

Board::LineState Board::lineState(int index) const noexcept
{
    bool empty = true;
    bool hasNull = false;
    for(Tile* tile : grid[index])
    {
        if(tile != nullptr)
        {
            empty = false;
        }
        else
        {
            hasNull = true;
        }
        if(hasNull && !empty)
        {
            return LineState::mixed;
        }
    }
    if(empty)
    {
        return LineState::empty;
    }
    else
    {
        return LineState::full;
    }
}

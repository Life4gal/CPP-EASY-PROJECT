#include "Game.h"

using namespace Core;

Game::Game(int width, int height) noexcept
    : board(new Board(width, height)), gameOver(false), score(0)
{
    restart();
}

Game::~Game()
{
    delete board;
}

void Game::restart() noexcept
{
    board->init();
    gameOver = false;
    score = 0;

    randomGenerate();
}

Board* Game::getGameBoard() noexcept
{
    return board;
}

void Game::move(const Game::Direction &direction) noexcept
{
    switch (direction)
    {
        case Direction::UP:
            rotate();
            break;
        case Direction::DOWN:
            moveDown();
            break;
        case Direction::LEFT:
            moveLeft();
            break;
        case Direction::RIGHT:
            moveRight();
            break;
        default:
            break;
    }

    notifyObservers();
}

bool Game::isGameOver() noexcept
{
    return gameOver;
}

int Game::getScore() noexcept
{
    return score;
}

void Game::rotate() noexcept
{
    board->removeTetrisFromBoard(tetris);
    tetris.rotate(0, board->height - 1, 0, board->width - 1);
    board->addTetrisIntoBoard(tetris);
}

void Game::moveDown() noexcept
{
    board->removeTetrisFromBoard(tetris);
    tetris.moveVertically(1);
    if(board->isExist(tetris))
    {
        // 超界了回退一步
        tetris.moveVertically(-1);
        board->addTetrisIntoBoard(tetris);
        score += board->clearLines();
        randomGenerate();
    }
    else
    {
        board->addTetrisIntoBoard(tetris);
    }
}

void Game::moveLeft() noexcept
{
    board->removeTetrisFromBoard(tetris);
    tetris.moveHorizontally(-1);
    if(board->isExist(tetris))
    {
        // 超界了回退一步
        tetris.moveHorizontally(1);
        board->addTetrisIntoBoard(tetris);
    }
    else
    {
        board->addTetrisIntoBoard(tetris);
    }
}

void Game::moveRight() noexcept
{
    board->removeTetrisFromBoard(tetris);
    tetris.moveHorizontally(1);
    if(board->isExist(tetris))
    {
        // 超界了回退一步
        tetris.moveHorizontally(-1);
        board->addTetrisIntoBoard(tetris);
    }
    else
    {
        board->addTetrisIntoBoard(tetris);
    }
}

void Game::randomGenerate() noexcept
{
    switch (QRandomGenerator::global()->bounded(7))
    {
        case 0:
            tetris = Tetris_Line;
            break;
        case 1:
            tetris = Tetris_Rect;
            break;
        case 2:
            tetris = Tetris_L;
            break;
        case 3:
            tetris = Tetris_RL;
            break;
        case 4:
            tetris = Tetris_Z;
            break;
        case 5:
            tetris = Tetris_RZ;
            break;
        case 6:
            tetris = Tetris_T;
            break;
        default:
            tetris = Tetris_Line;
            break;
    }

    const int mid = board->width / 2;

    // 图形默认初始位置按照宽度为10放置
    tetris.validatePosition(mid - 5);

    // 随机旋转0-3次
    int rotate_times = QRandomGenerator::global()->bounded(4);
    while(rotate_times--)
    {
        tetris.rotate(0, 3, mid - 2, mid + 1);
        //tetris.rotate(0, 3, 3, 6);
    }

    // 新生成图形的位置如果被占据就算游戏失败
    if(board->isExist(tetris))
    {
        gameOver = true;
    }

    board->addTetrisIntoBoard(tetris);
}

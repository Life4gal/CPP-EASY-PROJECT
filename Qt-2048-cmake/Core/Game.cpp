#include "Game.h"

using namespace Core;

Game::Game(int dimension)
    : score(0), gameOver(false), board(new Board(dimension))
{
    restart();
}

Game::~Game()
{
    delete board;
    board = nullptr;
}

void Game::restart()
{
    board->reset();
    score = 0;
    gameOver = false;
}

bool Game::isGameOver() const
{
    return gameOver;
}

Board *Game::getGameBoard() const
{
    return board;
}

void Game::move(const Board::Direction direction)
{
    board->move(direction);

    if(board->isTileCollisionLastRound())
    {
        score += board->getPointsScoredLastRound();
    }

    if(!board->canMove())
    {
        gameOver = true;
    }

    notifyObservers();
}

bool Game::isWon() const
{
    for(int i = 0, dimension = board->getDimension(); i < dimension; ++i)
    {
        for(int j = 0; j < dimension; ++j)
        {
            if(Tile* tile = board->getTile(i, j); tile != nullptr && tile->getValue() == win_score)
            {
                return true;
            }
        }
    }
    return false;
}

int Game::getScore() const
{
    return score;
}

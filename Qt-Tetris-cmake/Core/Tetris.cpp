#include "Tetris.h"

using namespace Core;

Tetris::Tetris() noexcept : key(-1), position(QVector<Tile*>(4))
{
    init();
}

Tetris::Tetris(int _key,
        int pos0_row, int pos0_col,
        int pos1_row, int pos1_col,
        int pos2_row, int pos2_col,
        int pos3_row, int pos3_col) noexcept
        :
        key(_key)
{
    init();
    position[0] = new Tile(pos0_row, pos0_col);
    position[1] = new Tile(pos1_row, pos1_col);
    position[2] = new Tile(pos2_row, pos2_col);
    position[3] = new Tile(pos3_row, pos3_col);
}

Tetris::~Tetris()
{
    for(Tile* tile : position)
    {
        delete tile;
    }
}

Tetris& Tetris::operator=(const Tetris& other)
{
    if(&other == this)
    {
        return *this;
    }

    key = other.key;
    init();
    for(int i = 0; i < 4; ++i)
    {
        auto [row, col] = *other.position[i];
        position[i] = new Tile(row, col);
    }
}

bool Tetris::operator==(const Tetris& rhs)
{
    if(&rhs == this)
    {
        return true;
    }

    for(int i = 0; i < 4; ++i)
    {
        if(rhs.position[i] != position[i])
        {
            return false;
        }
    }

    return true;
}

void Tetris::init()
{
    position.resize(4);
    for(int i = 0; i < 4; ++i)
    {
        delete position[i];
        position[i] = nullptr;
    }
}

void Tetris::moveVertically(const int step) noexcept
{
    for(Tile* tile : position)
    {
        tile->row += step;
    }
}

void Tetris::moveHorizontally(const int step) noexcept
{
    for(Tile* tile : position)
    {
        tile->col += step;
    }
}

#include <iostream>

void Tetris::rotate(
        const int min_row, const int max_row,
        const int min_col, const int max_col) noexcept
{
    if(key > 0)
    {
        for(Tile* tile : position)
        {
            auto& [row, col] = *tile;
            int temp_row = row;
            int temp_col = col;
            Tile* key_tile = position[key];
            auto [key_row, key_col] = *key_tile;

            row = temp_col - key_col + key_row;
            col = key_row + key_col - temp_row;
        }

        auto [row_pair, col_pair] = getRowColMinMax();
        auto [curr_min_row, curr_max_row] = row_pair;
        auto [curr_min_col, curr_max_col] = col_pair;

        std::cout << "before" << std::endl;
        for(Tile* tile : position)
        {
            auto [x, y] = *tile;
            std::cout << x << "*" << y << std::endl;
        }

        //越界检查
        if(int step = curr_min_row - min_row; step < 0)
        {
            moveVertically(-step);
        }
        if(int step = curr_max_row - max_row; step > 0)
        {
            moveVertically(-step);
        }
        if(int step = curr_min_col - min_col; step < 0)
        {
            moveHorizontally(-step);
        }
        if(int step = curr_max_col - max_col; step > 0)
        {
            moveHorizontally(-step);
        }

        std::cout << "after" << std::endl;
        for(Tile* tile : position)
        {
            auto [x, y] = *tile;
            std::cout << x << "*" << y << std::endl;
        }
    }
}

void Tetris::validatePosition(int offset) noexcept
{
    moveHorizontally(offset);
}

QPair<QPair<int, int>, QPair<int, int>> Tetris::getRowColMinMax() const noexcept
{
    auto [min_row, min_col] = *position[0];
    auto [max_row, max_col] = *position[0];

    for(Tile* tile : position)
    {
        auto [row, col] = *tile;

        if(row < min_row)
        {
            min_row = row;
        }
        if(row > max_row)
        {
            max_row = row;
        }
        if(col < min_col)
        {
            min_col = col;
        }
        if(col > max_col)
        {
            col = max_col;
        }
    }

    return qMakePair(qMakePair(min_row, max_row), qMakePair(min_col, max_col));
}

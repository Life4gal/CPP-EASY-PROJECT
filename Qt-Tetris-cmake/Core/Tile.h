#ifndef QT_TETRIS_TILE_H
#define QT_TETRIS_TILE_H

#include <utility>

namespace Core
{

struct Tile
{
    Tile() noexcept  : row(0), col(0) {}
    explicit Tile(int _x, int _y) noexcept : row(_x), col(_y) {}
    /*
    Tile(const Tile& other) noexcept = default;
    Tile(Tile&& other) noexcept : row(other.row), col(other.col), isExist(other.isExist) {}
    Tile& operator=(const Tile& other) noexcept = default;
    Tile& operator=(Tile&& other) noexcept
    {
        row = other.row;
        col = other.col;
        isExist = other.isExist;
    }
    */

    int row;
    int col;
};

}

#endif //QT_TETRIS_TILE_H

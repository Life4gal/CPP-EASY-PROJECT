#ifndef QT_TETRIS_BOARD_H
#define QT_TETRIS_BOARD_H

#include "Tile.h"
#include "Tetris.h"

#include <QVector>
#include <QPair>

namespace Core
{

struct Board
{
    enum class LineState
    {
        empty,
        mixed,
        full
    };

    QVector<QVector<Tile*>> grid;
    int width;
    int height;

    Board(int width, int height);
    Board(const Board& other);
    ~Board();

    void init();

    // 判断位置是否被占用
    [[nodiscard]] bool isExist(const Tetris& tetris) noexcept ;
    // 将当前图形移除
    void removeTetrisFromBoard(const Tetris& tetris);
    // 将当前图形加入面板
    void addTetrisIntoBoard(const Tetris& tetris);
    // 消除能消除的行并返回分数
    [[nodiscard]] int clearLines();

    [[nodiscard]] LineState lineState(int index) const noexcept ;
};

}

#endif //QT_TETRIS_BOARD_H

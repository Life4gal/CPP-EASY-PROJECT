#ifndef QT_TETRIS_TETRIS_H
#define QT_TETRIS_TETRIS_H

#include "Tile.h"

#include <QPair>
#include <QVector>

namespace Core
{

struct Tetris
{
    //每个图形都是四块的
    QVector<Tile*> position;

    //旋转基点，小于0不可旋转
    int key;

    Tetris() noexcept ;

    explicit Tetris(int key,
            int pos0_row, int pos0_col,
            int pos1_row, int pos1_col,
            int pos2_row, int pos2_col,
            int pos3_row, int pos3_col) noexcept ;

    ~Tetris();

    Tetris& operator=(const Tetris& other);
    bool operator==(const Tetris& rhs);

    void init();

    // 纵向移动
    void moveVertically(int step) noexcept ;
    // 横向移动
    void moveHorizontally(int step) noexcept ;

    // 旋转90度
    void rotate(int min_row, int max_row, int min_col, int max_col) noexcept ;

    // 图形出现的默认位置是按照宽度为10来算的，如果宽度不对应该相应改变
    void validatePosition(int offset) noexcept ;

    //获取到XY的最大最小值
    [[nodiscard]] QPair<QPair<int, int>, QPair<int, int>> getRowColMinMax() const noexcept ;
};

}

#endif //QT_TETRIS_TETRIS_H

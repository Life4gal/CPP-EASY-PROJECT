#ifndef QT_TETRIS_LABELTILE_H
#define QT_TETRIS_LABELTILE_H

#include <QLabel>
#include <QGraphicsDropShadowEffect>
#include <QVariant>

#include "Core/Tile.h"

namespace GUI
{

using cTile = Core::Tile;

class LabelTile : public QLabel
{
    Q_OBJECT
public:
    // 必须一个砖块对应一个标签，没有砖块的标签没有意义
    explicit LabelTile(cTile* tile) noexcept ;
    // 绘制标签
    void draw() noexcept ;

private:
    // 属于自己的砖块
    cTile* tile;

signals:
public slots:
};

}

#endif //QT_TETRIS_LABELTILE_H

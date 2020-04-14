#ifndef GUI_TILE_H
#define GUI_TILE_H

#include <QLabel>
#include <QGraphicsDropShadowEffect>
#include <QVariant>

#include "Core/Tile.h"

namespace GUI
{

using cTile = Core::Tile;

//为每一个砖块设置一个标签用于显示砖块的内容
class LabelTile : public QLabel
{
    Q_OBJECT
public:
    //必须一个砖块对应一个标签，没有砖块的标签没有意义
    explicit LabelTile(cTile* tile);
    //绘制标签
    void draw();

private:
    //属于自己的砖块
    cTile* tile;

signals:
public slots:
};

}

#endif //GUI_TILE_H

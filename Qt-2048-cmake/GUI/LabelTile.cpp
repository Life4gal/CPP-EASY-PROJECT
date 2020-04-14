#include "LabelTile.h"

using namespace GUI;

LabelTile::LabelTile(cTile* _tile) : tile(_tile)
{
    setAlignment(Qt::AlignCenter);
    setAttribute(Qt::WA_StyledBackground, true);
    setProperty("class", "LabelTile");
}

void LabelTile::draw()
{
    if(tile)
    {
        setText(QString::number(tile->getValue()));
        switch (tile->getValue()) {
            case 2:
            {
                setStyleSheet(".LabelTile { background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; }");
                break;
            }
            case 4:
            {
                setStyleSheet(".LabelTile { background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; }");
                break;
            }
            case 8:
            {
                setStyleSheet(".LabelTile { background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
                break;
            }
            case 16:
            {
                setStyleSheet(".LabelTile { background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
                break;
            }
            case 32:
            {
                setStyleSheet(".LabelTile { background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
                break;
            }
            case 64:
            {
                setStyleSheet(".LabelTile { background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
                break;
            }
            case 128:
            {
                setStyleSheet(".LabelTile { background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
                break;
            }
            case 256:
            {
                auto* dse = new QGraphicsDropShadowEffect();
                dse->setColor(Qt::yellow);
                dse->setBlurRadius(20);
                dse->setOffset(-1);
                setGraphicsEffect(dse);
                setStyleSheet(".LabelTile { background: rgb(237,204,97); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
                break;
            }
            case 512:
            {
                auto* dse = new QGraphicsDropShadowEffect();
                dse->setColor(Qt::yellow);
                dse->setBlurRadius(30);
                dse->setOffset(-1);
                setGraphicsEffect(dse);
                setStyleSheet(".LabelTile { background: rgb(237,204,97); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
                break;
            }
            case 1024:
            {
                auto* dse = new QGraphicsDropShadowEffect();
                dse->setColor(Qt::yellow);
                dse->setBlurRadius(40);
                dse->setOffset(-1);
                setGraphicsEffect(dse);
                setStyleSheet(".LabelTile { background: rgb(237,204,97); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
                break;
            }
            case 2048:
            {
                auto* dse = new QGraphicsDropShadowEffect();
                dse->setColor(Qt::yellow);
                dse->setBlurRadius(50);
                dse->setOffset(-1);
                setGraphicsEffect(dse);
                setStyleSheet(".LabelTile { background: rgb(237,204,97); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
                break;
            }
            default:
            {
                setStyleSheet(".LabelTile { background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; }");
                break;
            }
        }
    }
    else    //这个位置不存在砖块
    {
        setText("");
        setStyleSheet(".LabelTile { background: rgb(204,192,179); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; }");
    }
}

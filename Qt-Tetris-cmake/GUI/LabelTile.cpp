#include "LabelTile.h"

using namespace GUI;

LabelTile::LabelTile(cTile* _tile) noexcept
        : tile(_tile)
{
    setAlignment(Qt::AlignCenter);
    setAttribute(Qt::WA_StyledBackground, true);
    setProperty("class", "LabelTile");
}

void LabelTile::draw() noexcept
{
    if(tile != nullptr)
    {
        // 0~HEIGHT
        // 一般是[0, 19]
        switch(tile->row)
        {
            case 0:
            case 1:
                setStyleSheet(".LabelTile { background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 1px; font: 15pt; }");
                break;
            case 2:
            case 3:
                setStyleSheet(".LabelTile { background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 1px; font: 15pt; }");
                break;
            case 4:
            case 5:
                setStyleSheet(".LabelTile { background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 1px; font: 15pt; }");
                break;
            case 6:
            case 7:
                setStyleSheet(".LabelTile { background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 1px; font: 15pt; }");
                break;
            case 8:
            case 9:
                setStyleSheet(".LabelTile { background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 1px; font: 15pt; }");
                break;
            case 10:
            case 11:
                setStyleSheet(".LabelTile { background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 1px; font: 15pt; }");
                break;
            case 12:
            case 13:
                setStyleSheet(".LabelTile { background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 1px; font: 15pt; }");
                break;
            case 14:
            case 15:
            {
                setStyleSheet(".LabelTile { background: rgb(237,204,97); color: rgb(255,255,255); font: bold; border-radius: 1px; font: 15pt; }");
                break;
            }
            case 16:
            case 17:
            {
                setStyleSheet(".LabelTile { background: rgb(238,205,98); color: rgb(255,255,255); font: bold; border-radius: 1px; font: 15pt; }");
                break;
            }
            case 18:
            case 19:
            {
                setStyleSheet(".LabelTile { background: rgb(239,206,99); color: rgb(255,255,255); font: bold; border-radius: 1px; font: 15pt; }");
                break;
            }
            default:
                setStyleSheet(".LabelTile { background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 1px; font: 15pt; }");
                break;
        }
    }
    else
    {
        setStyleSheet(".LabelTile { background: rgb(204,192,179); color: rgb(119,110,101); font: bold; border-radius: 1px; font: 15pt; }");
    }
}

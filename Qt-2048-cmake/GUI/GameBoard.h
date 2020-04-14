#ifndef GUI_GAMEBOARD_H
#define GUI_GAMEBOARD_H

#include <QVector>
#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QKeyEvent>
#include <QString>
#include <QVariant>

#include "Core/Game.h"
#include "Core/Board.h"
#include "Core/Tile.h"
#include "Core/Observer.h"

#include "ResetButton.h"
#include "LabelTile.h"
#include "GameOverWindow.h"

namespace GUI
{

using cGame = Core::Game;

//游戏面板属于观测者，每一次管理者逻辑进行了行为，观测者都要对应的给出回应
class GameBoard : public QWidget, public Core::Observer
{
    Q_OBJECT
public:
    //默认构造一个4阶游戏场所
    explicit GameBoard(QWidget* parent = nullptr, int dimension = 4);
    ~GameBoard() override;

    void notify() override;

private:
    //游戏管理者，观测者同时管理游戏管理者，又隶属于管理者，要对管理者的行为进行反馈
    cGame* game;
    //相当于一个二维数组，和游戏管理者储存数据的数组对应，用于显示数据之上的标签
    QVector<QVector<LabelTile*>> guiBoard;
    //主布局
    QVBoxLayout* mainLayout;
    //边界布局
    QGridLayout* boardLayout;
    //分数的标签
    QLabel* score;
    //游戏结束的窗口，除非游戏结束，不然处于隐藏状态
    GameOverWindow gameOverWindow;

    //绘制面板
    void drawBoard();

protected:
    void keyPressEvent(QKeyEvent* event) override;

signals:
public slots:
    //重设游戏
    void resetGame();
};

}

#endif //GUI_GAMEBOARD_H

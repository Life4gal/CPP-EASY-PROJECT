#ifndef QT_TETRIS_GAMEBOARD_H
#define QT_TETRIS_GAMEBOARD_H

#include <QVector>
#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QKeyEvent>
#include <QString>
#include <QVariant>
#include <QTimer>

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

// 下坠延迟，单位毫秒
constexpr const int DELAY = 600;

//游戏面板属于观测者，每一次管理者逻辑进行了行为，观测者都要对应的给出回应
class GameBoard : public QWidget, public Core::Observer
{
    Q_OBJECT
public:
    explicit GameBoard(QWidget* parent = nullptr, int width = 10, int height = 20);

    ~GameBoard() override;

    void notify() override;

private:
    cGame* game;
    int width;
    int height;
    QVector<QVector<LabelTile*>> guiBoard;
    // 主布局
    QVBoxLayout* mainLayout;
    // 边界布局
    QGridLayout* boardLayout;
    // 分数的标签
    QLabel* score;
    // 游戏结束的窗口，除非游戏结束，不然处于隐藏状态
    GameOverWindow gameOverWindow;
    // 计时器，用于下坠砖块
    QTimer timer;


    // 绘制面板
    void drawBoard();

protected:
    void keyPressEvent(QKeyEvent* event) override ;

signals:
public slots:
    //重设游戏
    void resetGame();
};

}

#endif //QT_TETRIS_GAMEBOARD_H

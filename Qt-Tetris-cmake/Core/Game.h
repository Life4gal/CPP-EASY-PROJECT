#ifndef QT_TETRIS_GAME_H
#define QT_TETRIS_GAME_H

#include "Subject.h"
#include "Board.h"

#include <QRandomGenerator>

namespace Core
{

class Game : public Subject
{

public:
    enum class Direction
    {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    explicit Game(int width, int height) noexcept ;
    ~Game();

    // 重新开始，清零分数，清空重设面板
    void restart() noexcept ;
    // 获取当前的面板
    [[nodiscard]] Board* getGameBoard() noexcept ;
    // 移动
    void move(const Direction& direction) noexcept ;
    // 游戏是否结束
    [[nodiscard]] bool isGameOver() noexcept ;
    // 获取分数
    [[nodiscard]] int getScore() noexcept ;

private:
    // 当前操作的图像
    Tetris tetris;

    // 旋转90度
    void rotate() noexcept ;

    // 移动一格
    void moveDown() noexcept ;
    void moveLeft() noexcept ;
    void moveRight() noexcept ;

    // 随机生成一个图形
    void randomGenerate() noexcept ;

private:
    Board* board;
    bool gameOver;
    int score;
};

static const Tetris Tetris_Line{1, 0, 4, 1, 4, 2, 4, 3, 4};
static const Tetris Tetris_Rect{-1, 0, 4, 0, 5, 1, 4, 1, 5};
static const Tetris Tetris_L{1, 0, 4, 1, 4, 2, 4, 2, 5};
static const Tetris Tetris_RL{1, 0, 5, 1, 5, 2, 5, 2, 4};
static const Tetris Tetris_Z{2, 0, 3, 0, 4, 1, 4, 1, 5};
static const Tetris Tetris_RZ{2, 0, 5, 0, 4, 1, 4, 1, 3};
static const Tetris Tetris_T{2, 0, 4, 1, 3, 1, 4, 1, 5};

}

#endif //QT_TETRIS_GAME_H

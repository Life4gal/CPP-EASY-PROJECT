#ifndef CORE_GAME_H
#define CORE_GAME_H

#include "Subject.h"
#include "Board.h"

namespace Core
{

constexpr const int win_score = 2048;

class Game : public Subject
{
public:
    explicit Game(int dimension);
    ~Game();

    //重新开始，清零分数，清空重设面板
    void restart();
    //游戏是否结束
    [[nodiscard]] bool isGameOver() const;
    //获得当前的游戏面板
    [[nodiscard]] Board* getGameBoard() const;
    //进行移动
    void move(Board::Direction direction);
    //是否胜利
    [[nodiscard]] bool isWon() const;
    //获取到分数
    [[nodiscard]] int getScore() const;

private:
    //管理一个游戏面板
    Board* board;
    //游戏结果
    bool gameOver;
    //游戏分数
    int score;
};

}

#endif //CORE_GAME_H

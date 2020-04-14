#ifndef CORE_BOARD_H
#define CORE_BOARD_H

#include "Subject.h"
#include "Tile.h"

#include <QVector>
#include <QString>
#include <QPair>

namespace Core
{

class Tile;

class Board : public Core::Subject
{
public:
    //可以移动的方向
    enum class Direction
    {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    //一个正方形面板上有多少行列(一般来说是4)
    explicit Board(int dimension);
    Board(const Board& other);
    ~Board();

    void reset();
    //获得目标位置的砖块
    [[nodiscard]] Tile* getTile(int x, int y) const;
    //获得当前面版上的行列数量
    [[nodiscard]] int getDimension() const;
    //进行移动
    void move(Direction direction);
    //面板是否满了(不能再加入新的砖块了)
    [[nodiscard]] bool isFull() const;
    //这次移动获取的分数
    [[nodiscard]] int getPointsScoredLastRound() const;
    //这次移动是否造成砖块升级(合并)
    [[nodiscard]] bool isTileCollisionLastRound() const;
    //是否还能继续移动
    [[nodiscard]] bool canMove() const;

private:
    //相当于一个二维数组，储存着每行每列的砖块
    QVector<QVector<Tile*>> board;
    //当前面板的行列数量
    int dimension;
    //这次移动获取的分数
    int pointScoredLastRound;
    //这次移动是否造成升级(合并)
    bool tileCollisionLastRound;

    //初始化出一个新的空面板
    void init();
    //获得一个随机的空的位置
    QPair<int, int> getFreePosition();
    //面板经过上一步是否改变
    bool isChanged(Board& other) const;

    //当前位置在面板的合法范围内
    bool isInBounds(int x, int y);
    //水平移动
    void moveHorizontally(int x, int y, Direction direction);
    //垂直移动
    void moveVertically(int x, int y, Direction direction);
    //处理碰撞结果
    void handleCollision(int x, int y);

    //准备下次移动
    void prepareForNextMove();
};

}

#endif //CORE_BOARD_H

#ifndef CORE_TILE_H
#define CORE_TILE_H

namespace Core
{

constexpr const int multiplier = 2;

class Tile
{
public:
    //默认初始构造，值设置为2
    Tile();
    Tile(const Tile& other);
    explicit Tile(int val);

    [[nodiscard]] int getValue() const;
    //升级(合并两个砖块)，一般来说是消除一个砖块，另一个砖块翻倍
    void upgrade();
    void setUpgradedThisMove(bool upgraded);
    [[nodiscard]] bool isUpgradedThisMove() const;

private:
    int value;
    //这一步是否升级(合并两个砖块)
    bool upgradedThisMove;
};

}

#endif //CORE_TILE_H

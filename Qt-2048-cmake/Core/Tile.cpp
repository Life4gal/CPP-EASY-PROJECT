#include "Tile.h"

using namespace Core;

Tile::Tile()
{
    value = 2;
    upgradedThisMove = false;
}

Tile::Tile(const Tile& other)
{
    this->value = other.value;
    this->upgradedThisMove = other.upgradedThisMove;
}

Tile::Tile(int _value)
{
    value = _value;
    upgradedThisMove = false;
}

int Tile::getValue() const
{
    return value;
}

void Tile::upgrade()
{
    value *= multiplier;
}

void Tile::setUpgradedThisMove(bool upgraded)
{
    this->upgradedThisMove = upgraded;
}

bool Tile::isUpgradedThisMove() const
{
    return this->upgradedThisMove;
}

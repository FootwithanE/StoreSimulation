#include "Coin.h"

Coin::Coin() :
   Item(), type(""), grade(0) {};

Coin::Coin(int year, std::string type, int grade) :
   Item(year, ""), type(type), grade(grade) {};

std::string Coin::toString() const
{
   return Item::toString() + " " + type;
}
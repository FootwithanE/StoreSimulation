#include "Coin.h"

Coin::Coin() :
   Item(), type(""), grade(0) {};

Coin::Coin(int year, std::string type, int grade) :
   Item(year, ""), type(type), grade(grade) {};

bool Coin::operator == (const Comparable& obj) const
{
   const Coin& c = static_cast<const Coin &>(obj);
   return (grade == c.grade && type == c.type && year == c.year);
}

bool Coin::operator != (const Comparable& obj) const
{
   const Coin& c = static_cast<const Coin&>(obj);
   return !(grade == c.grade && type == c.type && year == c.year);
}

bool Coin::operator < (const Comparable& obj) const
{
   const Coin& c = static_cast<const Coin&>(obj);
   return std::tie(type, year, grade) < std::tie(c.type, c.year, c.grade);
}

bool Coin::operator > (const Comparable& obj) const
{
   const Coin& c = static_cast<const Coin&>(obj);
   return std::tie(type, year, grade) > std::tie(c.type, c.year, c.grade);;
}

std::string Coin::toString() const
{
   return Item::toString() + std::to_string(grade) + " " + type;
}

Coin* Coin::create()
{
   return new Coin();
}
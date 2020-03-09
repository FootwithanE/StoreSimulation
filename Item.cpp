#include "Item.h"


Item::Item() : year(0), grade("") {};

Item::Item(int year, std::string grade) :
   year(year), grade(grade) {};

Item& Item::operator = (const Comparable& obj)
{
   const Item& i = static_cast<const Item&>(obj);
   grade = i.grade;
   year = i.year;
   return *this;
}

bool Item::operator == (const Comparable& obj) const
{
   const Item& i = static_cast<const Item&>(obj);
   return (grade == i.grade && year == i.year);
}

bool Item::operator != (const Comparable& obj) const
{
   const Item& i = static_cast<const Item&>(obj);
   return !(grade == i.grade && year == i.year);
}

bool Item::operator < (const Comparable& obj) const
{
   const Item& i = static_cast<const Item&>(obj);
   return std::tie(year, grade) < std::tie(i.year, i.grade);
}

bool Item::operator > (const Comparable& obj) const
{
   const Item& i = static_cast<const Item&>(obj);
   return std::tie(year, grade) > std::tie(i.year, i.grade);
}

std::string Item::toString() const
{
   return std::to_string(year) + " " + grade;
}

Item* Item::create()
{
   return new Item();
}
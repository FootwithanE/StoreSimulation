#include "Item.h"


Item::Item() : year(0), grade("") {};

Item::Item(int year, std::string grade) :
   year(year), grade(grade) {};

std::string Item::toString() const
{
   return std::to_string(year) + " " + grade;
}
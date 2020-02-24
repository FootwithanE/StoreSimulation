#include "SportsCard.h"


SportsCard::SportsCard() :
   Item(), player(""), manufacturer("") {};

SportsCard::SportsCard(int year, std::string grade,
   std::string player, std::string manufacturer) :
   Item(year, grade), player(player), manufacturer(manufacturer) {};

std::string SportsCard::toString() const
{
   return Item::toString() + " " + player + " " + manufacturer;
}
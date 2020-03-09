#include "SportsCard.h"


SportsCard::SportsCard() :
   Item(), player(""), manufacturer("") {};

SportsCard::SportsCard(int year, std::string grade,
   std::string player, std::string manufacturer) :
   Item(year, grade), player(player), manufacturer(manufacturer) {};

SportsCard& SportsCard::operator = (const Comparable& obj)
{
   const SportsCard& s = static_cast<const SportsCard&>(obj);
   year = s.year;
   grade = s.grade;
   player = s.player;
   manufacturer = s.manufacturer;
   return *this;
}

bool SportsCard::operator == (const Comparable& obj) const
{
   const SportsCard& s = static_cast<const SportsCard&>(obj);
   return (player == s.player && year == s.year &&
      manufacturer == s.manufacturer && grade == s.grade);
}

bool SportsCard::operator != (const Comparable& obj) const
{
   const SportsCard& s = static_cast<const SportsCard&>(obj);
   return !(player == s.player && year == s.year &&
      manufacturer == s.manufacturer && grade == s.grade);
}

bool SportsCard::operator < (const Comparable& obj) const
{
   const SportsCard& s = static_cast<const SportsCard&>(obj);
   return std::tie(player, year, manufacturer, grade) < 
      std::tie(s.player, s.year, s.manufacturer, s.grade);
}

bool SportsCard::operator > (const Comparable& obj) const
{
   const SportsCard& s = static_cast<const SportsCard&>(obj);
   return std::tie(player, year, manufacturer, grade) >
      std::tie(s.player, s.year, s.manufacturer, s.grade);
}

std::string SportsCard::toString() const
{
   return Item::toString() + " " + player + " " + manufacturer;
}

SportsCard* SportsCard::create()
{
   return new SportsCard();
}
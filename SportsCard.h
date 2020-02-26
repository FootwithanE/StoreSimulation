#pragma once
#include "Item.h"

class SportsCard : public Item
{
protected:
   std::string player;
   std::string manufacturer;

public:
   SportsCard();
   SportsCard(int year, std::string grade, std::string player, 
         std::string manufacturer);
   std::string toString() const;
};


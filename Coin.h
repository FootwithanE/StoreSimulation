#pragma once
#include "Item.h"

class Coin : public Item
{
protected:
   std::string type;
   int grade;

public:
   Coin();
   Coin(int year, std::string type, int grade);
   std::string toString() const;

};


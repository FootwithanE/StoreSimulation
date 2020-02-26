#pragma once
#include "Item.h"
#include "Coin.h"
#include "SportsCard.h"
#include "Comic.h"

class ItemFactory
{
public:
   ItemFactory(){};

   Item* buildItem(int x)
   {
      return items[x];
   }

private:
   Item* items[3] = {new Coin(), new SportsCard(), new Comic()};

};


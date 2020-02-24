#include "Item.h"
#include "SportsCard.h"
#include "Coin.h"
#include "Comic.h"
#include <iostream>

using namespace std;

int main()
{
   Item inventory[3];

   SportsCard myCard(1990, "Good", "Nolan Ryan", "Tops");
   Coin myCoin(1901, "Penny", 5);
   Comic myComic(1960, "Excellent", "Marvel", "Spiderman");

   cout << myCard.toString() << endl;
   cout << myCoin.toString() << endl;
   cout << myComic.toString() << endl;

   /*inventory[0] = myCard;
   inventory[1] = myCoin;
   inventory[2] = myComic;

   for (int i = 0; i < 3; i++)
   {
      cout << inventory[i].toString() << endl;
   }*/

   return 0;
}
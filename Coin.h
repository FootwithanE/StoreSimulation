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

   /* Overloaded equal to operator compares two Coin objects
      Preconditions: item and obj.item are instance of Coin
      Postcondition: true if both Coin objects hold the same type,
         year, and grade; false if they do not
   */
   virtual bool operator == (const Comparable& obj) const;
   // const Coin *c = dynamic_cast(obj)
   // true if c == this player, year, manufacturer, and grade

/* Overloaded equal to operator compares two Coin objects
   Preconditions: item and obj.item are instance of Coin
   Postcondition: true if both Coin objects have a different
      type, year, or grade; false if they are the same
*/
   virtual bool operator != (const Comparable& obj) const;
   // const Coin *c = dynamic_cast(obj)
   // true if c != this player, year, manufacturer, or grade

   /* Overloaded less than operator to compare two Coin objects
      Preconditions: item and obj.item are instance of Coin
      Postcondition: true if item is less than obj.item based on type,
         year, and then grade; false if it is not
   */
   virtual bool operator < (const Comparable& obj) const;
   // const Customer *c = dynamic_cast(obj)
   // return this < c : first by type,
   // year, and then grade

/* Overloaded less than operator to compare two Coin objects
   Preconditions: item and obj.item are instance of Coin
   Postcondition: true if item is less than obj.item based on type,
         year, and then grade; false if it is not
*/
   virtual bool operator > (const Comparable& obj) const;
   // const Customer *c = dynamic_cast(obj)
   // return this > c : first by type,
   // then year, and then grade

   /* Output of Coin item through method toString
       Preconditions: none
       Postconditions: string value containing each data member
         of the Coin
   */
   virtual std::string toString() const;

};


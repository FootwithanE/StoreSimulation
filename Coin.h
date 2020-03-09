/* Coin.h
   Author: Stephen Foote
   -----------------------------------------------------------------------
   Class Coin is derived from class Item. Class Coin is meant to be used as
   collectible Item in Store Simulation. It inherits the year from class
   Item, but hides Item's grade (string) and instead uses an int.

*/

#pragma once
#include "Item.h"

class Coin : public Item
{
protected:
   std::string type;
   int grade;

public:
   /* default constructor
      Preconditions: none
      Postconditions: new Coin Item
   */
   Coin();

   /* parameterized Coin constructor
      Preconditions: none
      Postconditions: new Coin Item object with members set
         to provided parameters
   */
   Coin(int year, std::string type, int grade);

   /* default virtual destructor
      Preconditions: none
      Postconditions: none
   */
   ~Coin() {};

   Coin& operator = (const Comparable& obj);

   /* Overloaded equal to operator compares two Coin objects
      Preconditions: item and obj.item are instance of Coin
      Postcondition: true if both Coin objects hold the same type,
         year, and grade; false if they do not
   */
   virtual bool operator == (const Comparable& obj) const;

/* Overloaded equal to operator compares two Coin objects
   Preconditions: item and obj.item are instance of Coin
   Postcondition: true if both Coin objects have a different
      type, year, or grade; false if they are the same
*/
   virtual bool operator != (const Comparable& obj) const;

   /* Overloaded less than operator to compare two Coin objects
      Preconditions: item and obj.item are instance of Coin
      Postcondition: true if item is less than obj.item based on type,
         year, and then grade; false if it is not
   */
   virtual bool operator < (const Comparable& obj) const;

/* Overloaded less than operator to compare two Coin objects
   Preconditions: item and obj.item are instance of Coin
   Postcondition: true if item is less than obj.item based on type,
         year, and then grade; false if it is not
*/
   virtual bool operator > (const Comparable& obj) const;

   /* Output of Coin item through method toString
       Preconditions: none
       Postconditions: string value containing each data member
         of the Coin
   */
   virtual std::string toString() const;

   /* factory method
      Preconditions: enough memory to allocate for new object
      Postconditions: new empty Coin object
   */
   virtual Coin* create();

};


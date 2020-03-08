/* Comic.h
   Author: Stephen Foote
   -----------------------------------------------------------------------
   Class Comic is derived from class Item. Class Comic is meant to be used as
   collectible Item in Store Simulation. It inherits the year and grade from
   Item and add additional members, publisher and title.

*/

#pragma once
#include "Item.h"

class Comic : public Item
{
protected:
   std::string publisher;
   std::string title;

public:
   /* default constructor
      Preconditions: none
      Postconditions: new Comic Item
   */
   Comic();

   /* parameterized Comic constructor
      Preconditions: none
      Postconditions: new Comic Item object with members set
         to provided parameters
   */
   Comic(int year, std::string grade,
      std::string publisher, std::string title);

   /* default virtual destructor
      Preconditions: none
      Postconditions: none
   */
   ~Comic() {};

   /* Overloaded equal to operator compares two Comic objects
      Preconditions: item and obj.item are instance of Comic
      Postcondition: true if both Comic objects hold the same publisher,
         title, year, and grade; false if they do not
   */
   virtual bool operator == (const Comparable& obj) const;
   // const Comic *c = dynamic_cast(obj)
   // true if c == this publisher, title, year, and grade

/* Overloaded equal to operator compares two Comic objects
   Preconditions: item and obj.item are instance of Comic
   Postcondition: true if both Comic objects have a different
      publisher, title, year, or grade; false if they are the same
*/
   virtual bool operator != (const Comparable& obj) const;
   // const Comic *c = dynamic_cast(obj)
   // true if c != this publisher, title, year, and grade

   /* Overloaded less than operator to compare two Comic objects
      Preconditions: item and obj.item are instance of Comic
      Postcondition: true if item is less than obj.item based on publisher,
         title, year, and then grade; false if it is not
   */
   virtual bool operator < (const Comparable& obj) const;
   // const Customer *c = dynamic_cast(obj)
   // return this < c : first by publisher,
   // title, year, and grade

/* Overloaded less than operator to compare two Comic objects
   Preconditions: item and obj.item are instance of Comic
   Postcondition: true if item is less than obj.item based on publisher,
      title, year, and grade; false if it is not
*/
   virtual bool operator > (const Comparable& obj) const;
   // const Customer *c = dynamic_cast(obj)
   // return this > c : first by player name, 
   // then by year, then by manufacturer, 
   // then by grade

   /* Output of Comic item through method toString
       Preconditions: none
       Postconditions: string value containing each data member
         of the Comic
   */
   virtual std::string toString() const;

   /* factory method
      Preconditions: enough memory to allocate for new object
      Postconditions: new empty Comic object
   */
   virtual Comic* create();
      // return new Comic()
};


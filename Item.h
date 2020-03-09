/* Item.h
   Author: Stephen Foote
   -----------------------------------------------------------------------
   class Item is derived from class Comparable and is meant to be used as
   a base class for derived Items to be used in Store Simulation. As all
   derived Items have a year and grade, the only two members of Item are
   year and grade.

   Assumptions:
      -- Used only as base class

*/

#pragma once
#include "Comparable.h"
#include <string>

class Item : public Comparable
{
protected:
   int year;
   std::string grade;

public:
   /* default constructor
      Preconditions: none
      Postconditions: new Item
   */
   Item();

   /* parameterized Item constructor
      Preconditions: none
      Postconditions: new Item object with members set
         to provided parameters
   */
   Item(int year, std::string grade);

   /* default virtual destructor
      Preconditions: none
      Postconditions: none
   */
   virtual ~Item() {};

   Item& operator = (const Comparable& obj);

   /* Overloaded equal to operator compares two Item objects
     Preconditions: item and obj.item are instance of Item
     Postcondition: true if both Item objects hold the same
        year and grade; false if they do not
  */
   virtual bool operator == (const Comparable& obj) const;

/* Overloaded equal to operator compares two Item objects
   Preconditions: item and obj.item are instance of Item
   Postcondition: true if both Item objects have a different
      year or grade; false if they are the same
*/
   virtual bool operator != (const Comparable& obj) const;

   /* Overloaded less than operator to compare two Item objects
      Preconditions: item and obj.item are instance of Item
      Postcondition: true if item is less than obj.item based on
         year and then grade; false if it is not
   */
   virtual bool operator < (const Comparable& obj) const;

/* Overloaded less than operator to compare two Item objects
   Preconditions: item and obj.item are instance of Item
   Postcondition: true if item is less than obj.item based on 
      year and then grade; false if it is not
*/
   virtual bool operator > (const Comparable& obj) const;

   /* Output of Item through method toString
      Preconditions: none
      Postconditions: string value containing each data member
         of the Item
   */
   virtual std::string toString() const;

   /* factory method
      Preconditions: enough memory to allocate for new object
      Postconditions: new empty Item object
   */
   virtual Item* create();
};


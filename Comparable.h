/* Comparable.h
   Author: Stephen Foote
   -----------------------------------------------------------------------
   class Comparable encapsulates a single character as it's data member.
   Comparative operators are overloaded, which will compare Comparable objects
   based on their ASCII order.

   Assumptions:
      -- Stored char data member will be a single ASCII char
      -- Attempts to store non-ASCII char will result in data member default to '\0'
      -- >> will be used to read in and populate data member with char
*/

#pragma once
#include <iostream>

class Comparable
{

public:
   /* Default constructor for class Comparable
      Preconditions: None
      Postconditions: Single char item data member is initialized to
         default ASCII char '\0'. Non-ASCII char values result in data
         member remaining at default.
   */
   Comparable();

   /* Virtual destructor for derived Comparable classes
   */
   virtual ~Comparable();

   /* Overloaded equal to operator compares two Comparable objects
      Preconditions: item and obj.item are each a single ASCII char
      Postcondition: true if both Comparable objects hold the same ASCII
         char; false if they do not
   */
   virtual bool operator == (const Comparable& obj) const = 0;

   /* Overloaded not equal to operator compared two Comparable objects
      Preconditions: item and obj.item are each single ASCII char
      Postcondition: true if each Comparable objects holds a different ASCII
         char; false if they hold the same
   */
   virtual bool operator != (const Comparable& obj) const = 0;

   /* Overloaded less than operator to compare two Comparable objects
      Preconditions: item and obj.item are each single ASCII char
      Postcondition: true if item is less than obj.item based on ASCII
         order; false if it is not
   */
   virtual bool operator < (const Comparable& obj) const = 0;

   /* Overloaded greater than operator to compare two Comparable objects
      Preconditions: item and obj.item are each single ASCII char
      Postcondition: true if item is greater than obj.item based on ASCII
        order; false if it is not
   */
   virtual bool operator > (const Comparable& obj) const = 0;

   /* Output of Comparable item through method toString
   */
   virtual std::string toString() const = 0;

private:
   // data member for derived classes
};


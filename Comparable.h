/* Comparable.h
   Author: Stephen Foote
   -----------------------------------------------------------------------
   class Comparable is an abstract class, which requires all derived objects
   to override comparator operators. This allows derived comparable objects
   to be sorted and inserted into relevant data structures.

*/

#pragma once
#include <iostream>
#include <tuple>

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
      Preconditions: none
      Postcondition: true if both Comparable objects hold the same value; 
         false if they do not
   */
   virtual bool operator == (const Comparable& obj) const = 0;

   /* Overloaded not equal to operator compared two Comparable objects
      Preconditions: none
      Postcondition: true if each Comparable objects holds a different value;
         false if they hold the same
   */
   virtual bool operator != (const Comparable& obj) const = 0;

   /* Overloaded less than operator to compare two Comparable objects
      Preconditions: none
      Postcondition: true if item is less than obj.item based on their value's
         order; false if it is not
   */
   virtual bool operator < (const Comparable& obj) const = 0;

   /* Overloaded greater than operator to compare two Comparable objects
      Preconditions: none
      Postcondition: true if item is greater than obj.item based on their value's
         order; false if it is not
   */
   virtual bool operator > (const Comparable& obj) const = 0;

   /* Output of Comparable item through method toString
      Preconditions: none
      Postconditions: string containing representation of comparable
   */
   virtual std::string toString() const = 0;

private:
   // data member for derived classes
};


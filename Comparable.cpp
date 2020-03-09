/* Comparable.cpp
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

#include "Comparable.h"

/* Default constructor for class Comparable
   Preconditions: None
   Postconditions: Single char item data member is initialized to
      default ASCII char '\0'. Non-ASCII char values result in data
      member remaining at default.
 */
Comparable::Comparable() : item(0)
{
}

Comparable& Comparable::operator = (const Comparable& obj)
{
   item = obj.item;
   return *this;
}

/* Overloaded equal to operator compares two Comparable objects
   Preconditions: item and obj.item are each a single ASCII char
   Postcondition: true if both Comparable objects hold the same ASCII
      char; false if they do not
*/
bool Comparable::operator == (const Comparable& obj) const
{
   return this->item == obj.item;
}
/* Overloaded not equal to operator compared two Comparable objects
   Preconditions: item and obj.item are each single ASCII char
   Postcondition: true if each Comparable objects holds a different ASCII
      char; false if they hold the same
*/
bool Comparable::operator != (const Comparable& obj) const
{
   return this->item != obj.item;
}
/* Overloaded less than operator to compare two Comparable objects
   Preconditions: item and obj.item are each single ASCII char
   Postcondition: true if item is less than obj.item based on ASCII
      order; false if it is not
*/
bool Comparable::operator < (const Comparable& obj) const
{
   return this->item < obj.item;
}
/* Overloaded greater than operator to compare two Comparable objects
   Preconditions: item and obj.item are each single ASCII char
   Postcondition: true if item is greater than obj.item based on ASCII
      order; false if it is not
*/
bool Comparable::operator > (const Comparable& obj) const
{
   return this->item > obj.item;
}

std::string Comparable::toString() const
{
   return std::to_string(item);
}

/* Overloaded ostream operator
   Preconditions: None
   Postcondition: Returns ostream object containing the single char data
      member of Comparable object
*/
std::ostream& operator << (std::ostream& os, const Comparable& obj)
{
   os << obj.item;
   return os;
}
/* Overloaded istream operator
   Preconditions: istream object is a single ASCII char
   Postcondition: obj.item will now contain the single ASCII char
*/
std::istream& operator >> (std::istream& is, Comparable& obj)
{
   is >> obj.item;
   return is;
}
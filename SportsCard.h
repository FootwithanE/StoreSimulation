#pragma once
#include "Item.h"

class SportsCard : public Item
{
protected:
   std::string player;
   std::string manufacturer;

public:
   SportsCard();
   SportsCard(int year, std::string grade, std::string player, 
         std::string manufacturer);
   std::string toString() const;

   /* Overloaded equal to operator compares two SportsCard objects
      Preconditions: item and obj.item are instance of SportsCard
      Postcondition: true if both SportsCard objects hold the same player,
         year, manufacturer, and grade; false if they do not
   */
   virtual bool operator == (const Comparable& obj) const;
      // const SportsCard *c = dynamic_cast(obj)
      // true if c == this player, year, manufacturer, and grade

   /* Overloaded equal to operator compares two SportsCard objects
      Preconditions: item and obj.item are instance of SportsCard
      Postcondition: true if both SportsCard objects have a different
         player, year, manufacturer, or grade; false if they are the same
   */
   virtual bool operator == (const Comparable& obj) const;
   // const SportsCard *c = dynamic_cast(obj)
   // true if c != this player, year, manufacturer, or grade

   /* Overloaded less than operator to compare two Sportscard objects
      Preconditions: item and obj.item are instance of SportsCard
      Postcondition: true if item is less than obj.item based on alphabetical
         order by player name, then by int year, then by manufacturer
         string, then by grade string; false if it is not
   */
   virtual bool operator < (const Comparable& obj) const;
      // const Customer *c = dynamic_cast(obj)
      // return this < c : first by player name, 
      // then by year, then by manufacturer, 
      // then by grade

   /* Overloaded less than operator to compare two Sportscard objects
      Preconditions: item and obj.item are instance of SportsCard
      Postcondition: true if item is less than obj.item based on alphabetical
         order by player name, then by int year, then by manufacturer
         string, then by grade string; false if it is not
   */
   virtual bool operator > (const Comparable& obj) const;
   // const Customer *c = dynamic_cast(obj)
   // return this > c : first by player name, 
   // then by year, then by manufacturer, 
   // then by grade

   /* Output of Sportscard item through method toString
       Preconditions: none
       Postconditions: string value containing each data member
         of the Sportscard
   */
   virtual std::string toString() const;
};


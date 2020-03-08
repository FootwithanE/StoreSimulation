#include "Comic.h"

Comic::Comic() : Item::Item(), publisher(""), title("") {};

Comic::Comic(int year, std::string grade,
   std::string publisher, std::string title) :
   Item(year, grade), publisher(publisher), title(title) {};

bool Comic::operator == (const Comparable& obj) const
{
   const Comic& c = static_cast<const Comic&>(obj);
   return (year == c.year && grade == c.grade &&
      publisher == c.publisher && title == c.title);
}

bool Comic::operator != (const Comparable& obj) const
{
   const Comic& c = static_cast<const Comic&>(obj);
   return !(year == c.year && grade == c.grade &&
      publisher == c.publisher && title == c.title);
}

bool Comic::operator < (const Comparable& obj) const
{
   const Comic& c = static_cast<const Comic&>(obj);
   return std::tie(publisher, title, year, grade) < 
         std::tie(c.publisher, c.title, c.year, c.grade);
}

bool Comic::operator > (const Comparable& obj) const
{
   const Comic& c = static_cast<const Comic&>(obj);
   return std::tie(publisher, title, year, grade) >
      std::tie(c.publisher, c.title, c.year, c.grade);
}

std::string Comic::toString() const
{
   return Item::toString() + " " + publisher + " " + title;
}

Comic* Comic::create()
{
   return new Comic();
}
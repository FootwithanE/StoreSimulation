#include "Comic.h"

Comic::Comic() : Item::Item(), publisher(""), title("") {};

Comic::Comic(int year, std::string grade,
   std::string publisher, std::string title) :
   Item(year, grade), publisher(publisher), title(title) {};

std::string Comic::toString() const
{
   return Item::toString() + " " + publisher + " " + title;
}
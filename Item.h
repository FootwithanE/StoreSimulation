#pragma once
#include <string>

class Item
{
protected:
   int year;
   std::string grade;

public:
   Item();
   Item(int year, std::string grade);
   virtual std::string toString() const;
};


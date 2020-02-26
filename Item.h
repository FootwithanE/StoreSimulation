#pragma once
#include "Comparable.h"
#include <string>

class Item : public Comparable
{
protected:
   int year;
   std::string grade;

public:
   Item();
   Item(int year, std::string grade);
   virtual ~Item();
   virtual std::string toString() const;
};


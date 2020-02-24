#pragma once
#include "Item.h"

class Comic : public Item
{
protected:
   std::string publisher;
   std::string title;

public:
   Comic();
   Comic(int year, std::string grade,
      std::string publisher, std::string title);
   std::string toString() const;

};


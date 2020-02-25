#pragma once
#include <string>
#include "TransactionList.h"


class Customer
{
private:
   int id;
   std::string name;
   TransactionList* transactions;
public:
   Customer();
   void display();
};


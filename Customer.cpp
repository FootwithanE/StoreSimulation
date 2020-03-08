#include "Customer.h"

Customer::Customer() : id(-1), name(""), transactions() {};

Customer::Customer(int id, std::string name) : 
   id(id), name(name), transactions() {};

bool Customer::operator == (const Comparable& obj) const
{
   const Customer& s = static_cast<const Customer&>(obj);
   return name == s.name && id == s.id;
}

bool Customer::operator != (const Comparable& obj) const
{
   const Customer& s = static_cast<const Customer&>(obj);
   return !(name == s.name && id == s.id);
}

bool Customer::operator < (const Comparable& obj) const
{
   const Customer& s = static_cast<const Customer&>(obj);
   return name < s.name;
}

bool Customer::operator > (const Comparable& obj) const
{
   const Customer& s = static_cast<const Customer&>(obj);
   return name > s.name;
}

std::string Customer::toString() const
{
   return "ALL TRANSACTIONS";
}
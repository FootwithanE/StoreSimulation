#include "Customer.h"

Customer::Customer() : id(-1), name(""), transactions() {};

Customer::Customer(int id, std::string name) : 
   id(id), name(name), transactions() {};

Customer& Customer::operator = (const Comparable& obj)
{
   const Customer& s = static_cast<const Customer&>(obj);
   id = s.id;
   name = s.name;
   transactions = s.transactions;
   return *this;
}

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
   std::stringstream os;

   os << name;
   for (int i = 0; i < transactions.size(); i++)
      os << "\n" << transactions.at(i);

   return os.str();
}

void Customer::addTransaction(std::string item, int count, TransType type)
{
   this->transactions.push_back(Transaction(item, count, type));
}
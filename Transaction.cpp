#include "Transaction.h"

Transaction::Transaction() : itemDescription(""), count(0), trans() {};

Transaction::Transaction(std::string item, int count, TransType type) :
   itemDescription(item), count(count), trans(type) {};

std::ostream& operator << (std::ostream& os, const Transaction& obj)
{
   os << obj.trans << "\t" << obj.count << "\t" << obj.itemDescription << std::endl;
   return os;
}
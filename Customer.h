/* Customer.h
   Definition of Customer class
   Author: Stephen Foote
   ----------------------------------------------------
   Customer class represents a single store customer.
   Customer inherits from Comparable in order to be used
   within a BST. Each customer will hold data members for
   their unique customer ID, name, and a TransactionList
   which will hold all their transactions history.

*/
#pragma once
#include <string>
#include "TransactionList.h"
#include "Comparable.h"


class Customer : public Comparable
{
private:
   int id;
   std::string name;
   TransactionList* transactions;

public:
   Customer();

   // Perform deep destruction
   virtual ~Customer();

   void display();

   /* Overloaded equal to operator compares two Customer objects
       Preconditions: item and obj.item are each a string
       Postcondition: true if both Comparable objects hold the same string;
         false if they do not
    */
   virtual bool operator == (const Comparable& obj) const;
      // const Customer *c = dynamic_cast(obj)
      // return this->name == c.name

   /* Overloaded not equal to operator compared two Customer objects
      Preconditions: item and obj.item are each a string
      Postcondition: true if each Comparable objects holds a different string;
         false if they hold the same
   */
   virtual bool operator != (const Comparable& obj) const;
      // const Customer *c = dynamic_cast(obj)
      // return this->name != c.name

   /* Overloaded less than operator to compare two Customer objects
      Preconditions: item and obj.item are each a string
      Postcondition: true if item is less than obj.item based on alphabetical
         string order; false if it is not
   */
   virtual bool operator < (const Comparable& obj) const;
      // const Customer *c = dynamic_cast(obj)
      // return this->name < c.name

   /* Overloaded greater than operator to compare two Customer objects
      Preconditions: item and obj.item are each a string
      Postcondition: true if item is greater than obj.item based on alphabetical
         string order; false if it is not
   */
   virtual bool operator > (const Comparable& obj) const;
      // const Customer *c = dynamic_cast(obj)
      // return this->name > c.name

    /* Output of Comparable item through method toString
       Preconditions: none
       Postconditions: string value containing customer ID, name
         and entire transaction history
   */
   virtual std::string toString() const;

};


/* Transaction.h
   Definition of Transaction
   Author: Stephen Foote
   ----------------------------------------------------
   Transaction is a class to hold the relevant information
   of a transaction that took place within the store. 
   The description of the item sold or bought, the number of 
   each sold or bought, and the transaction type, to describe 
   whether the transaction was a sale or a purchase.
   Items are not sorted and are instead always inserted in
   the back of the list, as they are to be displayed in FIFO manner.

*/

#pragma once
#include <string>
#include <iostream>

// enum to associate type of transaction
enum TransType
{
   Sale, Purchase
};

// Linked list methods
class Transaction
{
private:
   // string value of item (toString return)
   std::string itemDescription;
   // number of items in transaction
   int count;
   // sale or purchase by customer
   TransType trans;

public:
   /* Default constrcutor for Transaction
      Preconditions: none
      Postconditions: new transaction class object
   */
   Transaction();

   /* Parameterized constructor for Transaction
      Preconditions: none
      Postconditions: new transaction class object, intialized
         to the provided values
   */
   Transaction(std::string item, int count, TransType type);

   /* Default destructor
      Preconditions: none
      Postconditions: Transaction removed
   */
   ~Transaction() {};

   /* Will print relevant transaction data in easily read format
      Preconditions: none
      Postconditions: returns ostream object with transaction type,
         item count, and item description.
   */
   friend std::ostream& operator << (std::ostream& os, const Transaction& obj);
};


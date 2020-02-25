/* TransactionList.h
   Definition of TransactionList
   Author: Stephen Foote
   ----------------------------------------------------
   Transaction List is a linked list of TransactionInventoryNodes.
   Each transaction InventoryNode keeps track of a customers transaction
   with the store. The description of the item sold or bought,
   the number of each sold or bought, and the transaction type, 
   to describe whether the transaction was a sale or a purchase.
   Items are not sorted and are instead always inserted in
   front of list, so when displayed, they are in order from
   most recent transaction.

*/

#pragma once

// enum to associate type of transaction
enum TransType
{
   Sale, Purchase
};

// InventoryNode to track item, count and transaction type
struct TransactionInventoryNode
{
   // Does not keep actual item - avoid dynamic memory
   std::string itemDescription;
   int count;
   TransType transaction;
   TransactionInventoryNode* next;
};

// Linked list methods
class TransactionList
{
private:
   TransactionInventoryNode* headPtr;

public:
   TransactionList();
   friend ostream& operator << (ostream& os, const TransactionList& list);
};


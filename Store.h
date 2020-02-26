/* Store.h
   Definition of Store || Manager class for Store Simulation
   Author: Stephen Foote
   ---------------------------------------------------------
   Store is the manager class for the collectibles store
   simulation. The store class takes care of reading instructions
   from the provided files, managing the store inventories of
   Items, and customer inventories, including transaction 
   histories.

*/


#pragma once
#include <sstream>
#include "Inventory.h"
#include "Customer.h"

// number of types of items
const int NUM_ITEMS = 3;
const int MAX_CUSTOMERS = 1000;

class Store
{
private:
   // Pointer to inventory (BST) for each item type
   Inventory* inventories[NUM_ITEMS];
   // Customer list by ID
   Customer customersById[MAX_CUSTOMERS];
   // Customers by Name (BST)
   Inventory* customersByName;
   



   bool sell(int id, char itemType, std::string param);
   // call buildFactory for itemType
   //    pass arguments from string
   // return Item



public:
   // Default constructor
   Store();

   /* adds customer to customerByID and customersByName
      Creates new customer
   */
   bool addCustomer(const int id, const std::string name);

   /* Takes first three arguments of transaction and
      makes decision on transaction type, customer
      association, and item type to create for
      inventory
   */
   bool commandDecision(std::string line);
      // stringstream ss(line) -> line whole line of command
      // begin parsing by token and ','
      //    if s and customer exists call sell and pass itemType 
      //                      and remaining string from ss
      //       return true
      //    if b and customer exists call buy and pass itemType
      //       return true
      //    if d call display
      //       return true
      //    if c and customer exits call Customer display
      //       return true
      //    if H call History
      //       return true
      //    else false
      //


};


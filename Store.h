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

public:
   // Default constructor
   Store();

   /* adds customer to customerByID and customersByName
      ...will call private methods to complete this
   */
   bool addCustomer(const int id, const std::string name);

   bool sellItem(int id, )


};


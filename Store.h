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
#include "InventoryBST.h"
#include "Customer.h"
#include "HashSet.h"

// number of types of items
const int NUM_ITEMS = 3;
const int MAX_CUSTOMERS = 1000;

class Store
{
private:
   // Pointer to inventory (BST) for each item type
   // index of BST type will match hash value for consistency
   InventoryBST* inventories[NUM_ITEMS];
   // Customer list by ID
   Customer customersById[MAX_CUSTOMERS];
   // Customers by Name (BST)
   InventoryBST* customersByName;
   // Hashtable of Items
   HashSet items;

public:
   // Default constructor
   Store()
   {
      HashSet Items(NUM_ITEMS);
   };

   /* adds customer to customerByID and customersByName
      Preconditions: none
      Postconditions: new customer add to customerById and
         customersByName
   */
   bool addCustomer(const int id, const std::string name);
      // creates new customer obj
      // if customer id free (no duplicates)
      //    insert new customer obj in customerById
      //    creates new pointer to customer object
      //    inster new pointer into customersByName(BST)
      //    return true
      // else false

   /* addItem takes in item information and fills inventory of store
      Preconditions: itemInfo contains all necessary information in
         correct format
      Postconditions: items, including frequency, are added to the
         store inventory in the correct item inventory
   */
   bool addItem(const char id, const int num, std::string info);
         // uses char item identifier on HashSet items
         // returns new correct derived Item to Item*
         //       use info to complete Item data
         //       if something missing - return false
         // add into correct inventory (Inventory.insert(item))
         //       if already exists increase frequency
         // return true

   /* add item to the correct inventory
      Preconditions: itemInfo contains all necessary information in
         correct format
      Postconditions: new Item is stored in correct inventory in sorted
         order
   */
   bool buyItem(const char id, std::string itemInfo);
         // uses char item identifier on HashSet items
         // returns new correct derived Item to Item*
         // store customer id
         // remainder of information from itemInfo used
         // to populate new item
         //                   if missing return false
         // use item info to add transaction to customer by id
         // item inserted to correct inventory (returned hash
         //       integer used to locate) 
         //       if item exists - increase freq.
         //       return true

   /* remove item from inventory
      Preconditions: itemInfo contains all necessary information in
         correct format
      Postconditions: one instance of Item is removed from inventory
   */
   bool sellItem(char id, std::string itemInfo);
         // uses char item identifier on HashSet items
         // returns new correct derived Item to Item*
         // remainder of information from itemInfo used
         // to populate new item
         //                   if missing return false
         // item searched for within inventory (returned hash
         //       integer used to locate) 
         //       if item exists
         //          use item info to add transaction to customer by id
         //          decrease freq. or remove
         //          return true
         // if not - return false

   /* Takes first three arguments of transaction and
      makes decision on transaction type, customer
      association, and item type to create for
      inventory
   */
   bool commandDecision(std::string line);  //<- may create hashtable for key/command values
      // stringstream ss(line) -> line whole line of command
      // begin parsing by token and ','
      //    if s and customer exists call sellItem and pass itemType 
      //                      and remaining string from ss
      //       return true
      //    if b and customer exists call buyItem and pass itemType
      //       return true
      //    if d call display
      //       return true
      //    if c and customer exits call Customer display
      //       return true
      //    if H call History
      //       return true
      //    else false
      //

   /* displays entire inventory of store
      Preconditions: none
      Postconditions: Goes throuh each inventory, and displays every item
         stored in each container, including item frequency
   */
   void display();
      // in order traverse of each inventory

   /* prints transaction history of customer by id
      Precondtions: customer with id exists
      Postconditions: transaction history of customer printed
   */
   void displayCustomer(int id);
      // find customer by id ->toString()

   /* displays transaction history of every customer in inventory
      Precondition: none
      Postcondition: every customer in inventory is printed, with their
         entire transaction history. Done in alphabetical order.
   */
   void history();
      // traverse customersByName and call toString()
};


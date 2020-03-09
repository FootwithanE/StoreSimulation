/* main.h
   Author: Stephen Foote
   ---------------------------------------------------------
   Main handles the file input for the store simulation. It then
   passes validated information to the Store class for manipulation
   and management of data.
*/

#include "Comparable.h"
#include "Item.h"
#include "SportsCard.h"
#include "Coin.h"
#include "Comic.h"
//#include "Store.h"
#include "Customer.h"
#include "InventoryBST.h"
#include <iostream>

using namespace std;

/* intialize items reads and initialize items in store inventory
   Preconditions: file must exits and be in propper format
   Postconditions: initialized item inventory in store
*/
//void initializeItems(ifstream& file, Store& obj);
// while not eof
// pass next line into store addItem
//


/* intialize store customer inventory
   Preconditions: file must exits and be in propper format
   Postconditions: initialized store customer inventory
*/
//void initializeCustomers(ifstream& file, Store& obj);
// while not eof
// pass next line into store addCustomer
//

/* read commands from file and pass arguments to store
   Preconditions: file must exits and be in propper format
   Postconditions: complete requested commands on store
*/
//void commander(ifstream& file, Store& obj);
// while not eof
// pass next line into store commandDecision
//

int main()
{

   // Initialize store
   //Store myStore();

   //ifstream obj -> myfile
   
  // initializeItems(myfile, myStore);

   // next file
   //initializeCustomers(myfile, myStore);

   // next file
   //commander(myfile, myStore);

   Comparable* coin = new Coin(1987, "penny", 0);
   Comparable* coin2 = new Coin(1986, "penny", 0);

   Customer* me = new Customer(001, "Stephen");
   Customer* me2 = new Customer(002, "Megan");
   me->addTransaction(coin->toString(), 2, Purchase);
   me->addTransaction(coin2->toString(), 1, Sale);

   cout << me->toString() << endl;

   InventoryBST myInventory;
   InventoryBST myInventory2;
   myInventory.insert(coin);
   myInventory.insert(coin2);

   InventoryBST myCustomers;
   myCustomers.insert(me);
   myCustomers.insert(me2);

   cout << myInventory << endl;
   myInventory2 = myInventory;
   cout << myInventory2 << endl;
   cout << myCustomers << endl;



   return 0;
}
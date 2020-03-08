/* main.h
   Author: Stephen Foote
   ---------------------------------------------------------
   Main handles the file input for the store simulation. It then
   passes validated information to the Store class for manipulation
   and management of data.
*/

#include "Item.h"
#include "SportsCard.h"
#include "Coin.h"
#include "Comic.h"
#include "Store.h"
#include <iostream>

using namespace std;

/* intialize items reads and initialize items in store inventory
   Preconditions: file must exits and be in propper format
   Postconditions: initialized item inventory in store
*/
void initializeItems(ifstream& file, Store& obj);
// while not eof
// pass next line into store addItem
//


/* intialize store customer inventory
   Preconditions: file must exits and be in propper format
   Postconditions: initialized store customer inventory
*/
void initializeCustomers(ifstream& file, Store& obj);
// while not eof
// pass next line into store addCustomer
//

/* read commands from file and pass arguments to store
   Preconditions: file must exits and be in propper format
   Postconditions: complete requested commands on store
*/
void commander(ifstream& file, Store& obj);
// while not eof
// pass next line into store commandDecision
//

int main()
{

   // Initialize store
   Store myStore();

   //ifstream obj -> myfile
   
   initializeItems(myfile, myStore);

   // next file
   initializeCustomers(myfile, myStore);

   // next file
   commander(myfile, myStore);



   return 0;
}
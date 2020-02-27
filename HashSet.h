/* HashSet.h
   Author: Stephen Foote
   --------------------------------------------------------
   class HashSet uses a hashing algorithm to create a hash
   value for characters. They are stored with a value pair,
   which is a pointer to a dummy Comprable object, stored
   within a Table. This key, value pair is meant to act as 
   a factory for Comprable objects.

   Assumptions:
         -- Comprable object must have create() method
         -- must number of unique derived items beforehand


*/

#pragma once
#include "Comparable.h"


class HashSet
{
private:
   // Bucket holds key and Comarable dummy object
   struct Bucket
   {
      char key;
      Comparable* value;
      // value will be dummy Item (comparable) 
      // with create() method
   };
   // size of hash table
   int tableSize;
   Bucket table[]; 

public:
   /* default constructor
      Preconditions: none
      Postconditions: Hashset of size 0
   */
   HashSet();

   /* Parameterized constructor
      Preconditions: none
      Postconditions: Hashset with Table initialized to provided
         int parameter
   */
   HashSet(int valueNum) : tableSize(valueNum)
   {
      table[tableSize];
   }

   /* HashSet destructor
      Preconditions: none
      Postconditions: ensure no dummy objects left in Table
   */
   ~HashSet();

   /* hash function works on char key
      Preconditions: none
      Postconditions: int hash value based on char key and
         tableSize
   */
   int hash(char key)
   {
      return key % tableSize;
   }

   /* insert a key and value into the hash table
      Preconditions: no duplicate values and the number of keys
         must be < tableSize
      Postconditions: Bucket with key, value pair inserted into
         hash table
   */
   void insertValue(char key, Comparable* value);
      // find hash value for key 
      // store in table at index[key] as
      // bucket with key and value as dummy Comparable
   
};


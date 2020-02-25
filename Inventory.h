/* Inventory.h
   Definition of Inventory for Item objects
   Author: Stephen Foote
   -----------------------------------------------------------------------
   A Binary Search Tree that utilizes a InventoryNode that holds a pointer to a class
   Item object and contains the frequency of that item. This
   means there are no duplicated InventoryNodes.

   Assumptions:
      -- Will be used in conjunction with class Item
      -- InventoryNode pointers default to nullptr and frequency to 1
      -- tree root pointer to InventoryNode is initialized to nullptr
*/

#pragma once
#include "Item.h"

/* struct InventoryNode is used to store a pointer to Item object, along with it's
   frequency within the tree and a pointer to each it's left and right children

   Assumptions:
      -- Used in conjunction with class Item
      -- Frequency will maintain accuracy if InventoryNode is used in Inventory only
*/
struct InventoryNode
{
   Item* item; // pointer to Item class object
   int frequency; // Frequency of current Item item within tree
   InventoryNode* left; // pointer to left child
   InventoryNode* right; // pointer to right child
   // Default initialized members
   InventoryNode() : item(nullptr), frequency(1), left(nullptr), right(nullptr) {};
};

class Inventory
{

public:
   /* Default constructor for class Inventory
      Preconditions: none
      Postconditions: Inventory object with root pointer to InventoryNode
         initialized to nullptr
   */
   Inventory();
   /* Copy constructor for class Inventory
      Preconditions: none
      Postconditions: deep copy of tree, so that no memory locations
         are shared between this and tree
   */
   Inventory(const Inventory& tree);
   /* Overloaded assignment operator
      Precondition: none
      Postcondition: A deep copy of tree is made and is assigned to the other Inventory.
         this == tree returns true.
   */
   Inventory& operator = (const Inventory& tree);
   /* Destructor for Inventory objects
      Preconditions: none
      Postconditions: Inventory object destroyed and all allocated memory
         freed.
   */
   ~Inventory();
   /* makeEmpty clears the Inventory of all InventoryNodes
      Preconditions: none
      Postconditions: All InventoryNodes in the Inventory are destroyed and allocated
         memory is freed. Inventory object is not destroyed and root is  set
         back to nullptr.
   */
   void makeEmpty();
   /* insert adds a Item object to the Inventory
      Preconditions: pointer to Item is used as argument. Pointer should not
         be nullptr. False will be returned if Item object is nullptr.
      Postconditions: If instance of Item object is already held in a InventoryNode
         within the tree, that InventoryNode has an increase in frequency and false is returned.
         Otherwise, a new InventoryNode, now containing the new Item object is inserted into
         the tree, with a frequency of 1 and true is returned. The Inventory maintains
         the properties of a binary search tree.
   */
   bool insert(Item* obj);
   /* Overloaded ostream operator to print Inventory
      Preconditions: none
      Postconditions: Return of ostream object containing inorder frequency table of Inventory.
         Each line will contain in order ASCII character and frequency of occurrence. Empty
         Inventory will print nothing.
   */
   friend std::ostream& operator << (std::ostream& os, const Inventory& obj);
   /* remove searches the tree for a matching Item and removes it from the tree
      Preconditions: none
      Postconditions: returns false if no InventoryNode with matching Item key can be located.
         Returns true, and removes one occurrance or the InventoryNode for the last occurrance, if
         Item key located within tree. Binary search tree properties are maintained.
   */
   bool remove(const Item& key);
   /* retrieve a pointer to a Item object, if it exists in the tree
      Preconditions: Item pointer to receive return value
      Postconditions: If a InventoryNode with a matching Item object exists, a pointer
         to that Item is returned. If it cannot be located within the tree, a
         nullptr is returned.
   */
   const Item* retrieve(const Item& key);
   /* height of InventoryNode containing provided Item object
      Preconditions: none
      Postconditions: If InventoryNode containing Item object is located, the height is
         returned as int. -1 is returned if Item object cannot be located within
         Inventory.
   */
   int height(const Item& obj) const;
   /* Overloaded equal to operator
      Precondition: two Inventory objects to compare
      Postcondition: returns true if both Inventory objects are identical. Each InventoryNode of
         each tree must hold the same Item and frequency as the matching InventoryNode in the
         other Tree; otherwise returns false.
   */
   bool operator == (const Inventory& obj) const;
   /* Overloaded not equal to operator
      Precondition: two Inventory objects to compare
      Postconditions: returns false if both Inventory objects are identical. Each InventoryNode of
         each tree must hold the same Item and frequency as the matching InventoryNode in the
         other Tree; otherwise returns true.
   */
   bool operator != (const Inventory& obj) const;

private:
   InventoryNode* root;
   /* private recursive helper method deepCopy is called by copy constructor and
      overloaded assignment operator
      Preconditions: valid arguments passed to copy constructor or assignment operator
      Postconditions: Returns deep copy InventoryNode pointers. Item and frequency is copied,
         but no memory is shared between InventoryNodes.
   */
   InventoryNode* deepCopy(InventoryNode* cur);
   /* private recursive helper method destroyTree is called by destructor and makeEmpty
      Preconditions: none
      Postconditions: removal of all InventoryNodes and freeing of all memory associated with Inventory
   */
   void destroyTree(InventoryNode*& root);
   /* private recursive helper method insert is called by public insert method
      Preconditions: called if root != nullptr && obj != nullptr
      Postconditions: If instance of Item object is already held in a InventoryNode
         within the tree, that InventoryNode has an increase in frequency and false is returned.
         Otherwise, a new InventoryNode, now containing the new Item object is inserted into
         the tree, with a frequency of 1 and true is returned. The Inventory maintains
         the properties of a binary search tree.
   */
   bool insert(InventoryNode* cur, Item* obj);
   /* private recursive helper method inOrder is called by overloaded ostream operator
      Preconditions: none
      Postconditions: ostream object passed by reference will containg Inventory information
         in order in a frequency table.
   */
   void inOrder(std::ostream& os, InventoryNode* cur) const;
   /* private recursive helper method remove is called by public method remove
      Preconditions: valid arguments passed to remove public
      Postconditions: Returns true if the Item key could be located in the Inventory.
         If there is more than 1 occurrance, the frequency is reduced by one, otherwise, the
         InventoryNode is removed from the Inventory. Returns false if the key cannot be located. Maintains
         properties of binary search tree.
   */
   bool remove(InventoryNode*& root, const Item& key);
   /* private recursive helper method deleteInventoryNode is called by private method remove
      Preconditions: the Item key was located and frequency == 1
      Postconditions: InventoryNode containing Item key is removed from Inventory. All
         allocated memory associated with that InventoryNode is freed. Inventory maintains the
         properties of a binary search tree.
   */
   void deleteInventoryNode(InventoryNode*& root);
   /* private recursive helper method finMinValueRight is called by deleteInventoryNode
      Precondition: Item key was located on InventoryNode with two children != nullptr
      Postcondition: pointer to copy of InventoryNode containing Item key is returned
            in order to access multiple data members of InventoryNode structs.
   */
   InventoryNode* findMinValueRight(InventoryNode*& root);
   /* private recursive helper method retrieve is called by public method retrieve
      Preconditions: none
      Postconditions: if Item object located matching provided key, pointer to that
         Item is returned. If it cannot be located, nullptr is returned.
   */
   const Item* retrieve(InventoryNode* root, const Item& key);
   /* private recursive helper method compareTrees is called by overloaded equal to and
      not equal to operators
      Preconditions: is called if root and obj.root are not the same InventoryNode
      Postconditions: returns true if Inventory objects are identical. All InventoryNodes are in
         the same position and contain the same Item and frequency; otherwise returns
         false.
   */
   bool compareTrees(InventoryNode* root, const InventoryNode* other) const;
   /* private recursive helper method getHeight is called by height method
      Preconditions: is called if InventoryNode returned from finInventoryNodeForHeight != nullptr and
         not a leaf of the tree
      Postconditions: returns height of located InventoryNode as int
   */
   int getHeight(InventoryNode* root) const;
   /* private recursive helper method findInventoryNodeForHeight is called by height method
      Preconditions: Item obj != nullptr
      Postconditions: searches for and returns pointer to InventoryNode where Item
         from argument passed to height is located. If Item is not located
         returns nullptr.
   */
   InventoryNode* findInventoryNodeForHeight(InventoryNode* root, const Item& obj) const;
};

/* Inventory.cpp
   Definition of Binary Search Tree for Item objects
   Author: Stephen Foote
   -----------------------------------------------------------------------
   A Binary Search Tree that utilizes a InventoryNode that holds a pointer to a class
   Item object and contains the frequency of that Item item. This
   means there are no duplicated InventoryNodes.

   Assumptions:
      -- Will be used in conjunction with class Item
      -- InventoryNode pointers default to nullptr and frequency to 1
      -- InventoryNode is only initialized when Item object is being inserted
            into the tree
      -- tree root pointer to InventoryNode is initialized to nullptr
*/

#include "Inventory.h"
#include <iostream>

/* Default constructor for class Inventory
   Preconditions: none
   Postconditions: Inventory object with root pointer to InventoryNode
         initialized to nullptr
*/
Inventory::Inventory() : root(nullptr)
{
}
/* Copy constructor for class Inventory
   Preconditions: none
   Postconditions: deep copy of tree, so that no memory locations
         are shared between this and tree
*/
Inventory::Inventory(const Inventory& tree) : root(nullptr)
{
   root = deepCopy(tree.root);
}
/* Overloaded assignment operator
   Precondition: none
   Postcondition: A deep copy of tree is made and is assigned to the other Inventory.
         this == tree returns true.
*/
Inventory& Inventory::operator = (const Inventory& tree)
{
   // Ensure not the same object
   if (this != &tree)
      this->root = deepCopy(tree.root);

   return *this;
}
/* private recursive helper method deepCopy is called by copy constructor and
   overloaded assignment operator
   Preconditions: valid arguments passed to copy constructor or assignment operator
   Postconditions: Returns deep copy InventoryNode pointer. Item and frequency is copied,
        but no memory is shared between InventoryNodes.
*/
InventoryNode* Inventory::deepCopy(InventoryNode* cur)
{
   if (cur == nullptr)
      return nullptr;

   InventoryNode* newInventoryNode = new InventoryNode;
   newInventoryNode->item = new Item; // instantiate Item
   *newInventoryNode->item = *cur->item; // assign through de-refernce
   newInventoryNode->frequency = cur->frequency; // transfer frequency
   // call recursive to reach all InventoryNodes
   newInventoryNode->left = deepCopy(cur->left);
   newInventoryNode->right = deepCopy(cur->right);

   return newInventoryNode;
}
/* Destructor for Inventory objects
   Preconditions: none
   Postconditions: Inventory object destroyed and all allocated memory
         freed.
*/
Inventory::~Inventory()
{
   destroyTree(root);
}
/* makeEmpty clears the Inventory of all InventoryNodes
   Preconditions: none
   Postconditions: All InventoryNodes in the Inventory are destroyed and allocated
         memory is freed. Inventory object is not destroyed and root is  set
         back to nullptr.
*/
void Inventory::makeEmpty()
{
   destroyTree(root);
}
/* private recursive helper method destroyTree is called by destructor and makeEmpty
   Preconditions: none
   Postconditions: removal of all InventoryNodes and freeing of all memory associated with Inventory
*/
void Inventory::destroyTree(InventoryNode*& root)
{
   if (root != nullptr)
   {
      destroyTree(root->left);
      destroyTree(root->right);
      delete root->item; // Delete Item
      root->item = nullptr;
      delete root; // Delete InventoryNode
      root = nullptr;
   }
}
/* insert adds a Item object to the Inventory
   Preconditions: pointer to Item is used as argument.
   Postconditions: If instance of Item object is already held in a InventoryNode
         within the tree, that InventoryNode has an increase in frequency and false is returned.
         If Item == nullptr then false is returned.
         Otherwise, a new InventoryNode, now containing the new Item object is inserted into
         the tree, with a frequency of 1 and true is returned. The Inventory maintains
         the properties of a binary search tree.
*/
bool Inventory::insert(Item* obj)
{
   // nullptr obj not stored
   if (obj == nullptr)
   {
      return false;
   }
   // if Inventory empty
   else if (root == nullptr)
   {
      root = new InventoryNode;
      root->item = obj;
      return true;
   }
   // recursive call required
   else
      return insert(root, obj);
}
/* private recursive helper method insert is called by public insert method
   Preconditions: called if root != nullptr && obj != nullptr
   Postconditions: If instance of Item object is already held in a InventoryNode
         within the tree, that InventoryNode has an increase in frequency and false is returned.
         Otherwise, a new InventoryNode, now containing the new Item object is inserted into
         the tree, with a frequency of 1 and true is returned. The Inventory maintains
         the properties of a binary search tree.
*/
bool Inventory::insert(InventoryNode* cur, Item* obj)
{
   // Occurrance > 0
   if (*obj == *cur->item)
   {
      cur->frequency += 1;
      return false;
   }
   // move through left subtree
   else if (*obj < *cur->item)
   {
      // add new InventoryNode to left
      if (cur->left == nullptr)
      {
         cur->left = new InventoryNode;
         cur->left->item = obj;
         return true;
      }
      else
         // recursive call left
         return insert(cur->left, obj);
   }
   // move through right subtree as above
   else
   {
      if (cur->right == nullptr)
      {
         cur->right = new InventoryNode;
         cur->right->item = obj;
         return true;
      }
      else
         return insert(cur->right, obj);
   }
}
/* Overloaded ostream operator to print Inventory
   Preconditions: none
   Postconditions: Return of ostream object containing inorder frequency table of Inventory.
         Each line will contain in order ASCII character and frequency of occurrence. Empty
         Inventory will print nothing.
*/
std::ostream& operator << (std::ostream& os, const Inventory& obj)
{
   // call for inorder traversal
   obj.inOrder(os, obj.root);
   return os;
}
/* private recursive helper method inOrder is called by overloaded ostream operator
   Preconditions: none
   Postconditions: ostream object passed by reference will containg Inventory information
         in order in a frequency table.
*/
void Inventory::inOrder(std::ostream& os, InventoryNode* cur) const
{
   if (cur == nullptr)
      return;
   inOrder(os, cur->left);
   // pull char and frequency from each InventoryNode
   os << *cur->item << " " << cur->frequency << std::endl;
   inOrder(os, cur->right);
}
/* remove searches the tree for a matching Item and removes it from the tree
   Preconditions: none
   Postconditions: returns false if no InventoryNode with matching Item key can be located.
         Returns true, and removes one occurrance or the InventoryNode for the last occurrance, if
         Item key located within tree. Binary search tree properties are maintained.
*/
bool Inventory::remove(const Item& key)
{
   // recursive call
   return remove(root, key);
}
/* private recursive helper method remove is called by public method remove
   Preconditions: valid arguments passed to remove public
   Postconditions: Returns true if the Item key could be located in the Inventory.
         If there is more than 1 occurrance, the frequency is reduced by one, otherwise, the
         InventoryNode is removed from the Inventory. Returns false if the key cannot be located. Maintains
         properties of binary search tree.
*/
bool Inventory::remove(InventoryNode*& root, const Item& key)
{
   if (root == nullptr)
      return false;
   else if (*root->item == key)
   {
      // remove on occurrance
      if (root->frequency > 1)
      {
         root->frequency--;
      }
      // remove whole InventoryNode
      else
      {
         // call helper delete
         deleteInventoryNode(root);
      }
      return true;
   }
   // recursive call left and right
   else if (*root->item > key)
      return remove(root->left, key);
   else
      return remove(root->right, key);
}
/* private recursive helper method deleteInventoryNode is called by private method remove
   Preconditions: called if the Item key was located and frequency == 1
   Postconditions: InventoryNode containing Item key is removed from Inventory. All
         allocated memory associated with that InventoryNode is freed. Inventory maintains the
         properties of a binary search tree.
*/
void Inventory::deleteInventoryNode(InventoryNode*& root)
{
   // delete leaf
   if (root->left == nullptr && root->right == nullptr)
   {
      delete root;
      root = nullptr;
   }
   // delete InventoryNode with one child
   else if (root->left == nullptr || root->right == nullptr)
   {
      InventoryNode* temp = root;
      root = root->left == nullptr ? root->right : root->left;
      delete temp->item;
      delete temp;
   }
   // delete InventoryNode with two children
   else
   {
      // Copy InventoryNode data members into InventoryNode to delete
      InventoryNode* temp = findMinValueRight(root->right);
      root->item = temp->item;
      root->frequency = temp->frequency;
      delete temp;
   }
}
/* private recursive helper method finMinValueRight is called by deleteInventoryNode
   Precondition: called if Item key was located on InventoryNode with two children != nullptr
   Postcondition: the Item item from the minimum possible InventoryNode of the right
         sub tree of root, is located and used to copy into the found InventoryNode meeting the
         above criteria. The found InventoryNode is then deleted and the Inventory maintains
         the properties of a binary search tree.
*/
InventoryNode* Inventory::findMinValueRight(InventoryNode*& root)
{
   // no further left = min
   if (root->left == nullptr)
   {
      // copy InventoryNode data
      InventoryNode* temp = root;
      root = root->right;
      return temp;
   }
   else
      // keep looking for min value
      return findMinValueRight(root->left);
}
/* retrieve a pointer to a Item object, if it exists in the tree
   Preconditions: none
   Postconditions: returns Item pointer. If a InventoryNode with a matching Item
         object exists, a pointer to that Item is returned. If it cannot be
         located within the tree, a nullptr is returned.
*/
const Item* Inventory::retrieve(const Item& key)
{
   // recursive call
   return retrieve(root, key);
}
/* private recursive helper method retrieve is called by public method retrieve
   Preconditions: none
   Postconditions: if Item object located matching provided key, pointer to that
         Item is returned. If it cannot be located, nullptr is returned.
*/
const Item* Inventory::retrieve(InventoryNode* root, const Item& key)
{
   // cannot be found
   if (root == nullptr)
      return nullptr;
   // located
   else if (*root->item == key)
      return root->item;
   // recursive calls left and right
   else if (*root->item > key)
      return retrieve(root->left, key);
   else
      return retrieve(root->right, key);
}
/* height of InventoryNode containing provided Item object
   Preconditions: none
   Postconditions: If InventoryNode containing Item object is located, the height is
         returned as int. -1 is returned if Item object cannot be located within
         Inventory.
*/
int Inventory::height(const Item& obj) const
{
   // find and return InventoryNode with Item
   InventoryNode* cur = findInventoryNodeForHeight(root, obj);
   // could not locate
   if (cur == nullptr)
      return -1;
   // leaf InventoryNode
   if (cur->left == nullptr && cur->right == nullptr)
      return 0;
   else
      // all other InventoryNodes
      return getHeight(cur) - 1; // -1 to compensate for count from 0
}
/* private recursive helper method getHeight is called by height method
   Preconditions: is called if InventoryNode returned from finInventoryNodeForHeight != nullptr and
         not a leaf of the tree
   Postconditions: returns height of located InventoryNode as int
*/
int Inventory::getHeight(InventoryNode* root) const
{
   // stop search
   if (root == nullptr)
      return 0;
   else
   {
      // recursive search of left and right subtree
      int leftSub = getHeight(root->left);
      int rightSub = getHeight(root->right);
      // return longest path only
      if (leftSub > rightSub)
         return leftSub + 1;
      else
         return rightSub + 1;
   }
}
/* private recursive helper method findInventoryNodeForHeight is called by height method
   Preconditions: Item obj != nullptr
   Postconditions: searches for and returns pointer to InventoryNode where Item
         from argument passed to height is located. If Item is not located
         returns nullptr.
*/
InventoryNode* Inventory::findInventoryNodeForHeight(InventoryNode* root, const Item& obj) const
{
   // Cannot be found
   if (root == nullptr)
      return nullptr;
   // located
   else if (*root->item == obj)
      return root;
   // recursive search
   else if (*root->item > obj)
      return findInventoryNodeForHeight(root->left, obj);
   else
      return findInventoryNodeForHeight(root->right, obj);
}
/* private recursive helper method compareTrees is called by overloaded equal to and
      not equal to operators
   Preconditions: is called if root and obj.root are not the same InventoryNode
   Postconditions: returns true if Inventory objects are identical. All InventoryNodes are in
         the same position and contain the same Item and frequency; otherwise returns
         false.
*/
bool Inventory::compareTrees(InventoryNode* root, const InventoryNode* other) const
{
   // nothing to compare if both nullptr
   if (root == nullptr && other == nullptr)
      return true;
   if (root != nullptr && other != nullptr)
   {  // check Item and frequency and then recursive check left and right subtrees
      return *root->item == *other->item && root->frequency == other->frequency &&
         compareTrees(root->left, other->left) && compareTrees(root->right, other->right);
   }
   // if one nullptr and the other not they cannot be equal
   return false;
}
/* Overloaded equal to operator
   Precondition: two Inventory objects to compare
   Postcondition: returns true if both Inventory objects are identical. Each InventoryNode of
         each tree must hold the same Item and frequency as the matching InventoryNode in the
         other Tree; otherwise returns false.
*/
bool Inventory::operator == (const Inventory& obj) const
{
   // if -> same root then trees are equal
   if (root == obj.root)
      return true;
   else
      // call recursive method
      return compareTrees(root, obj.root);
}
/* Overloaded not equal to operator
   Precondition: two Inventory objects to compare
   Postconditions: returns false if both Inventory objects are identical. Each InventoryNode of
         each tree must hold the same Item and frequency as the matching InventoryNode in the
         other Tree; otherwise returns true.
*/
bool Inventory::operator != (const Inventory& obj) const
{
   // if -> same root then trees are equal
   if (root == obj.root)
      return false;
   else
      // negate recursive call
      return !compareTrees(root, obj.root);
}

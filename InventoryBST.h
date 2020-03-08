/* InventoryBST.h
   Definition of InventoryBST for Comparable objects
   Author: Stephen Foote
   -----------------------------------------------------------------------
   A Binary Search Tree that utilizes a InventoryNode that holds a pointer to a class
   Comparable object and contains the frequency of that Comparable. This
   means there are no duplicated InventoryNodes.

   Assumptions:
      -- Will be used in conjunction with class Comparable
      -- InventoryNode pointers default to nullptr and frequency to 1
      -- tree root pointer to InventoryNode is initialized to nullptr
*/

#pragma once
#include "Comparable.h"

/* struct InventoryNode is used to store a pointer to Comparable object, along with it's
   frequency within the tree and a pointer to each it's left and right children

   Assumptions:
      -- Used in conjunction with class Comparable
      -- Frequency will maintain accuracy if InventoryNode is used in InventoryBST only
*/
struct InventoryNode
{
   Comparable* item; // pointer to Comparable class object
   int frequency; // Frequency of current Comparable within tree - counting duplicates
   InventoryNode* left; // pointer to left child
   InventoryNode* right; // pointer to right child
   // Default initialized members
   InventoryNode() : item(nullptr), frequency(1), left(nullptr), right(nullptr) {};
};

class InventoryBST
{

public:
   /* Default constructor for class InventoryBST
      Preconditions: none
      Postconditions: InventoryBST object with root pointer to InventoryNode
         initialized to nullptr
   */
   InventoryBST();
   /* Copy constructor for class InventoryBST
      Preconditions: none
      Postconditions: deep copy of tree, so that no memory locations
         are shared between this and tree
   */
   InventoryBST(const InventoryBST& tree);
   /* Overloaded assignment operator
      Precondition: none
      Postcondition: A deep copy of tree is made and is assigned to the other InventoryBST.
         this == tree returns true.
   */
   InventoryBST& operator = (const InventoryBST& tree);
   /* Destructor for InventoryBST objects
      Preconditions: none
      Postconditions: InventoryBST object destroyed and all allocated memory
         freed.
   */
   ~InventoryBST();
   /* makeEmpty clears the InventoryBST of all InventoryNodes
      Preconditions: none
      Postconditions: All InventoryNodes in the InventoryBST are destroyed and allocated
         memory is freed. InventoryBST object is not destroyed and root is  set
         back to nullptr.
   */
   void makeEmpty();
   /* insert adds a Comparable object to the InventoryBST
      Preconditions: pointer to Comparable is used as argument. Pointer should not
         be nullptr. False will be returned if Comparable object is nullptr.
      Postconditions: If instance of Comparable object is already held in a InventoryNode
         within the tree, that InventoryNode has an increase in frequency and false is returned.
         Otherwise, a new InventoryNode, now containing the new Comparable object is inserted into
         the tree, with a frequency of 1 and true is returned. The InventoryBST maintains
         the properties of a binary search tree.
   */
   bool insert(Comparable* obj);
   /* Overloaded ostream operator to print InventoryBST
      Preconditions: none
      Postconditions: Return of ostream object containing inorder frequency table of InventoryBST.
         Each line will contain in order ASCII character and frequency of occurrence. Empty
         InventoryBST will print nothing.
   */
   friend std::ostream& operator << (std::ostream& os, const InventoryBST& obj);
   /* remove searches the tree for a matching Comparable and removes it from the tree
      Preconditions: none
      Postconditions: returns false if no InventoryNode with matching Comparable key can be located.
         Returns true, and removes one occurrance or the InventoryNode for the last occurrance, if
         Comparable key located within tree. Binary search tree properties are maintained.
   */
   bool remove(const Comparable& key);
   /* retrieve a pointer to a Comparable object, if it exists in the tree
      Preconditions: Comparable pointer to receive return value
      Postconditions: If a InventoryNode with a matching Comparable object exists, a pointer
         to that Comparable is returned. If it cannot be located within the tree, a
         nullptr is returned.
   */
   const Comparable* retrieve(const Comparable& key);
   /* height of InventoryNode containing provided Comparable object
      Preconditions: none
      Postconditions: If InventoryNode containing Comparable object is located, the height is
         returned as int. -1 is returned if Comparable object cannot be located within
         InventoryBST.
   */
   int height(const Comparable& obj) const;
   /* Overloaded equal to operator
      Precondition: two InventoryBST objects to compare
      Postcondition: returns true if both InventoryBST objects are identical. Each InventoryNode of
         each tree must hold the same Comparable and frequency as the matching InventoryNode in the
         other Tree; otherwise returns false.
   */
   bool operator == (const InventoryBST& obj) const;
   /* Overloaded not equal to operator
      Precondition: two InventoryBST objects to compare
      Postconditions: returns false if both InventoryBST objects are identical. Each InventoryNode of
         each tree must hold the same Comparable and frequency as the matching InventoryNode in the
         other Tree; otherwise returns true.
   */
   bool operator != (const InventoryBST& obj) const;

private:
   InventoryNode* root;

   /* private recursive helper method deepCopy is called by copy constructor and
      overloaded assignment operator
      Preconditions: valid arguments passed to copy constructor or assignment operator
      Postconditions: Returns deep copy InventoryNode pointers. Comparable and frequency is copied,
         but no memory is shared between InventoryNodes.
   */
   InventoryNode* deepCopy(InventoryNode* cur);

   /* private recursive helper method destroyTree is called by destructor and makeEmpty
      Preconditions: none
      Postconditions: removal of all InventoryNodes and freeing of all memory associated with InventoryBST
   */
   void destroyTree(InventoryNode*& root);

   /* private recursive helper method insert is called by public insert method
      Preconditions: called if root != nullptr && obj != nullptr
      Postconditions: If instance of Comparable object is already held in a InventoryNode
         within the tree, that InventoryNode has an increase in frequency and false is returned.
         Otherwise, a new InventoryNode, now containing the new Comparable object is inserted into
         the tree, with a frequency of 1 and true is returned. The InventoryBST maintains
         the properties of a binary search tree.
   */
   bool insert(InventoryNode* cur, Comparable* obj);

   /* private recursive helper method inOrder is called by overloaded ostream operator
      Preconditions: none
      Postconditions: ostream object passed by reference will containg InventoryBST information
         in order in a frequency table.
   */
   void inOrder(std::ostream& os, InventoryNode* cur) const;

   /* private recursive helper method remove is called by public method remove
      Preconditions: valid arguments passed to remove public
      Postconditions: Returns true if the Comparable key could be located in the InventoryBST.
         If there is more than 1 occurrance, the frequency is reduced by one, otherwise, the
         InventoryNode is removed from the InventoryBST. Returns false if the key cannot be located. Maintains
         properties of binary search tree.
   */
   bool remove(InventoryNode*& root, const Comparable& key);

   /* private recursive helper method deleteInventoryNode is called by private method remove
      Preconditions: the Comparable key was located and frequency == 1
      Postconditions: InventoryNode containing Comparable key is removed from InventoryBST. All
         allocated memory associated with that InventoryNode is freed. InventoryBST maintains the
         properties of a binary search tree.
   */
   void deleteInventoryNode(InventoryNode*& root);

   /* private recursive helper method finMinValueRight is called by deleteInventoryNode
      Precondition: Comparable key was located on InventoryNode with two children != nullptr
      Postcondition: pointer to copy of InventoryNode containing Comparable key is returned
            in order to access multiple data members of InventoryNode structs.
   */
   InventoryNode* findMinValueRight(InventoryNode*& root);

   /* private recursive helper method retrieve is called by public method retrieve
      Preconditions: none
      Postconditions: if Comparable object located matching provided key, pointer to that
         Comparable is returned. If it cannot be located, nullptr is returned.
   */
   const Comparable* retrieve(InventoryNode* root, const Comparable& key);

   /* private recursive helper method compareTrees is called by overloaded equal to and
      not equal to operators
      Preconditions: is called if root and obj.root are not the same InventoryNode
      Postconditions: returns true if InventoryBST objects are identical. All InventoryNodes are in
         the same position and contain the same Comparable and frequency; otherwise returns
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
      Preconditions: Comparable obj != nullptr
      Postconditions: searches for and returns pointer to InventoryNode where Comparable
         from argument passed to height is located. If Comparable is not located
         returns nullptr.
   */
   InventoryNode* findInventoryNodeForHeight(InventoryNode* root, const Comparable& obj) const;
};

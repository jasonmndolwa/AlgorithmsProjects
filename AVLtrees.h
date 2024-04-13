// Including necessary standard libraries
#include <iostream>
#include <iomanip> // For setw function
#include <queue> // For level-order traversal
#include <stack> // For various traversals

using namespace std;

// Declaration of a placeholder type for data in the binary tree
typedef char elemType; // "placeholder" for data type

// Binary tree class
class binaryTree {
protected:
    // Structure for tree nodes
    struct TreeNode {
        elemType data;    // Store data
        TreeNode* left;   // Link to left subtree
        TreeNode* right;  // Link to right subtree
    };
    TreeNode* root; // Pointer to the root of the tree

private:
    // Private member functions for tree traversals and other operations
    void in_order(TreeNode*) const; // In-order traversal
    void pre_order(TreeNode*) const; // Pre-order traversal
    void post_order(TreeNode*) const; // Post-order traversal
    void level_order(TreeNode*) const; // Level-order traversal
    int size(TreeNode*) const; // Calculate the size of the tree
    int height(TreeNode*) const; // Calculate the height of the tree
    void display(TreeNode*, int) const; // Display the tree in a formatted manner

public:
    // Constructor to initialize the root to nullptr
    binaryTree() { root = nullptr; };
    // Public member functions for accessing tree properties and performing traversals
    int treeNodeCount() const { return size(root); }; // Return the number of nodes in the tree
    int height() const; // Return the height of the tree
    void display() const; // Display the tree
    void post_orderTraversal() const; // Perform post-order traversal
    void in_order_Traversal() const; // Perform in-order traversal
    void pre_order_Traversal() const; // Perform pre-order traversal
    void level_order_Traversal() const; // Perform level-order traversal
};

// Derived class representing a binary search tree (BST)
class BST : public binaryTree {

private:
    // Private member function to search for a key in the tree
    bool search(const elemType, TreeNode*) const;

public:
    // Public member function to search for a key in the tree
    bool searchItem(const elemType key) { return search(key, root); };
    // Public member function to insert a new item into the tree
    void insertItem(const elemType); // Insert an item into the tree
};

// Derived class representing a balanced binary search tree (AVL tree)
class balancedBST : public BST {
private:
    // Private member functions for AVL tree operations
    TreeNode* insert(TreeNode*, elemType&); // Insert a new node into the AVL tree
    TreeNode* leftRotate(TreeNode*); // Perform a left rotation on the tree
    TreeNode* rightRotate(TreeNode*); // Perform a right rotation on the tree
    TreeNode* balance(TreeNode*); // Balance the AVL tree

    void balanceFactors(TreeNode*) const; // Display AVL balance factors
    int getBalance(TreeNode*) const; // Get the balance factor of a node
    int getHeight(TreeNode*) const; // Get the height of a node

public:
    // Public member functions for AVL tree operations
    void insertItem(const elemType&); // Insert an item into the AVL tree
    void balanceFactors() const; // Display AVL balance factors
};
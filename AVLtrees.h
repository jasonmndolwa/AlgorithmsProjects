#include <iostream>
#include <iomanip>
#include <stack>

typedef char elemType; // "placeholder" for data type

// Binary tree class
class binaryTree {
protected:
    // Structure for tree nodes
    struct TreeNode {
        elemType data;    // store data
        TreeNode* left;   // link to left subtree
        TreeNode* right;  // link to right subtree
    };
    TreeNode* root;

private:
    void in_order(TreeNode*) const;
    void pre_order(TreeNode*) const;
    void post_order(TreeNode*) const;
    void level_order(TreeNode*) const;
    int size(TreeNode*) const;
    int height(TreeNode*) const;
    void display(TreeNode*, int) const;

public:
    binaryTree() { root = NULL; };
    int treeNodeCount() const { return size(root); };
    int height() const;
    void display() const;
    void post_orderTraversal() const;
    void in_order_Traversal() const;
    void pre_order_Traversal() const;
    void level_order_Traversal() const;
};

class BST : public binaryTree {

private:
    bool search(const elemType, TreeNode*) const;

public:
    bool searchItem(const elemType key) { return search(key, root); };
    void insertItem(const elemType);
};

class balancedBST : public BST {
private:
    TreeNode* insert(TreeNode*, const elemType&);
    TreeNode* leftRotate(TreeNode*);
    TreeNode* rightRotate(TreeNode*);
    TreeNode* balance(TreeNode*);
    int getBalance(TreeNode*) const;

public:
    void insertItem(const elemType&);
    void balanceFactors() const;
};

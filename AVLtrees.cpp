#include "AVLTrees.h"

int binaryTree::height() const {
    return height(root);
}

void binaryTree::display() const {
    display(root, 0);
}

void binaryTree::post_orderTraversal() const {
    return post_order(root);
}

void binaryTree::in_order_Traversal() const {
    in_order(root);
}

void binaryTree::pre_order_Traversal() const {
    pre_order(root);
}

void binaryTree::level_order_Traversal() const {
    level_order(root);
}

void binaryTree::in_order(binaryTree::TreeNode *) const {
}

void binaryTree::pre_order(binaryTree::TreeNode *) const {

}

void binaryTree::post_order(binaryTree::TreeNode *) const {

}

void binaryTree::level_order(binaryTree::TreeNode *) const {

}

int binaryTree::size(binaryTree::TreeNode *) const {
    return 0;
}

int binaryTree::height(binaryTree::TreeNode *) const {
    return 0;
}

void binaryTree::display(binaryTree::TreeNode *, int) const {

}

bool BST::search(const elemType key, TreeNode* node) const {
    if (node == nullptr) return false;
    if (key == node->data) return true;
    if (key < node->data) return search(key, node->left);
    return search(key, node->right);
}

void BST::insertItem(const elemType key) {
    TreeNode* newNode = new TreeNode;
    newNode->data = key;
    newNode->left = nullptr;
    newNode->right = nullptr;

    if (root == nullptr) {
        root = newNode;
    } else {
        TreeNode* current = root;
        TreeNode* parent = nullptr;
        while (current != nullptr) {
            parent = current;
            if (key < current->data) {
                current = current->left;
            } else if (key > current->data) {
                current = current->right;
            } else {
                delete newNode; // Duplicate keys are not allowed
                return;
            }
        }

        if (key < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }
}

binaryTree::TreeNode *balancedBST::insert(binaryTree::TreeNode *, const elemType &) {
    return nullptr;
}

binaryTree::TreeNode *balancedBST::leftRotate(binaryTree::TreeNode *) {
    return nullptr;
}

binaryTree::TreeNode *balancedBST::rightRotate(binaryTree::TreeNode *) {
    return nullptr;
}

binaryTree::TreeNode *balancedBST::balance(binaryTree::TreeNode *) {
    return nullptr;
}

int balancedBST::getBalance(binaryTree::TreeNode *) const {
    return 0;
}

void balancedBST::insertItem(const elemType &) {

}

void balancedBST::balanceFactors() const {

}

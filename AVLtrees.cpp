#include "AVLTrees.h"

// Get the height of the binary tree
int binaryTree::height() const {
    return height(root);  // Call the private height function with the root node
}
// Display the binary tree
void binaryTree::display() const {
    display(root, 0);  // Call the private display function with the root node and initial indentation
}
// Perform post-order traversal of the binary tree
void binaryTree::post_orderTraversal() const {
    return post_order(root);  // Call the private post_order function with the root node
}
// Perform in-order traversal of the binary tree
void binaryTree::in_order_Traversal() const {
    in_order(root);  // Call the private in_order function with the root node
}
// Perform pre-order traversal of the binary tree
void binaryTree::pre_order_Traversal() const {
    pre_order(root);  // Call the private pre_order function with the root node
}
// Perform level-order traversal of the binary tree
void binaryTree::level_order_Traversal() const {
    level_order(root);  // Call the private level_order function with the root node
}

// Perform an in-order traversal of the binary tree
void binaryTree::in_order(binaryTree::TreeNode *) const {
    stack<TreeNode *> stack1;
    TreeNode *curr = root;

    while (curr != nullptr or !stack1.empty()) {
        while (curr != nullptr) {
            stack1.push(curr);
            curr = curr->left;
        }
        curr = stack1.top();
        stack1.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}
// Perform a pre-order traversal of the binary tree
void binaryTree::pre_order(binaryTree::TreeNode *) const {
    if(root == nullptr){
        return;
    }
    stack<TreeNode*> stack2;
    stack2.push(root);

    while(!stack2.empty()){
        TreeNode* curr = stack2.top();
        stack2.pop();
        cout << curr->data << " " << endl;

        if(curr->right != nullptr){
            stack2.push(curr->right);
        }
        if(curr->left != nullptr){
            stack2.push(curr->left);
        }
    }
}
// Perform a post-order traversal of the binary tree
void binaryTree::post_order(binaryTree::TreeNode *) const {
    if(root == nullptr){
        return;
    }
    stack<TreeNode*> stack3;
    stack<TreeNode*> stack4;
    stack3.push(root);

    while(!stack3.empty()){
        TreeNode* curr = stack3.top();
        stack3.pop();
        stack4.push(curr);

        if(curr->left != nullptr){
            stack3.push(curr->left);
        }
        if(curr->right != nullptr){
            stack3.push(curr->right);
        }
    }

    while(!stack4.empty()){
        cout << stack4.top()->data << " " << endl;
        stack4.pop();
    }
}
// Perform a level-order traversal of the binary tree
void binaryTree::level_order(binaryTree::TreeNode *) const {
    if(root == nullptr){
        return;
    }
    stack<TreeNode*> stack5;
    stack5.push(root);

    while(!stack5.empty()){
        TreeNode* curr = stack5.top();
        stack5.pop();
        cout << curr->data << " ";

        if(curr->right != nullptr){
            stack5.push(curr->right);
        }
        if(curr->left != nullptr){
            stack5.push(curr->left);
        }
    }
}

// Calculate the size of the binary tree
int binaryTree::size(binaryTree::TreeNode *) const {
    if(root == nullptr){
        return 0;
    }

    stack<TreeNode*> stack6;
    stack6.push(root);
    int count = 0;

    while(!stack6.empty()){
        TreeNode* curr = stack6.top();
        stack6.pop();
        count++;

        if(curr->left != nullptr){
            stack6.push(curr->left);
        }
        if(curr->right != nullptr){
            stack6.push(curr->right);
        }
    }
    return count;
}
// Calculate the height of the binary tree
int binaryTree::height(TreeNode* root) const {
    if (root == nullptr) {
        return -1;
    }

    stack<TreeNode*> stack7;
    stack7.push(root);
    int height = 0; // Initialize the height to 0 since we are counting levels from the root.

    while (!stack7.empty()) {
        int size = stack7.size();

        // Traverse all nodes at the current level
        for (int i = 0; i < size; i++) {
            TreeNode* curr = stack7.top();
            stack7.pop();

            // Add children of the current node to the stack for the next level
            if (curr->left != nullptr) {
                stack7.push(curr->left);
            }
            if (curr->right != nullptr) {
                stack7.push(curr->right);
            }
        }
        // Increment height after traversing a level
        height++;
    }
    // Subtract 1 from height because we counted the root level as 0
    return height - 1;
}
// Display the binary tree
void binaryTree::display(binaryTree::TreeNode *node, int indent) const {
    if (node == nullptr) {
        return;
    }

    // Increase indentation for each level
    indent += 4;

    // Display right subtree first (for proper alignment)
    display(node->right, indent);

    // Print current node with proper indentation
    cout << setw(indent) << ' ' << node->data << endl;

    // Display left subtree
    display(node->left, indent);
}

// Insert an element into the binary search tree
void BST::insertItem(const elemType key) {
    if(!isalpha(key)){
        throw invalid_argument("Only char type data can be inserted.");
    }

    if(searchItem(key)){
        cout << "Already exists in the tree." << endl;
        return;
    }
    // Create a new TreeNode with the given key
    TreeNode *newNode;
    newNode = new TreeNode;
    newNode->data = key;
    newNode->left = nullptr;
    newNode->right = nullptr;

    // If the tree is empty, set the new node as the root
    if (root == nullptr) {
        root = newNode;
        return;
    }

    // Traverse the tree to find the proper location to insert the new node
    TreeNode* current = root;
    TreeNode* parent = nullptr;
    while (current != nullptr) {
        parent = current;
        if (key < current->data) {
            current = current->left;
        } else if (key > current->data) {
            current = current->right;
        } else {
            // Key already exists in the tree, delete the new node and return
            delete newNode;
            return;
        }
    }

    if (parent != nullptr) {
        // Insert the new node at the appropriate position
        if (key < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    } else {
        root = newNode;
    }

}
// Search for a key in the binary search tree starting from a given node.
bool BST::search(const elemType key, binaryTree::TreeNode *node) const {
    // Base case: if the node is null, the key is not found
    if (node == nullptr) {
        return false;
    }

    // If the current node's data matches the key, return true
    if (node->data == key) {
        return true;
    }

    // Recursively search in the left subtree if the key is less than the current node's data
    if (key < node->data) {
        return search(key, node->left);
    }

    // Recursively search in the right subtree if the key is greater than the current node's data
    return search(key, node->right);
}

// Insert an element into the AVL tree
binaryTree::TreeNode *balancedBST::insert(binaryTree::TreeNode *node, elemType &key) {
    // Create a new TreeNode and initialize its members
    TreeNode *newNode;
    newNode = new TreeNode;
    newNode->data = key;
    newNode->left = nullptr;
    newNode->right = nullptr;

    // If the tree is empty, the new node becomes the root
    if(root == nullptr){
        return newNode;
    }

    // Traverse the tree to find the appropriate position to insert the new node
    TreeNode* current = root;
    while (current != nullptr) {
        if (key < current->data) {
            if (current->left == nullptr) {
                current->left = newNode;
                return root; // Return the root of the modified tree
            } else {
                current = current->left;
            }
        } else if (key > current->data) {
            if (current->right == nullptr) {
                current->right = newNode;
                return root; // Return the root of the modified tree
            } else {
                current = current->right;
            }
        } else {
            // If the key already exists in the tree, do not insert duplicates
            delete newNode;
            return root; // Return the root of the unchanged tree
        }
    }
    // Return the root of the modified tree
    return root;
}
// Perform a left rotation on the AVL tree
binaryTree::TreeNode *balancedBST::leftRotate(binaryTree::TreeNode *x) {
    TreeNode* y = x->right;
    TreeNode* subtree = y->left;

    y->left = x;
    x->right = subtree;

    return y;
}
// Perform a right rotation on the AVL tree
binaryTree::TreeNode *balancedBST::rightRotate(binaryTree::TreeNode *y) {
    TreeNode* x = y->left;
    TreeNode* subtree = x->right;

    x->right = y;
    y->left  = subtree;

    return x;
}
// Balance the AVL tree
binaryTree::TreeNode *balancedBST::balance(binaryTree::TreeNode *node) {
    // Calculate the height of the left and right subtrees
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    // Calculate the balance factor of the node
    int balanceFactor = leftHeight - rightHeight;
    // If the balance factor indicates the subtree is unbalanced
    if (balanceFactor > 1) {
        // Left-heavy subtree
        if (getHeight(node->left->left) >= getHeight(node->left->right)) {
            // Left-left case: Perform a right rotation
            return rightRotate(node);
        } else {
            // Left-right case: Perform a left rotation on the left child followed by a right rotation on the node
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    } else if (balanceFactor < -1) {
        // Right-heavy subtree
        if (getHeight(node->right->right) >= getHeight(node->right->left)) {
            // Right-right case: Perform a left rotation
            return leftRotate(node);
        } else {
            //a right rotation on the right child followed by a left rotation on the node
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }
    // If the subtree is already balanced, return the node unchanged
    return node;
}

// Insert an item into the balanced BST
void balancedBST::insertItem(const elemType &key) {
    root = insert(root, const_cast<elemType &>(key));//Got an error when I had only key, one of the actions clion suggested was to do this.
    root = balance(root);
}
// Display balance factors of all nodes in the tree
void balancedBST::balanceFactors() const {
    balanceFactors(root);
    cout << endl;
}

// Helper function to get the balance factor of a node
int balancedBST::getBalance(binaryTree::TreeNode *node) const {
    return getHeight(node->left) - getHeight(node->right);
}
// Helper function to get the height of a node in the balanced binary search tree
int balancedBST::getHeight(binaryTree::TreeNode *node) const {
    // If the node is null (the tree is empty/we've reached a leaf node)
    if (node == nullptr) {
        return -1;
    }

    // Recursively calculate the height of the left subtree
    int leftHeight = getHeight(node->left);

    // Recursively calculate the height of the right subtree
    int rightHeight = getHeight(node->right);

    // Return the height of the current node by adding 1 to the maximum height of its left and right subtrees
    return 1 + max(leftHeight, rightHeight);
}
// Helper function to display balance factors recursively
void balancedBST::balanceFactors(binaryTree::TreeNode *node) const {
    if (node == nullptr) {
        return;
    }

    // Calculate the balance factor for the current node
    int balanceFactor = getBalance(node);

    // Display the balance factor along with the node data
    cout << node->data << ":" << balanceFactor << " ";

    // Recursively calculate balance factors for left and right subtrees
    balanceFactors(node->left);
    balanceFactors(node->right);
}

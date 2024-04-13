#include <iostream>
#include "AVLTrees.h" // Include your header file here

int main() {
    // Create a balancedBST object
    balancedBST tree;

    // Insert elements into the tree
    tree.insertItem('G');
    tree.insertItem('C');
    tree.insertItem('R');
    tree.insertItem('A');
    tree.insertItem('E');
    tree.insertItem('M');
    tree.insertItem('D');
    tree.insertItem('F');

    // Search for an element in the tree
    char key = 'Z';
    if (tree.searchItem(key)) {
        cout << "Element " << key << " found in the tree." << endl;
    } else {
        cout << "Element " << key << " not found in the tree." << endl;
    }

    // Perform tree balancing
    tree.balanceFactors();

    // Display the tree after balancing
    cout << "Tree after balancing:" << endl;
    tree.display();
    cout << endl;

    return 0;
}
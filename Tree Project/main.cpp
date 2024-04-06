#include "BST.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std; 

int main() {
    BST bst;

    srand(static_cast<unsigned int>(time(nullptr)));

    // Add a set of random numbers to the BST
    int total = 100;
    vector<int> addedNumbers;
    for (int i = 0; i < total; ++i) {
        int randomNumber = rand() % 1000;
        addedNumbers.push_back(randomNumber);
        bst.Add(randomNumber);
    }
    // Test inorder traversal
    bst.InorderTraverse();

    // Test maximum function
    cout << "\nMaximum value in BST: " << bst.Maximum() << endl;

    // Now find and remove a random number that we know was added to the tree
    int randomIndex = rand() % total;
    int numberToFindAndRemove = addedNumbers[randomIndex];

    cout << "\nAttempting to find and remove: " << numberToFindAndRemove << endl;
    Node* foundNode = bst.Find(numberToFindAndRemove);
    if (foundNode != nullptr) {
        cout << "\nFound node with data: " << foundNode->data << endl;
        if (bst.Remove(numberToFindAndRemove)) {
            cout << "\nNumber " << numberToFindAndRemove << " was removed." << endl;
        }
        else {
            cout << "Failed to remove number " << numberToFindAndRemove << endl;
        }
    }
    else {
        cout << "Number " << numberToFindAndRemove << " was not found in the tree." << endl;
    }

    // Test removing non-existing node
    if (!bst.Remove(1000)) {
        cout << "\nNode with data 1000 not found to remove.\n" << endl;
    }

    // New inorder traversal after removal
    bst.InorderTraverse();

    return 0;
}

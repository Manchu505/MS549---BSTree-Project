#include "BST.h"
#include <iostream>
#include <stdexcept>

using namespace std; 

BST::BST() : root(nullptr) {}

BST::~BST() {
    DeleteTree(root);
}

Node* BST::AddRecursive(Node* node, int data) {
    if (!node) {
        return new Node(data);
    }
    if (data < node->data) {
        node->left = AddRecursive(node->left, data);
    }
    else if (data > node->data) {
        node->right = AddRecursive(node->right, data);
    }
    return node;
}

void BST::Add(int data) {
    root = AddRecursive(root, data);
}

Node* BST::RemoveRecursive(Node* node, int data) {
    if (!node) {
        return nullptr;
    }
    if (data < node->data) {
        node->left = RemoveRecursive(node->left, data);
    }
    else if (data > node->data) {
        node->right = RemoveRecursive(node->right, data);
    }
    else {
        node = RemoveNode(node);
    }
    return node;
}

Node* BST::RemoveNode(Node* node) {
    if (!node->left) {
        Node* temp = node->right;
        delete node;
        return temp;
    }
    else if (!node->right) {
        Node* temp = node->left;
        delete node;
        return temp;
    }

    // Node with two children: Get the inorder successor (smallest in the right subtree)
    Node* temp = FindMin(node->right);

    // Copy the inorder successor's content to this node
    node->data = temp->data;

    // Delete the inorder successor
    node->right = RemoveRecursive(node->right, temp->data);

    return node;
}

bool BST::Remove(int data) {
    if (Find(data) == nullptr) {
        return false; // Element not found
    }
    root = RemoveRecursive(root, data);
    return true;
}

int BST::Maximum() const {
    Node* maxNode = FindMax(root);
    if (maxNode == nullptr) {
        throw runtime_error("The tree is empty.");
    }
    return maxNode->data;
}

Node* BST::FindMax(Node* node) const {
    if (node == nullptr) {
        return nullptr;
    }
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}

Node* BST::FindMin(Node* node) const {
    if (node == nullptr) {
        return nullptr;
    }
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

void BST::InorderTraverse() const {
    InorderTraverseRecursive(root);
    cout << endl;
}

void BST::InorderTraverseRecursive(Node* node) const {
    if (node == nullptr) {
        return;
    }
    InorderTraverseRecursive(node->left);
    cout << node->data << " ";
    InorderTraverseRecursive(node->right);
}

void BST::DeleteTree(Node* node) {
    if (node == nullptr) {
        return;
    }
    DeleteTree(node->left);
    DeleteTree(node->right);
    delete node;
}

Node* BST::Find(int data) const {
    return FindRecursive(root, data);
}

Node* BST::FindRecursive(Node* node, int data) const {
    if (node == nullptr || node->data == data) {
        return node;
    }
    if (data < node->data) {
        return FindRecursive(node->left, data);
    }
    return FindRecursive(node->right, data);
}

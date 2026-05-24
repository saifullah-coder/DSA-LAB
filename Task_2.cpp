#include <iostream>
using namespace std;

// Node structure for binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Helper to create a new node with given value
Node* newNode(int val) {
    Node* n = new Node();
    n->data = val;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

// Inorder traversal: Left -> Root -> Right
// Visits left subtree first, then prints current node, then right subtree
void inorder(Node* root) {
    if (root == nullptr) return;  // Base case: stop if node doesn't exist
    inorder(root->left);          // Recurse into left subtree
    cout << root->data << " ";    // Print current node
    inorder(root->right);         // Recurse into right subtree
}

// Preorder traversal: Root -> Left -> Right
// Prints current node first, then recurses into left and right subtrees
void preorder(Node* root) {
    if (root == nullptr) return;  // Base case: stop if node doesn't exist
    cout << root->data << " ";    // Print current node first
    preorder(root->left);         // Recurse into left subtree
    preorder(root->right);        // Recurse into right subtree
}

int main() {
    // Manually construct the binary tree (same structure as Task 1)
    //         40
    //        /  \
    //      20    60
    //     / \   / \
    //    10  30 50  70

    Node* root = newNode(40);       // Root node
    root->left = newNode(20);       // Left child of root
    root->right = newNode(60);      // Right child of root
    root->left->left = newNode(10); // Left child of 20
    root->left->right = newNode(30);// Right child of 20
    root->right->left = newNode(50);// Left child of 60
    root->right->right = newNode(70);// Right child of 60

    // Display traversal results
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    return 0;
}

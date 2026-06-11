#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Insert function
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Find minimum node (used in deletion)
Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}

// Delete function
Node* deleteNode(Node* root, int key) {
    if (!root) return root;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        // Case 1: No child
        if (!root->left && !root->right) {
            delete root;
            return NULL;
        }
        // Case 2: One child
        else if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children
        else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int main() {
    Node* root = NULL;

    // Insert values
    int values[] = { 50, 30, 70, 20, 40, 60, 80 };
    for (int val : values) {
        root = insert(root, val);
    }

    cout << "After Insertion (In-order): ";
    inorder(root);
    cout << endl;

    // Delete value
    root = deleteNode(root, 70);

    cout << "After Deletion (In-order): ";
    inorder(root);
    cout << endl;

    return 0;
}

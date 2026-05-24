#include <iostream>
#include <queue>   // Required for BFS (FIFO queue)
using namespace std;

// Node structure for binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Helper to create a new node
Node* newNode(int val) {
    Node* n = new Node();
    n->data = val;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

// BFS (Level-Order) Traversal using a queue
// Visits nodes level by level, from left to right at each level
void BFS(Node* root) {
    if (root == nullptr) return;  // Handle empty tree

    queue<Node*> q;   // Queue holds pointers to nodes waiting to be visited
    q.push(root);     // Start by enqueuing the root node

    while (!q.empty()) {
        Node* current = q.front(); // Get the front node in the queue
        q.pop();                   // Remove it from the queue

        cout << current->data << " "; // Print the node's value

        // Enqueue left child first so it's processed before right (left-to-right order)
        if (current->left != nullptr)
            q.push(current->left);

        // Enqueue right child after left
        if (current->right != nullptr)
            q.push(current->right);
    }
}

int main() {
    // Manually construct the binary tree
    //         40
    //        /  \
    //      20    60
    //     / \   / \
    //    10  30 50  70

    Node* root = newNode(40);
    root->left = newNode(20);
    root->right = newNode(60);
    root->left->left = newNode(10);
    root->left->right = newNode(30);
    root->right->left = newNode(50);
    root->right->right = newNode(70);

    cout << "BFS / Level-Order Traversal: ";
    BFS(root);
    cout << endl;

    return 0;
}

#include <iostream>
#include <stack>   // Required for iterative DFS (LIFO stack)
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

// Iterative DFS Traversal using a stack
// Follows Root -> Left -> Right order (same as preorder)
// Stack is LIFO: Last In, First Out — so we push right before left
void DFS(Node* root) {
    if (root == nullptr) return;  // Handle empty tree

    stack<Node*> s;  // Stack holds pointers to nodes to be visited
    s.push(root);    // Start by pushing the root

    while (!s.empty()) {
        Node* current = s.top(); // Peek at the top node
        s.pop();                 // Remove it from the stack

        cout << current->data << " "; // Print the node's value

        // Push RIGHT child first so LEFT gets processed first (LIFO reversal)
        // If we pushed left first, right would be processed first — wrong order
        if (current->right != nullptr)
            s.push(current->right);

        if (current->left != nullptr)
            s.push(current->left);
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

    cout << "DFS Traversal: ";
    DFS(root);
    cout << endl;

    return 0;
}

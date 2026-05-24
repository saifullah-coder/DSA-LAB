#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

// Node structure for expression tree
struct ExprNode {
    string data;
    ExprNode* left;
    ExprNode* right;
};

// Helper to create a new expression node
ExprNode* newExprNode(string val) {
    ExprNode* n = new ExprNode();
    n->data = val;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

// Check if a token is an operator (+, -, *, /)
bool isOperator(const string& s) {
    return (s == "+" || s == "-" || s == "*" || s == "/");
}

// Build expression tree from a postfix expression string
// Algorithm:
//   - Scan tokens left to right
//   - Operand: create a node and push it onto the stack
//   - Operator: pop two nodes, make them children of a new operator node, push result
ExprNode* buildFromPostfix(const string& postfix) {
    stack<ExprNode*> s;
    stringstream ss(postfix);  // Split postfix string into tokens by spaces
    string token;

    while (ss >> token) {
        if (!isOperator(token)) {
            // Operand: just create a leaf node and push it
            s.push(newExprNode(token));
        } else {
            // Operator: pop two operands from the stack
            ExprNode* opNode = newExprNode(token);

            // First pop becomes the RIGHT child (it was pushed later)
            opNode->right = s.top(); s.pop();

            // Second pop becomes the LEFT child
            opNode->left  = s.top(); s.pop();

            // Push the new subtree back onto the stack
            s.push(opNode);
        }
    }

    // The remaining node on the stack is the root of the expression tree
    return s.top();
}

// Inorder traversal with brackets → infix expression
void printInfix(ExprNode* root) {
    if (root == nullptr) return;
    bool isOp = isOperator(root->data);
    if (isOp) cout << "(";
    printInfix(root->left);
    cout << root->data;
    printInfix(root->right);
    if (isOp) cout << ")";
}

// Preorder traversal → prefix expression
void printPrefix(ExprNode* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    printPrefix(root->left);
    printPrefix(root->right);
}

// Postorder traversal → postfix expression
void printPostfix(ExprNode* root) {
    if (root == nullptr) return;
    printPostfix(root->left);
    printPostfix(root->right);
    cout << root->data << " ";
}

// Evaluate the expression tree recursively
int evaluate(ExprNode* root) {
    if (root == nullptr) return 0;
    if (!isOperator(root->data))
        return stoi(root->data);  // Leaf: convert string to int

    int l = evaluate(root->left);
    int r = evaluate(root->right);
    if (root->data == "+") return l + r;
    if (root->data == "-") return l - r;
    if (root->data == "*") return l * r;
    if (root->data == "/") return l / r;
    return 0;
}

int main() {
    // Postfix expression: 3 5 + 8 2 - *
    // Equivalent to: (3 + 5) * (8 - 2)
    string postfix = "3 5 + 8 2 - *";

    // Build the expression tree from postfix
    ExprNode* root = buildFromPostfix(postfix);

    cout << "Infix Expression: ";
    printInfix(root);
    cout << endl;

    cout << "Prefix Expression: ";
    printPrefix(root);
    cout << endl;

    cout << "Postfix Expression: ";
    printPostfix(root);
    cout << endl;

    cout << "Final Answer: " << evaluate(root) << endl;

    return 0;
}

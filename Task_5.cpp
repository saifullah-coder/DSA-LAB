#include <iostream>
#include <string>
using namespace std;

// Node structure for expression tree
// data holds either an operator (+, -, *) or an operand (number as string)
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

// Inorder traversal: Left -> Root -> Right
// Produces infix expression; brackets are added around each sub-expression
void printInfix(ExprNode* root) {
    if (root == nullptr) return;

    // If the node is an operator (internal node), wrap subtree in brackets
    bool isOperator = (root->data == "+" || root->data == "-" || root->data == "*");

    if (isOperator) cout << "(";
    printInfix(root->left);        // Print left operand/sub-expression
    cout << root->data;            // Print operator or operand
    printInfix(root->right);       // Print right operand/sub-expression
    if (isOperator) cout << ")";
}

// Preorder traversal: Root -> Left -> Right
// Produces prefix (Polish notation) expression
void printPrefix(ExprNode* root) {
    if (root == nullptr) return;
    cout << root->data << " ";     // Print operator/operand first
    printPrefix(root->left);       // Then left subtree
    printPrefix(root->right);      // Then right subtree
}

// Postorder traversal: Left -> Right -> Root
// Produces postfix (Reverse Polish notation) expression
void printPostfix(ExprNode* root) {
    if (root == nullptr) return;
    printPostfix(root->left);      // Left subtree first
    printPostfix(root->right);     // Right subtree
    cout << root->data << " ";     // Operator/operand printed last
}

// Recursively evaluate the expression tree
// Leaf nodes are operands (numbers), internal nodes are operators
int evaluate(ExprNode* root) {
    if (root == nullptr) return 0;

    // If both children are null, this is a leaf node (operand)
    if (root->left == nullptr && root->right == nullptr)
        return stoi(root->data);   // Convert string number to integer

    // Recursively evaluate left and right subtrees
    int leftVal  = evaluate(root->left);
    int rightVal = evaluate(root->right);

    // Apply the operator and print intermediate result for clarity
    if (root->data == "+") {
        cout << leftVal << " + " << rightVal << " = " << (leftVal + rightVal) << endl;
        return leftVal + rightVal;
    }
    if (root->data == "-") {
        cout << leftVal << " - " << rightVal << " = " << (leftVal - rightVal) << endl;
        return leftVal - rightVal;
    }
    if (root->data == "*") {
        cout << leftVal << " * " << rightVal << " = " << (leftVal * rightVal) << endl;
        return leftVal * rightVal;
    }

    return 0; // Should not reach here for valid expressions
}

int main() {
    // Construct the expression tree for: (3 + 5) * (8 - 2)
    //
    //         *
    //        / \
    //       +   -
    //      / \ / \
    //     3  5 8  2
    //
    // Operators are internal nodes; operands are leaf nodes

    ExprNode* root = newExprNode("*");       // Root: multiply operator

    root->left = newExprNode("+");           // Left child: add operator
    root->left->left  = newExprNode("3");    // 3 is left operand of +
    root->left->right = newExprNode("5");    // 5 is right operand of +

    root->right = newExprNode("-");          // Right child: subtract operator
    root->right->left  = newExprNode("8");   // 8 is left operand of -
    root->right->right = newExprNode("2");   // 2 is right operand of -

    // Print all three expression forms
    cout << "Infix Expression: ";
    printInfix(root);
    cout << endl;

    cout << "Prefix Expression: ";
    printPrefix(root);
    cout << endl;

    cout << "Postfix Expression: ";
    printPostfix(root);
    cout << endl;

    // Evaluate and print step-by-step results
    cout << "\nEvaluation:" << endl;
    int result = evaluate(root);
    cout << "Final Answer: " << result << endl;

    return 0;
}

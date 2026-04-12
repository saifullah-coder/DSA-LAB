#include <iostream>
#include <string>
using namespace std;

class Stack {
    char data[100];
    int top;
public:
    Stack() : top(-1) {}
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == 99; }
    void push(char c) { if (!isFull()) data[++top] = c; }
    char pop() { if (!isEmpty()) return data[top--]; return '\0'; }
    char peek() { if (!isEmpty()) return data[top]; return '\0'; }
};

class StringReverser {
public:
    string reverse(string str) {
        Stack s;
        for (char c : str) s.push(c);
        string result = "";
        while (!s.isEmpty()) result += s.pop();
        return result;
    }
};

class ParenthesisChecker {
public:
    bool isBalanced(string expr) {
        Stack s;
        for (char c : expr) {
            if (c == '(' || c == '[' || c == '{') {
                s.push(c);
            } else if (c == ')' || c == ']' || c == '}') {
                if (s.isEmpty()) return false;
                char top = s.pop();
                if (c == ')' && top != '(') return false;
                if (c == ']' && top != '[') return false;
                if (c == '}' && top != '{') return false;
            }
        }
        return s.isEmpty();
    }
};

class InfixToPostfix {
    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        if (op == '^') return 3;
        return 0;
    }
    bool isOperand(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }
public:
    string convert(string infix) {
        Stack s;
        string postfix = "";
        for (char c : infix) {
            if (isOperand(c)) {
                postfix += c;
            } else if (c == '(') {
                s.push(c);
            } else if (c == ')') {
                while (!s.isEmpty() && s.peek() != '(') postfix += s.pop();
                if (!s.isEmpty()) s.pop();
            } else {
                while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) postfix += s.pop();
                s.push(c);
            }
        }
        while (!s.isEmpty()) postfix += s.pop();
        return postfix;
    }
};

int main() {
    int choice;
    cout << "=== Stack Applications ===\n";
    cout << "1. Reverse a String\n";
    cout << "2. Check Balanced Parentheses\n";
    cout << "3. Infix to Postfix\n";
    cout << "Enter choice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        string str;
        cout << "Enter string: ";
        getline(cin, str);
        StringReverser sr;
        cout << "Reversed: " << sr.reverse(str) << "\n";
    } else if (choice == 2) {
        string expr;
        cout << "Enter expression: ";
        getline(cin, expr);
        ParenthesisChecker pc;
        cout << (pc.isBalanced(expr) ? "Balanced" : "Not Balanced") << "\n";
    } else if (choice == 3) {
        string expr;
        cout << "Enter infix expression: ";
        getline(cin, expr);
        InfixToPostfix itp;
        cout << "Postfix: " << itp.convert(expr) << "\n";
    } else {
        cout << "Invalid choice.\n";
    }
    return 0;
}

#include <iostream>
using namespace std;

class Node {
public:
    int   data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node* cur = head;
        while (cur) { Node* t = cur; cur = cur->next; delete t; }
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head          = newNode;
        cout << value << " inserted at the beginning.\n";
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            cout << value << " inserted (list was empty).\n";
            return;
        }

        Node* cur = head;
        while (cur->next != nullptr)
            cur = cur->next;

        cur->next = newNode;
        cout << value << " inserted at the end.\n";
    }

    void deleteByValue(int value) {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head       = head->next;
            delete temp;
            cout << value << " deleted from the list.\n";
            return;
        }

        Node* prev = head;
        Node* cur  = head->next;

        while (cur != nullptr && cur->data != value) {
            prev = cur;
            cur  = cur->next;
        }

        if (cur == nullptr) {
            cout << value << " not found in the list.\n";
            return;
        }

        prev->next = cur->next;
        delete cur;
        cout << value << " deleted from the list.\n";
    }

    void display() const {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* cur = head;
        cout << "List: ";
        while (cur != nullptr) {
            cout << cur->data;
            if (cur->next) cout << " -> ";
            cur = cur->next;
        }
        cout << " -> NULL\n";
    }
};

int main() {
    LinkedList list;

    cout << "=== Task 2: Singly Linked List ADT ===\n\n";

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.display();

    list.insertAtBeginning(5);
    list.display();

    list.deleteByValue(20);
    list.display();

    list.deleteByValue(5);
    list.display();

    list.deleteByValue(99);
    list.display();

    return 0;
}

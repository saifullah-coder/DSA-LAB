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

    int countNodes() const {
        int count = 0;
        Node* cur = head;
        while (cur) { ++count; cur = cur->next; }
        return count;
    }

    void insertAtPosition(int value, int pos) {
        int size = countNodes();

        if (pos < 1 || pos > size + 1) {
            cout << "Invalid position! Valid range: 1 to " << size + 1 << ".\n";
            return;
        }

        Node* newNode = new Node(value);

        if (pos == 1) {
            newNode->next = head;
            head          = newNode;
            cout << value << " inserted at position " << pos << ".\n";
            return;
        }

        Node* cur = head;
        for (int i = 1; i < pos - 1; ++i)
            cur = cur->next;

        newNode->next = cur->next;
        cur->next     = newNode;
        cout << value << " inserted at position " << pos << ".\n";
    }

    void deleteAtPosition(int pos) {
        int size = countNodes();

        if (size == 0) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }

        if (pos < 1 || pos > size) {
            cout << "Invalid position! Valid range: 1 to " << size << ".\n";
            return;
        }

        Node* temp;

        if (pos == 1) {
            temp = head;
            head = head->next;
            cout << "Node with value " << temp->data << " deleted from position 1.\n";
            delete temp;
            return;
        }

        Node* cur = head;
        for (int i = 1; i < pos - 1; ++i)
            cur = cur->next;

        temp      = cur->next;
        cur->next = temp->next;
        cout << "Node with value " << temp->data << " deleted from position " << pos << ".\n";
        delete temp;
    }

    void search(int value) const {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* cur   = head;
        int   pos   = 1;
        bool  found = false;

        while (cur != nullptr) {
            if (cur->data == value) {
                cout << value << " found at position " << pos << ".\n";
                found = true;
            }
            cur = cur->next;
            ++pos;
        }

        if (!found)
            cout << value << " not found in the list.\n";
    }

    void display() const {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* cur = head;
        int   pos = 1;
        cout << "List (total " << countNodes() << " nodes):\n";
        while (cur != nullptr) {
            cout << "  [" << pos++ << "] " << cur->data;
            if (cur->next) cout << "  ->  ";
            cur = cur->next;
        }
        cout << "  ->  NULL\n";
    }
};

void printMenu() {
    cout << "\n========================================\n";
    cout << "       Singly Linked List - Menu        \n";
    cout << "========================================\n";
    cout << "  1. Insert node at a specific position \n";
    cout << "  2. Delete node at a specific position \n";
    cout << "  3. Search for an element              \n";
    cout << "  4. Count total number of nodes        \n";
    cout << "  5. Display the list                   \n";
    cout << "  6. Exit                               \n";
    cout << "========================================\n";
    cout << "Enter your choice: ";
}

int main() {
    LinkedList list;
    int choice;

    cout << "=== Task 3: Menu-Driven Singly Linked List ===\n";

    do {
        printMenu();
        cin >> choice;

        switch (choice) {

        case 1: {
            int value, pos;
            cout << "Enter value to insert : ";
            cin  >> value;
            cout << "Enter position        : ";
            cin  >> pos;
            list.insertAtPosition(value, pos);
            break;
        }

        case 2: {
            int pos;
            cout << "Enter position to delete: ";
            cin  >> pos;
            list.deleteAtPosition(pos);
            break;
        }

        case 3: {
            int value;
            cout << "Enter value to search: ";
            cin  >> value;
            list.search(value);
            break;
        }

        case 4:
            cout << "Total nodes: " << list.countNodes() << "\n";
            break;

        case 5:
            list.display();
            break;

        case 6:
            cout << "Exiting program. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Please enter 1-6.\n";
        }

    } while (choice != 6);

    return 0;
}

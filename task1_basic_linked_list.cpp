#include <iostream>
using namespace std;

class Node {
public:
    int  data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    ~SinglyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current    = current->next;
            delete temp;
        }
    }

    void CreateNode(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    void Display() const {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* current = head;
        cout << "List: ";
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) cout << " -> ";
            current = current->next;
        }
        cout << " -> NULL\n";
    }
};

int main() {
    SinglyLinkedList list;

    cout << "=== Task 1: Singly Linked List (CreateNode + Display) ===\n\n";

    list.CreateNode(10);
    list.CreateNode(20);
    list.CreateNode(30);
    list.CreateNode(40);
    list.CreateNode(50);

    list.Display();

    return 0;
}

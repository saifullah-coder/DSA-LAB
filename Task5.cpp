#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

void printList(Node* head) {
    if (head == nullptr) {
        cout << endl;
        return;
    }
    cout << head->data << " ";
    printList(head->next);
}

void insertAtBeginning(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node*& head, int val) {
    if (head == nullptr) {
        head = new Node(val);
        return;
    }
    insertAtEnd(head->next, val);
}

void insertAtPosition(Node*& head, int val, int pos) {
    if (pos == 1) {
        insertAtBeginning(head, val);
        return;
    }

    if (head == nullptr) {
        cout << "Position out of range." << endl;
        return;
    }

    insertAtPosition(head->next, val, pos - 1);
}

void deleteByValue(Node*& head, int val) {
    if (head == nullptr) {
        cout << "Value not found." << endl;
        return;
    }

    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    deleteByValue(head->next, val);
}

void deleteAtPosition(Node*& head, int pos) {
    if (head == nullptr) {
        cout << "Position out of range." << endl;
        return;
    }

    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    deleteAtPosition(head->next, pos - 1);
}

int search(Node* head, int val, int index = 1) {
    if (head == nullptr)
        return -1;

    if (head->data == val)
        return index;

    return search(head->next, val, index + 1);
}

int main() {
    Node* head = nullptr;

    insertAtEnd(head, 10);
    cout << "After insert 10 at end: ";
    printList(head);

    insertAtEnd(head, 20);
    cout << "After insert 20 at end: ";
    printList(head);

    insertAtEnd(head, 30);
    cout << "After insert 30 at end: ";
    printList(head);

    insertAtBeginning(head, 5);
    cout << "After insert 5 at beginning: ";
    printList(head);

    insertAtPosition(head, 15, 3);
    cout << "After insert 15 at position 3: ";
    printList(head);

    cout << "Search 20: " << search(head, 20) << endl;
    cout << "Search 99: " << search(head, 99) << endl;

    deleteByValue(head, 15);
    cout << "After delete 15: ";
    printList(head);

    deleteAtPosition(head, 2);
    cout << "After delete position 2: ";
    printList(head);

    return 0;
}
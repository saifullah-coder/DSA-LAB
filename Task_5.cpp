#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void printList(Node* head) {
    if (head == nullptr) {
        cout << endl;
        return;
    }
    cout << head->data << " ";
    printList(head->next);
}

Node* insertAtBeginning(Node* head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    return newNode;
}

Node* insertAtEnd(Node* head, int val) {
    if (head == nullptr)
        return new Node(val);
    head->next = insertAtEnd(head->next, val);
    return head;
}

Node* insertAtPosition(Node* head, int val, int pos) {
    if (pos == 1) {
        Node* newNode = new Node(val);
        newNode->next = head;
        return newNode;
    }
    if (head == nullptr) {
        cout << "Position out of range." << endl;
        return head;
    }
    head->next = insertAtPosition(head->next, val, pos - 1);
    return head;
}

Node* deleteByValue(Node* head, int val) {
    if (head == nullptr) {
        cout << "Value not found." << endl;
        return nullptr;
    }
    if (head->data == val) {
        Node* temp = head->next;
        delete head;
        return temp;
    }
    head->next = deleteByValue(head->next, val);
    return head;
}

Node* deleteAtPosition(Node* head, int pos) {
    if (head == nullptr) {
        cout << "Position out of range." << endl;
        return nullptr;
    }
    if (pos == 1) {
        Node* temp = head->next;
        delete head;
        return temp;
    }
    head->next = deleteAtPosition(head->next, pos - 1);
    return head;
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

    head = insertAtEnd(head, 10);
    cout << "After insert 10 at end: ";
    printList(head);

    head = insertAtEnd(head, 20);
    cout << "After insert 20 at end: ";
    printList(head);

    head = insertAtEnd(head, 30);
    cout << "After insert 30 at end: ";
    printList(head);

    head = insertAtBeginning(head, 5);
    cout << "After insert 5 at beginning: ";
    printList(head);

    head = insertAtPosition(head, 15, 3);
    cout << "After insert 15 at position 3: ";
    printList(head);

    int pos = search(head, 20);
    cout << "Search 20: position " << pos << endl;

    pos = search(head, 99);
    cout << "Search 99: position " << pos << endl;

    head = deleteByValue(head, 15);
    cout << "After delete by value 15: ";
    printList(head);

    head = deleteAtPosition(head, 2);
    cout << "After delete at position 2: ";
    printList(head);

    return 0;
}

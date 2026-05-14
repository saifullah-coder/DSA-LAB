#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

void printForward(Node* head) {
    if (head == nullptr) {
        cout << endl;
        return;
    }
    cout << head->data << " ";
    printForward(head->next);
}

void printReverse(Node* tail) {
    if (tail == nullptr) {
        cout << endl;
        return;
    }
    cout << tail->data << " ";
    printReverse(tail->prev);
}

Node* getTail(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    return getTail(head->next);
}

Node* insertAtBeginning(Node* head, int val) {
    Node* newNode = new Node(val);

    if (head != nullptr) {
        newNode->next = head;
        head->prev = newNode;
    }

    return newNode;
}

Node* insertAtEnd(Node* head, int val) {
    if (head == nullptr)
        return new Node(val);

    head->next = insertAtEnd(head->next, val);

    if (head->next != nullptr)
        head->next->prev = head;

    return head;
}

Node* insertAtPosition(Node* head, int val, int pos) {
    if (pos == 1) {
        return insertAtBeginning(head, val);
    }

    if (head == nullptr) {
        cout << "Position out of range." << endl;
        return nullptr;
    }

    head->next = insertAtPosition(head->next, val, pos - 1);

    if (head->next != nullptr)
        head->next->prev = head;

    return head;
}

Node* deleteByValue(Node* head, int val) {
    if (head == nullptr)
        return nullptr;

    if (head->data == val) {
        Node* temp = head->next;

        if (temp != nullptr)
            temp->prev = head->prev;

        delete head;
        return temp;
    }

    head->next = deleteByValue(head->next, val);

    if (head->next != nullptr)
        head->next->prev = head;

    return head;
}

Node* deleteAtPosition(Node* head, int pos) {
    if (head == nullptr)
        return nullptr;

    if (pos == 1) {
        Node* temp = head->next;

        if (temp != nullptr)
            temp->prev = nullptr;

        delete head;
        return temp;
    }

    head->next = deleteAtPosition(head->next, pos - 1);

    if (head->next != nullptr)
        head->next->prev = head;

    return head;
}

int search(Node* head, int val, int index = 1) {
    if (head == nullptr)
        return -1;

    if (head->data == val)
        return index;

    return search(head->next, val, index + 1);
}

bool checkPalindrome(Node* front, Node* back, int size) {
    if (size <= 0)
        return true;

    if (front->data != back->data)
        return false;

    return checkPalindrome(front->next, back->prev, size - 2);
}

int listSize(Node* head) {
    if (head == nullptr)
        return 0;

    return 1 + listSize(head->next);
}

int main() {
    Node* head = nullptr;

    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);

    cout << "List: ";
    printForward(head);

    head = insertAtBeginning(head, 0);
    cout << "After insert beginning: ";
    printForward(head);

    head = insertAtPosition(head, 99, 3);
    cout << "After insert at position 3: ";
    printForward(head);

    cout << "Reverse: ";
    printReverse(getTail(head));

    cout << "Search 3: " << search(head, 3) << endl;
    cout << "Search 50: " << search(head, 50) << endl;

    head = deleteByValue(head, 99);
    cout << "After delete 99: ";
    printForward(head);

    head = deleteAtPosition(head, 1);
    cout << "After delete position 1: ";
    printForward(head);

    Node* pal = nullptr;
    pal = insertAtEnd(pal, 1);
    pal = insertAtEnd(pal, 2);
    pal = insertAtEnd(pal, 1);

    cout << "Palindrome [1,2,1]: "
        << (checkPalindrome(pal, getTail(pal), listSize(pal)) ? "Yes" : "No")
        << endl;

    return 0;
}
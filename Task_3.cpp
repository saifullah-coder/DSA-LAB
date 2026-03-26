#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int frontIndex;
    int rearIndex;
    int count;
    int capacity;

public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(int val) {
        if (count == capacity) {
            cout << "Queue is full.\n";
            return;
        }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = val;
        count++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1;
        }
        int val = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        count--;
        return val;
    }

    int front() const {
        if (isEmpty()) return -1;
        return arr[frontIndex];
    }

    bool isEmpty() const {
        return count == 0;
    }

    int size() const {
        return count;
    }

    void display() const {
        for (int i = 0; i < count; i++) {
            cout << arr[(frontIndex + i) % capacity] << " ";
        }
        cout << "\n";
    }
};

class Stack {
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int val) {
        arr[++top] = val;
    }

    int pop() {
        return arr[top--];
    }

    bool isEmpty() const {
        return top == -1;
    }
};

void reverseFirstK(Queue& q, int k) {
    if (k <= 1 || k > q.size()) return;

    Stack s(k);

    for (int i = 0; i < k; i++) {
        s.push(q.dequeue());
    }

    Queue temp(q.size() + k);

    while (!s.isEmpty()) {
        temp.enqueue(s.pop());
    }

    while (!q.isEmpty()) {
        temp.enqueue(q.dequeue());
    }

    while (!temp.isEmpty()) {
        q.enqueue(temp.dequeue());
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    Queue q(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        q.enqueue(val);
    }

    int k;
    cout << "Enter K: ";
    cin >> k;

    reverseFirstK(q, k);

    cout << "Output: ";
    q.display();

    return 0;
}

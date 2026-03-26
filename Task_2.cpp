#include <iostream>
using namespace std;

template <typename T>
class Stack {
    T* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new T[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(T val) {
        if (top == capacity - 1) {
            cout << "Stack overflow.\n";
            return;
        }
        arr[++top] = val;
    }

    T pop() {
        if (top == -1) {
            cout << "Stack underflow.\n";
            return T();
        }
        return arr[top--];
    }

    T peek() const {
        if (top == -1) {
            cout << "Stack is empty.\n";
            return T();
        }
        return arr[top];
    }

    bool isEmpty() const {
        return top == -1;
    }

    int size() const {
        return top + 1;
    }

    T getAt(int i) const {
        return arr[i];
    }
};

template <typename T>
class QueueUsingStacks {
    Stack<T> s1;
    Stack<T> s2;

    void transfer() {
        if (s2.isEmpty()) {
            while (!s1.isEmpty()) {
                s2.push(s1.pop());
            }
        }
    }

public:
    QueueUsingStacks(int size) : s1(size), s2(size) {}

    void enqueue(T val) {
        s1.push(val);
    }

    T dequeue() {
        transfer();
        if (s2.isEmpty()) {
            cout << "Queue is empty.\n";
            return T();
        }
        return s2.pop();
    }

    T front() {
        transfer();
        if (s2.isEmpty()) {
            cout << "Queue is empty.\n";
            return T();
        }
        return s2.peek();
    }

    bool isEmpty() {
        return s1.isEmpty() && s2.isEmpty();
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue (front to rear): ";
        for (int i = 0; i < s2.size(); i++) {
            cout << s2.getAt(i) << " ";
        }
        for (int i = s1.size() - 1; i >= 0; i--) {
            cout << s1.getAt(i) << " ";
        }
        cout << "\n";
    }
};

int main() {
    int size;
    cout << "Enter max queue size: ";
    cin >> size;

    QueueUsingStacks<int> q(size);
    int choice, value;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Front\n4. Display\n0. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            cout << "Dequeued: " << q.dequeue() << "\n";
            break;
        case 3:
            cout << "Front: " << q.front() << "\n";
            break;
        case 4:
            q.display();
            break;
        case 0:
            cout << "Exiting.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}

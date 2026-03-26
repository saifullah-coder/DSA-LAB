#include <iostream>
using namespace std;

template <typename T>
class AbstractQueue {
public:
    virtual void enQueue(T value) = 0;
    virtual T deQueue() = 0;
    virtual T front() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractQueue() {}
};

template <typename T>
class myQueue : public AbstractQueue<T> {
    T* arr;
    int capacity;
    int frontIndex;
    int rearIndex;
    int count;

public:
    myQueue(int size) {
        capacity = size;
        arr = new T[capacity];
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    ~myQueue() {
        delete[] arr;
    }

    void enQueue(T value) {
        if (isFull()) {
            cout << "Queue is full.\n";
            return;
        }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = value;
        count++;
    }

    T deQueue() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return T();
        }
        T val = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        count--;
        return val;
    }

    T front() const {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return T();
        }
        return arr[frontIndex];
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == capacity;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements (front to rear): ";
        for (int i = 0; i < count; i++) {
            cout << arr[(frontIndex + i) % capacity] << " ";
        }
        cout << "\n";
    }
};

int main() {
    int size;
    cout << "Enter queue size: ";
    cin >> size;

    myQueue<int> q(size);
    int choice, value;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Front\n4. Display\n5. Is Empty\n6. Is Full\n0. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enQueue(value);
            break;
        case 2:
            cout << "Dequeued: " << q.deQueue() << "\n";
            break;
        case 3:
            cout << "Front: " << q.front() << "\n";
            break;
        case 4:
            q.display();
            break;
        case 5:
            cout << (q.isEmpty() ? "Queue is empty." : "Queue is not empty.") << "\n";
            break;
        case 6:
            cout << (q.isFull() ? "Queue is full." : "Queue is not full.") << "\n";
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

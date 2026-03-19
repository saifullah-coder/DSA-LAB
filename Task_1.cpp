#include <iostream>
#include <string>
using namespace std;

template <typename T>
class AbstractStack {
public:
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractStack() {}
};

template <typename T>
class myStack : public AbstractStack<T> {
private:
    T* arr;
    int maxSize;
    int topIndex;

public:
    myStack(int size) {
        maxSize = size;
        arr = new T[maxSize];
        topIndex = -1;
    }

    ~myStack() {
        delete[] arr;
    }

    void push(T value) {
        if (isFull()) {
            cout << "Stack is full. Cannot push.\n";
            return;
        }
        arr[++topIndex] = value;
        cout << value << " pushed onto the stack.\n";
    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop.\n";
            return T();
        }
        return arr[topIndex--];
    }

    T top() const {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return T();
        }
        return arr[topIndex];
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    bool isFull() const {
        return topIndex == maxSize - 1;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = topIndex; i >= 0; i--) {
            cout << arr[i];
            if (i != 0) cout << " -> ";
        }
        cout << "\n";
    }
};

int main() {
    int size;
    cout << "Enter the maximum size of the stack: ";
    cin >> size;

    myStack<int> s(size);
    int choice, value;

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push element\n";
        cout << "2. Pop element\n";
        cout << "3. Show top element\n";
        cout << "4. Check if stack is empty\n";
        cout << "5. Check if stack is full\n";
        cout << "6. Display stack elements\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            if (!s.isEmpty())
                cout << "Popped: " << s.pop() << "\n";
            break;
        case 3:
            if (!s.isEmpty())
                cout << "Top element: " << s.top() << "\n";
            break;
        case 4:
            cout << (s.isEmpty() ? "Stack is empty.\n" : "Stack is not empty.\n");
            break;
        case 5:
            cout << (s.isFull() ? "Stack is full.\n" : "Stack is not full.\n");
            break;
        case 6:
            s.display();
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 7);

    return 0;
}

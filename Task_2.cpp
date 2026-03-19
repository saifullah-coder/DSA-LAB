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
    T* minArr;
    int maxSize;
    int topIndex;
    int minTop;

public:
    myStack(int size) {
        maxSize = size;
        arr = new T[maxSize];
        minArr = new T[maxSize];
        topIndex = -1;
        minTop = -1;
    }

    ~myStack() {
        delete[] arr;
        delete[] minArr;
    }

    void push(T value) {
        if (isFull()) {
            cout << "Stack is full. Cannot push.\n";
            return;
        }
        arr[++topIndex] = value;
        if (minTop == -1 || value <= minArr[minTop]) {
            minArr[++minTop] = value;
        }
        cout << value << " pushed onto the stack.\n";
    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop.\n";
            return T();
        }
        T val = arr[topIndex--];
        if (val == minArr[minTop]) {
            minTop--;
        }
        return val;
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

    T getMin() const {
        if (minTop == -1) {
            cout << "Stack is empty. No minimum.\n";
            return T();
        }
        return minArr[minTop];
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
        cout << "\n--- Enhanced Stack Menu ---\n";
        cout << "1. Push element\n";
        cout << "2. Pop element\n";
        cout << "3. Show top element\n";
        cout << "4. Check if stack is empty\n";
        cout << "5. Check if stack is full\n";
        cout << "6. Display stack elements\n";
        cout << "7. Show minimum element\n";
        cout << "8. Exit\n";
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
            if (!s.isEmpty())
                cout << "Minimum element: " << s.getMin() << "\n";
            break;
        case 8:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 8);

    return 0;
}

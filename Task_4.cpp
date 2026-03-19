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
        if (isFull()) return;
        arr[++topIndex] = value;
    }

    T pop() {
        if (isEmpty()) return T();
        return arr[topIndex--];
    }

    T top() const {
        if (isEmpty()) return T();
        return arr[topIndex];
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    bool isFull() const {
        return topIndex == maxSize - 1;
    }

    void clear() {
        topIndex = -1;
    }
};

int main() {
    myStack<string> undoStack(100);
    myStack<string> redoStack(100);

    string currentText = "";
    int choice;
    string input;

    cout << "=== Simple Text Editor ===\n";

    do {
        cout << "\nCurrent text: \"" << currentText << "\"\n";
        cout << "1. Type text\n";
        cout << "2. Delete last character\n";
        cout << "3. Undo\n";
        cout << "4. Redo\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter text to type: ";
            getline(cin, input);
            undoStack.push(currentText);
            redoStack.clear();
            currentText += input;
            cout << "Text added.\n";
            break;

        case 2:
            if (currentText.empty()) {
                cout << "Nothing to delete.\n";
            } else {
                undoStack.push(currentText);
                redoStack.clear();
                currentText = currentText.substr(0, currentText.length() - 1);
                cout << "Last character deleted.\n";
            }
            break;

        case 3:
            if (undoStack.isEmpty()) {
                cout << "Nothing to undo.\n";
            } else {
                redoStack.push(currentText);
                currentText = undoStack.pop();
                cout << "Undo successful.\n";
            }
            break;

        case 4:
            if (redoStack.isEmpty()) {
                cout << "Nothing to redo.\n";
            } else {
                undoStack.push(currentText);
                currentText = redoStack.pop();
                cout << "Redo successful.\n";
            }
            break;

        case 5:
            cout << "Exiting editor. Final text: \"" << currentText << "\"\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}

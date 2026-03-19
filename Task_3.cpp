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
class myCarStack : public AbstractStack<T> {
private:
    T* arr;
    int maxSize;
    int topIndex;

public:
    myCarStack(int size) {
        maxSize = size;
        arr = new T[maxSize];
        topIndex = -1;
    }

    ~myCarStack() {
        delete[] arr;
    }

    void push(T value) {
        if (isFull()) {
            cout << "Parking lot is full. Cannot park more cars.\n";
            return;
        }
        arr[++topIndex] = value;
        cout << "Car " << value << " parked successfully.\n";
    }

    T pop() {
        if (isEmpty()) {
            cout << "Parking lot is empty.\n";
            return T();
        }
        return arr[topIndex--];
    }

    T top() const {
        if (isEmpty()) {
            cout << "Parking lot is empty.\n";
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

    int count() const {
        return topIndex + 1;
    }

    void display() const {
        if (isEmpty()) {
            cout << "No cars in the parking lot.\n";
            return;
        }
        cout << "Cars in parking lot (top to bottom):\n";
        for (int i = topIndex; i >= 0; i--) {
            cout << "  [" << (topIndex - i + 1) << "] " << arr[i] << "\n";
        }
    }

    bool search(T plate) const {
        for (int i = 0; i <= topIndex; i++) {
            if (arr[i] == plate) return true;
        }
        return false;
    }

    void removeCar(T plate, myCarStack<T>& temp) {
        if (!search(plate)) {
            cout << "Car " << plate << " not found in the parking lot.\n";
            return;
        }

        while (!isEmpty() && top() != plate) {
            temp.push(pop());
        }

        if (!isEmpty()) {
            pop();
            cout << "Car " << plate << " has left the parking lot.\n";
        }

        while (!temp.isEmpty()) {
            push(temp.pop());
        }
    }
};

int main() {
    myCarStack<string> lot(8);
    myCarStack<string> temp(8);

    int choice;
    string plate;

    do {
        cout << "\n--- Parking Lot Management System ---\n";
        cout << "1. Park a car\n";
        cout << "2. Remove a car by plate number\n";
        cout << "3. View all parked cars\n";
        cout << "4. Total cars parked\n";
        cout << "5. Search for a car\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter car plate number: ";
            cin >> plate;
            if (lot.search(plate))
                cout << "Car " << plate << " is already parked.\n";
            else
                lot.push(plate);
            break;
        case 2:
            cout << "Enter plate number of car to remove: ";
            cin >> plate;
            lot.removeCar(plate, temp);
            break;
        case 3:
            lot.display();
            break;
        case 4:
            cout << "Total cars parked: " << lot.count() << "\n";
            break;
        case 5:
            cout << "Enter plate number to search: ";
            cin >> plate;
            if (lot.search(plate))
                cout << "Car " << plate << " is in the parking lot.\n";
            else
                cout << "Car " << plate << " is not found.\n";
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

class PrintQueue {
    string* arr;
    int frontIndex;
    int rearIndex;
    int count;
    int capacity;

public:
    PrintQueue(int size) {
        capacity = size;
        arr = new string[capacity];
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    ~PrintQueue() {
        delete[] arr;
    }

    void enqueue(string document_name) {
        if (count == capacity) {
            cout << "Print queue is full.\n";
            return;
        }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = document_name;
        count++;
        cout << "\"" << document_name << "\" added to print queue.\n";
    }

    void dequeue() {
        if (count == 0) {
            cout << "No documents in queue.\n";
            return;
        }
        string doc = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        count--;
        cout << "Printing: \"" << doc << "\"\n";
    }

    void front() const {
        if (count == 0) {
            cout << "No documents in queue.\n";
            return;
        }
        cout << "Next document to print: \"" << arr[frontIndex] << "\"\n";
    }

    void display() const {
        if (count == 0) {
            cout << "No pending print jobs.\n";
            return;
        }
        cout << "Pending print jobs (front to rear):\n";
        for (int i = 0; i < count; i++) {
            cout << "  " << (i + 1) << ". " << arr[(frontIndex + i) % capacity] << "\n";
        }
    }
};

int main() {
    int size;
    cout << "Enter max print queue size: ";
    cin >> size;
    cin.ignore();

    PrintQueue pq(size);
    int choice;

    do {
        cout << "\n1. Add Print Job\n2. Print Document\n3. View Next Document\n4. Display Queue\n0. Exit\nChoice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            string name;
            cout << "Enter document name: ";
            getline(cin, name);
            pq.enqueue(name);
            break;
        }
        case 2:
            pq.dequeue();
            break;
        case 3:
            pq.front();
            break;
        case 4:
            pq.display();
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

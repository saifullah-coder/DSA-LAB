#include <iostream>
#include <string>
using namespace std;

struct Package {
    int id;
    string address;
    int startTime;
    int endTime;
};

class DeliveryQueue {
    Package* arr;
    int frontIndex;
    int rearIndex;
    int count;
    int capacity;

public:
    DeliveryQueue(int size) {
        capacity = size;
        arr = new Package[capacity];
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    ~DeliveryQueue() {
        delete[] arr;
    }

    void enqueue(int id, string address, int startTime, int endTime) {
        if (count == capacity) {
            cout << "Delivery queue is full.\n";
            return;
        }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = {id, address, startTime, endTime};
        count++;
        cout << "Package " << id << " added to queue.\n";
    }

    void dequeue() {
        if (count == 0) {
            cout << "Queue is empty.\n";
            return;
        }
        Package p = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        count--;
        cout << "Package " << p.id << " delivered to " << p.address << " and removed from queue.\n";
    }

    void front() const {
        if (count == 0) {
            cout << "Queue is empty.\n";
            return;
        }
        Package p = arr[frontIndex];
        cout << "Next package -> ID: " << p.id << ", Address: " << p.address
             << ", Window: " << p.startTime << "-" << p.endTime << "\n";
    }

    void display() const {
        if (count == 0) {
            cout << "No packages in queue.\n";
            return;
        }
        cout << "Packages in queue:\n";
        for (int i = 0; i < count; i++) {
            Package p = arr[(frontIndex + i) % capacity];
            cout << "  ID: " << p.id << " | Address: " << p.address
                 << " | Window: " << p.startTime << "-" << p.endTime << "\n";
        }
    }

    void timeToDeliver(int currentTime) {
        if (count == 0) {
            cout << "Queue is empty.\n";
            return;
        }

        while (count > 0) {
            Package p = arr[frontIndex];
            if (currentTime >= p.startTime && currentTime <= p.endTime) {
                cout << "Package " << p.id << " can be delivered on time.\n";
                return;
            } else {
                cout << "Package " << p.id << " is expired. Skipping.\n";
                frontIndex = (frontIndex + 1) % capacity;
                count--;
            }
        }

        cout << "No deliverable packages at current time " << currentTime << ".\n";
    }
};

int main() {
    int size;
    cout << "Enter max queue size: ";
    cin >> size;
    cin.ignore();

    DeliveryQueue dq(size);
    int choice;

    do {
        cout << "\n1. Add Package\n2. Deliver (Dequeue)\n3. View Front Package\n4. Display All Packages\n5. Check Deliverability\n0. Exit\nChoice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            int id, start, end;
            string address;
            cout << "Enter Package ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Delivery Address: ";
            getline(cin, address);
            cout << "Enter Start Time: ";
            cin >> start;
            cout << "Enter End Time: ";
            cin >> end;
            cin.ignore();
            dq.enqueue(id, address, start, end);
            break;
        }
        case 2:
            dq.dequeue();
            break;
        case 3:
            dq.front();
            break;
        case 4:
            dq.display();
            break;
        case 5: {
            int currentTime;
            cout << "Enter current time: ";
            cin >> currentTime;
            cin.ignore();
            dq.timeToDeliver(currentTime);
            break;
        }
        case 0:
            cout << "Exiting.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}

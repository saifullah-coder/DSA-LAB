#include <iostream>
#include <string>
using namespace std;

struct Flight {
    string flightID;
    Flight* next;
    Flight(string id) : flightID(id), next(nullptr) {}
};

class Queue {
    Flight* front;
    Flight* rear;
    string label;
public:
    Queue(string lbl) : front(nullptr), rear(nullptr), label(lbl) {}

    void enqueue(string flightID) {
        Flight* node = new Flight(flightID);
        if (!rear) { front = rear = node; }
        else { rear->next = node; rear = node; }
    }

    string dequeue() {
        if (!front) return "";
        string id = front->flightID;
        Flight* temp = front;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
        return id;
    }

    bool isEmpty() { return front == nullptr; }

    string getLabel() { return label; }

    void display() {
        cout << label << " Queue: ";
        if (!front) { cout << "[empty]\n"; return; }
        Flight* temp = front;
        while (temp) { cout << temp->flightID << " "; temp = temp->next; }
        cout << "\n";
    }

    ~Queue() {
        while (front) {
            Flight* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

class AirportScheduler {
    Queue emergencyQueue;
    Queue passengerQueue;
    Queue cargoQueue;
public:
    AirportScheduler() : emergencyQueue("Emergency"), passengerQueue("Passenger"), cargoQueue("Cargo") {}

    void enqueue(char type, string flightID) {
        if (type == 'E' || type == 'e') {
            emergencyQueue.enqueue(flightID);
            cout << "Emergency flight " << flightID << " added.\n";
        } else if (type == 'P' || type == 'p') {
            passengerQueue.enqueue(flightID);
            cout << "Passenger flight " << flightID << " added.\n";
        } else if (type == 'C' || type == 'c') {
            cargoQueue.enqueue(flightID);
            cout << "Cargo flight " << flightID << " added.\n";
        } else {
            cout << "Unknown flight type.\n";
        }
    }

    void dequeue() {
        if (!emergencyQueue.isEmpty()) {
            cout << "[LANDING] " << emergencyQueue.dequeue() << " (Emergency)\n";
        } else if (!passengerQueue.isEmpty()) {
            cout << "[LANDING] " << passengerQueue.dequeue() << " (Passenger)\n";
        } else if (!cargoQueue.isEmpty()) {
            cout << "[LANDING] " << cargoQueue.dequeue() << " (Cargo)\n";
        } else {
            cout << "No flights waiting to land.\n";
        }
    }

    void display() {
        cout << "\n--- Runway Queue Status ---\n";
        emergencyQueue.display();
        passengerQueue.display();
        cargoQueue.display();
        cout << "---------------------------\n";
    }

    void landAll() {
        cout << "\n=== Final Landing Order ===\n";
        int order = 1;
        while (!emergencyQueue.isEmpty() || !passengerQueue.isEmpty() || !cargoQueue.isEmpty()) {
            cout << order++ << ". ";
            dequeue();
        }
    }
};

int main() {
    AirportScheduler scheduler;
    int choice;

    cout << "=== Airport Runway Scheduling System ===\n";
    cout << "\n--- Demo: Arriving sequence: P1, C1, E1, P2, C2, E2 ---\n";
    scheduler.enqueue('P', "P1");
    scheduler.enqueue('C', "C1");
    scheduler.enqueue('E', "E1");
    scheduler.enqueue('P', "P2");
    scheduler.enqueue('C', "C2");
    scheduler.enqueue('E', "E2");
    scheduler.display();
    scheduler.landAll();

    cout << "\n--- Interactive Mode ---\n";
    do {
        cout << "\n1. Add Flight\n2. Land Next Flight\n3. Display Queues\n4. Land All\n0. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            char type;
            string id;
            cout << "Type (E/P/C): "; cin >> type; cin.ignore();
            cout << "Flight ID: "; getline(cin, id);
            scheduler.enqueue(type, id);
        } else if (choice == 2) {
            scheduler.dequeue();
        } else if (choice == 3) {
            scheduler.display();
        } else if (choice == 4) {
            scheduler.landAll();
        } else if (choice != 0) {
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    cout << "System shutdown.\n";
    return 0;
}

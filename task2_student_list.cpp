#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
    Student* next;
    Student(int r, string n, float m) : rollNo(r), name(n), marks(m), next(nullptr) {}
};

class StudentList {
    Student* head;
public:
    StudentList() : head(nullptr) {}

    void insertAtBeginning(int roll, string name, float marks) {
        Student* node = new Student(roll, name, marks);
        node->next = head;
        head = node;
        cout << "Inserted at beginning.\n";
    }

    void insertAtEnd(int roll, string name, float marks) {
        Student* node = new Student(roll, name, marks);
        if (!head) { head = node; cout << "Inserted at end.\n"; return; }
        Student* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = node;
        cout << "Inserted at end.\n";
    }

    void insertAfter(int afterRoll, int roll, string name, float marks) {
        Student* temp = head;
        while (temp && temp->rollNo != afterRoll) temp = temp->next;
        if (!temp) { cout << "Roll No " << afterRoll << " not found.\n"; return; }
        Student* node = new Student(roll, name, marks);
        node->next = temp->next;
        temp->next = node;
        cout << "Inserted after Roll No " << afterRoll << ".\n";
    }

    void deleteRecord(int roll) {
        if (!head) { cout << "List is empty.\n"; return; }
        if (head->rollNo == roll) {
            Student* temp = head;
            head = head->next;
            delete temp;
            cout << "Record deleted.\n";
            return;
        }
        Student* prev = head;
        Student* curr = head->next;
        while (curr && curr->rollNo != roll) { prev = curr; curr = curr->next; }
        if (!curr) { cout << "Roll No " << roll << " not found.\n"; return; }
        prev->next = curr->next;
        delete curr;
        cout << "Record deleted.\n";
    }

    void display() {
        if (!head) { cout << "No records found.\n"; return; }
        cout << "\n-------------------------------------------\n";
        cout << "Roll No | Name                 | Marks\n";
        cout << "-------------------------------------------\n";
        Student* temp = head;
        while (temp) {
            cout << temp->rollNo << "\t | " << temp->name;
            int spaces = 20 - temp->name.length();
            for (int i = 0; i < spaces; i++) cout << " ";
            cout << " | " << temp->marks << "\n";
            temp = temp->next;
        }
        cout << "-------------------------------------------\n";
    }

    void search(int roll) {
        Student* temp = head;
        while (temp) {
            if (temp->rollNo == roll) {
                cout << "Found -> Roll: " << temp->rollNo << ", Name: " << temp->name << ", Marks: " << temp->marks << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Student with Roll No " << roll << " not found.\n";
    }

    void update(int roll) {
        Student* temp = head;
        while (temp) {
            if (temp->rollNo == roll) {
                int field;
                cout << "Update: 1. Name  2. Marks\nChoice: ";
                cin >> field;
                cin.ignore();
                if (field == 1) {
                    cout << "New Name: ";
                    getline(cin, temp->name);
                } else if (field == 2) {
                    cout << "New Marks: ";
                    cin >> temp->marks;
                } else {
                    cout << "Invalid choice.\n";
                }
                cout << "Updated successfully.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Student with Roll No " << roll << " not found.\n";
    }

    void statistics() {
        if (!head) { cout << "No records to compute statistics.\n"; return; }
        float highest = head->marks, lowest = head->marks, sum = 0;
        int count = 0;
        Student* temp = head;
        while (temp) {
            if (temp->marks > highest) highest = temp->marks;
            if (temp->marks < lowest) lowest = temp->marks;
            sum += temp->marks;
            count++;
            temp = temp->next;
        }
        cout << "Highest: " << highest << " | Lowest: " << lowest << " | Average: " << sum / count << "\n";
    }

    ~StudentList() {
        while (head) {
            Student* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    StudentList list;
    int choice;
    do {
        cout << "\n=== Student Record Management ===\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert After Roll No\n";
        cout << "4. Delete\n5. Display\n6. Search\n7. Update\n8. Statistics\n0. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1 || choice == 2 || choice == 3) {
            int roll, after = 0;
            string name;
            float marks;
            if (choice == 3) {
                cout << "Insert after Roll No: ";
                cin >> after;
                cin.ignore();
            }
            cout << "Roll No: "; cin >> roll; cin.ignore();
            cout << "Name: "; getline(cin, name);
            cout << "Marks: "; cin >> marks; cin.ignore();
            if (choice == 1) list.insertAtBeginning(roll, name, marks);
            else if (choice == 2) list.insertAtEnd(roll, name, marks);
            else list.insertAfter(after, roll, name, marks);
        } else if (choice == 4) {
            int roll; cout << "Roll No to delete: "; cin >> roll; cin.ignore();
            list.deleteRecord(roll);
        } else if (choice == 5) {
            list.display();
        } else if (choice == 6) {
            int roll; cout << "Roll No to search: "; cin >> roll; cin.ignore();
            list.search(roll);
        } else if (choice == 7) {
            int roll; cout << "Roll No to update: "; cin >> roll; cin.ignore();
            list.update(roll);
        } else if (choice == 8) {
            list.statistics();
        } else if (choice != 0) {
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    cout << "Exiting...\n";
    return 0;
}

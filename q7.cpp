#include <iostream>
#include <string>
using namespace std;

#define SIZE 10

class LibraryQueue {
    string patrons[SIZE];
    int front, rear;

public:
    LibraryQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    bool isFull() {
        return (rear == SIZE - 1);
    }

    void addPatron(string name) {
        if (isFull()) {
            cout << "Queue is full! Cannot add more patrons.\n";
            return;
        }
        if (front == -1) front = 0;
        patrons[++rear] = name;
        cout << name << " has joined the library queue.\n";
    }

    void servePatron() {
        if (isEmpty()) {
            cout << "No patrons to serve!\n";
            return;
        }
        cout << patrons[front] << " has completed their book transaction.\n";
        front++;
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "No patrons currently waiting.\n";
            return;
        }
        cout << "\nPatrons waiting in line (Front → Rear): ";
        for (int i = front; i <= rear; i++)
            cout << patrons[i] << " ";
        cout << endl;
    }
};
int main() {
    LibraryQueue q;
    int choice;
    string name;

    cout << "===== Library Queue Simulation =====\n";

    do {
        cout << "\n1. Add Patron to Queue";
        cout << "\n2. Serve Patron";
        cout << "\n3. Display Queue";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter patron name: ";
            cin >> name;
            q.addPatron(name);
            break;

        case 2:
            q.servePatron();
            break;

        case 3:
            q.displayQueue();
            break;

        case 4:
            cout << "Exiting simulation...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}

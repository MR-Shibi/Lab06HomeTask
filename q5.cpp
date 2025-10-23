#include <iostream>
using namespace std;

#define SIZE 10

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    bool isFull() {
        return (rear == SIZE - 1);
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is full! Cannot add customer " << val << endl;
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = val;
        cout << "Customer " << val << " entered the line.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No customers to serve!\n";
            return;
        }
        cout << "Customer " << arr[front++] << " has been served.\n";
    }

    void display() {
        if (isEmpty()) {
            cout << "No customers in queue.\n";
            return;
        }
        cout << "\nCurrent Queue (Front → Rear): ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    Queue q;

    int customers[] = {13, 7, 4, 1, 6, 8, 10};
    int n = sizeof(customers) / sizeof(customers[0]);
    for (int i = 0; i < n; i++)
        q.enqueue(customers[i]);

    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    return 0;
}

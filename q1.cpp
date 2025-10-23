#include <iostream>
using namespace std;

#define MAX 10

class Stack {
    string arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(string item) {
        if (isFull()) {
            cout << "Stack is full! Cannot add more tasks.\n";
            return;
        }
        arr[++top] = item;
        cout << "Added task: " << item << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "No task to remove!\n";
            return;
        }
        cout << "Removed top task: " << arr[top--] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "No tasks available.\n";
            return;
        }
        cout << "\nCurrent To-Do List (Top to Bottom):\n";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << endl;
    }
};

int main() {
    Stack todo;
    todo.push("Complete Project Report");
    todo.push("Email Client");
    todo.push("Attend Meeting");
    todo.display();
    todo.pop();
    if (todo.isEmpty())
        cout << "To-do list is empty.\n";
    else
        cout << "Tasks still remaining.\n";

    return 0;
}

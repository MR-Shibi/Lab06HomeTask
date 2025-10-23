#include <iostream>
#include <string>
using namespace std;
class Stack {
    string arr[10];
    int top;
public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }

    void push(string val) {
        if (top == 9) {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = val;
    }

    string pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return "";
        }
        return arr[top--];
    }

    string peek() {
        if (isEmpty()) return "";
        return arr[top];
    }
};
struct Node {
    string url;
    Node* next;
    Node(string u) : url(u), next(NULL) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() { head = NULL; }

    void insertFront(string url) {
        Node* newNode = new Node(url);
        newNode->next = head;
        head = newNode;
    }

    void removeFront() {
        if (head == NULL) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void display() {
        Node* temp = head;
        cout << "\nBrowsing History (Most recent first):\n";
        while (temp != NULL) {
            cout << temp->url << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
int main() {
    Stack historyStack;
    LinkedList historyList;
    string sites[] = {"Google", "Facebook", "Twitter", "LinkedIn", "Instagram"};
    for (int i = 0; i < 5; i++) {
        historyStack.push(sites[i]);
        historyList.insertFront(sites[i]);
    }

    cout << "\nBefore clicking BACK:\n";
    historyList.display();
    cout << "\nUser clicks BACK twice...\n";
    for (int i = 0; i < 2; i++) {
        string lastSite = historyStack.pop();
        cout << "Going back from: " << lastSite << endl;
        historyList.removeFront();
    }

    cout << "\nAfter clicking BACK twice:\n";
    historyList.display();

    cout << "\nCurrently viewing: " << historyStack.peek() << endl;

    return 0;
}

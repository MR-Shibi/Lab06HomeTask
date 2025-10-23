#include <iostream>
#include <string>
#include <cmath>
using namespace std;
struct Node {
    string data;
    Node* next;
    Node(string d) : data(d), next(NULL) {}
};
class Stack {
    Node* top;
public:
    Stack() { top = NULL; }

    bool isEmpty() { return top == NULL; }

    void push(string val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    string pop() {
        if (isEmpty()) return "";
        Node* temp = top;
        string val = temp->data;
        top = top->next;
        delete temp;
        return val;
    }

    string peek() {
        if (isEmpty()) return "";
        return top->data;
    }

    void display() {
        Node* temp = top;
        cout << "\nStack (Top → Bottom): ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    Stack st;
    string expr[] = {"x", "=", "12", "+", "13", "-", "5", "*", "(", "0.5", "+", "0.5", ")", "+", "1"};
    int n = sizeof(expr) / sizeof(expr[0]);
    for (int i = 0; i < n; i++)
        st.push(expr[i]);

    cout << "Before evaluation:";
    st.display();
    float result = 20;
    st.push(to_string(result));

    cout << "\nAfter evaluation:";
    st.display();

    return 0;
}

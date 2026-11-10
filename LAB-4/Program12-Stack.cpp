#include <iostream>
using namespace std;

const int MAX = 100;

class StaticStack {
private:
    int arr[MAX];
    int top;

public:
    StaticStack() { top = -1; }

    void push(int val) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = val;
    }

    void pop() {
        if (top < 0) {
            cout << "Stack Underflow!\n";
            return;
        }
        top--;
    }

    int peek() {
        if (top < 0) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top < 0;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    StaticStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Static Stack after pushes: ";
    s.display();

    s.pop();
    cout << "Static Stack after pop: ";
    s.display();

    return 0;
}
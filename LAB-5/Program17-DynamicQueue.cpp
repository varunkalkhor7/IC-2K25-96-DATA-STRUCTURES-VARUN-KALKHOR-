#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class DynamicQueue {
private:
    Node* front;
    Node* rear;

public:
    DynamicQueue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    int peek() {
        if (isEmpty()) return -1;
        return front->data;
    }

    void display() {
        Node* temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    DynamicQueue q;
    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(300);
    cout << "Dynamic Queue: ";
    q.display();
    q.dequeue();
    cout << "After dequeue: ";
    q.display();
    return 0;
}
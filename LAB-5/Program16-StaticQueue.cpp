#include <iostream>
using namespace std;

const int MAX = 100;

class StaticQueue {
private:
    int arr[MAX];
    int front, rear;

public:
    StaticQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue Overflow!\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = val;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return;
        }
        front++;
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }

    int peek() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    StaticQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Static Queue: ";
    q.display();
    q.dequeue();
    cout << "After dequeue: ";
    q.display();
    return 0;
}
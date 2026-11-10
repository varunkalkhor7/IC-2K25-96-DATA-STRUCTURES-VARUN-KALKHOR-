#include <iostream>
using namespace std;

const int MAX = 5;

class CircularQueue {
private:
    int arr[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1));
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue Overflow!\n";
            return;
        }
        if (front == -1) {
            front = rear = 0;
        } else if (rear == MAX - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = val;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == MAX - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        if (rear >= front) {
            for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        } else {
            for (int i = front; i < MAX; i++) cout << arr[i] << " ";
            for (int i = 0; i <= rear; i++) cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout << "Circular Queue: ";
    q.display();
    q.dequeue();
    q.dequeue();
    q.enqueue(60);
    q.enqueue(70);
    cout << "After operations: ";
    q.display();
    return 0;
}
#include <iostream>
using namespace std;

const int MAX = 100;

class Deque {
private:
    int arr[MAX];
    int front, rear;

public:
    Deque() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (front == 0 && rear == MAX - 1) || (front == rear + 1);
    }

    void insertFront(int val) {
        if (isFull()) {
            cout << "Overflow!\n";
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (front == 0) {
            front = MAX - 1;
        } else {
            front--;
        }
        arr[front] = val;
    }

    void insertRear(int val) {
        if (isFull()) {
            cout << "Overflow!\n";
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == MAX - 1) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = val;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Underflow!\n";
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

    void deleteRear() {
        if (isEmpty()) {
            cout << "Underflow!\n";
            return;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (rear == 0) {
            rear = MAX - 1;
        } else {
            rear--;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << "\n";
    }
};

int main() {
    Deque dq;
    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    cout << "Deque: ";
    dq.display();
    dq.deleteFront();
    cout << "After delete front: ";
    dq.display();
    dq.deleteRear();
    cout << "After delete rear: ";
    dq.display();
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int data;
    int priority;
};

class ArrayPriorityQueue {
private:
    vector<Item> arr;

public:
    void enqueue(int val, int priority) {
        arr.push_back({val, priority});
    }

    void dequeue() {
        if (arr.empty()) {
            cout << "Queue is empty!\n";
            return;
        }
        int highestPriorityIndex = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i].priority > arr[highestPriorityIndex].priority) {
                highestPriorityIndex = i;
            }
        }
        arr.erase(arr.begin() + highestPriorityIndex);
    }

    void display() {
        for (auto& item : arr) {
            cout << "[" << item.data << ", P:" << item.priority << "] ";
        }
        cout << "\n";
    }
};

int main() {
    ArrayPriorityQueue pq;
    pq.enqueue(10, 1);
    pq.enqueue(30, 3);
    pq.enqueue(20, 2);
    cout << "Array-based Priority Queue: ";
    pq.display();
    pq.dequeue();
    cout << "After dequeue highest priority: ";
    pq.display();
    return 0;
}
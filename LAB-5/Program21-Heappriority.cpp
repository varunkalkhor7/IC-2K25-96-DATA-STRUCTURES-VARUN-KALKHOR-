#include <iostream>
#include <vector>
using namespace std;

class HeapPriorityQueue {
private:
    vector<int> heap;

    void siftUp(int i) {
        while (i > 0) {
            int p = (i - 1) / 2;
            if (heap[i] > heap[p]) {
                swap(heap[i], heap[p]);
                i = p;
            } else {
                break;
            }
        }
    }

    void siftDown(int i) {
        int maxIndex = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < heap.size() && heap[l] > heap[maxIndex]) maxIndex = l;
        if (r < heap.size() && heap[r] > heap[maxIndex]) maxIndex = r;
        if (i != maxIndex) {
            swap(heap[i], heap[maxIndex]);
            siftDown(maxIndex);
        }
    }

public:
    void enqueue(int val) {
        heap.push_back(val);
        siftUp(heap.size() - 1);
    }

    void dequeue() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) siftDown(0);
    }

    int peek() {
        if (heap.empty()) return -1;
        return heap[0];
    }

    void display() {
        for (int val : heap) cout << val << " ";
        cout << "\n";
    }
};

int main() {
    HeapPriorityQueue hpq;
    hpq.enqueue(10);
    hpq.enqueue(50);
    hpq.enqueue(20);
    hpq.enqueue(30);
    cout << "Heap-based Max Priority Queue: ";
    hpq.display();
    hpq.dequeue();
    cout << "After dequeue max: ";
    hpq.display();
    return 0;
}
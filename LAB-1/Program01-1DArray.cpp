#include <iostream>
using namespace std;

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void insert(int arr[], int &n, int capacity, int val, int pos) {
    if (n >= capacity || pos < 0 || pos > n) {
        cout << "Invalid insertion!\n";
        return;
    }
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    n++;
}

void deletion(int arr[], int &n, int pos) {
    if (pos < 0 || pos >= n) {
        cout << "Invalid deletion position!\n";
        return;
    }
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

int search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}

void rotateRight(int arr[], int n, int k) {
    if (n <= 0) return;
    k = k % n;
    int temp[100];
    for (int i = 0; i < n; i++) {
        temp[(i + k) % n] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int n = 5;

    cout << "Original 1D Array:\n";
    display(arr, n);

    insert(arr, n, 100, 25, 2);
    cout << "After inserting 25 at index 2:\n";
    display(arr, n);

    deletion(arr, n, 3);
    cout << "After deleting element at index 3:\n";
    display(arr, n);

    int idx = search(arr, n, 40);
    cout << "Element 40 found at index: " << idx << "\n";

    rotateRight(arr, n, 2);
    cout << "After rotating right by 2 positions:\n";
    display(arr, n);

    return 0;
}
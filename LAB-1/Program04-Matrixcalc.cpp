#include <iostream>
using namespace std;

void display(int mat[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}

void add(int a[2][2], int b[2][2], int res[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            res[i][j] = a[i][j] + b[i][j];
        }
    }
}

int main() {
    int a[2][2] = {{1, 2}, {3, 4}};
    int b[2][2] = {{5, 6}, {7, 8}};
    int res[2][2];

    add(a, b, res);

    cout << "Matrix A:\n";
    display(a);
    
    cout << "Matrix B:\n";
    display(b);
    
    cout << "Result (Sum):\n";
    display(res);

    return 0;
}
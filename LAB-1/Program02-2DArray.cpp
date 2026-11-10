#include <iostream>
using namespace std;

const int MAX = 10;

void display(int mat[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << "\n";
    }
}

void search(int mat[MAX][MAX], int r, int c, int key) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] == key) {
                cout << "Element " << key << " found at position (" << i << ", " << j << ")\n";
                return;
            }
        }
    }
    cout << "Element " << key << " not found!\n";
}

void rotate90(int mat[MAX][MAX], int &r, int &c) {
    int temp[MAX][MAX];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            temp[j][r - 1 - i] = mat[i][j];
        }
    }
    int oldR = r;
    r = c;
    c = oldR;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            mat[i][j] = temp[i][j];
        }
    }
}

void insertRow(int mat[MAX][MAX], int &r, int c, int rowArr[], int pos) {
    if (pos < 0 || pos > r || r >= MAX) {
        cout << "Invalid row insertion!\n";
        return;
    }
    for (int i = r; i > pos; i--) {
        for (int j = 0; j < c; j++) {
            mat[i][j] = mat[i - 1][j];
        }
    }
    for (int j = 0; j < c; j++) {
        mat[pos][j] = rowArr[j];
    }
    r++;
}

void deleteRow(int mat[MAX][MAX], int &r, int c, int pos) {
    if (pos < 0 || pos >= r) {
        cout << "Invalid row deletion!\n";
        return;
    }
    for (int i = pos; i < r - 1; i++) {
        for (int j = 0; j < c; j++) {
            mat[i][j] = mat[i + 1][j];
        }
    }
    r--;
}

int main() {
    int mat[MAX][MAX] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int r = 3, c = 3;

    cout << "Original 2D Matrix:\n";
    display(mat, r, c);

    search(mat, r, c, 5);

    int newRow[3] = {99, 99, 99};
    insertRow(mat, r, c, newRow, 1);
    cout << "After inserting new row at index 1:\n";
    display(mat, r, c);

    deleteRow(mat, r, c, 2);
    cout << "After deleting row at index 2:\n";
    display(mat, r, c);

    rotate90(mat, r, c);
    cout << "After rotating 90 degrees clockwise:\n";
    display(mat, r, c);

    return 0;
}
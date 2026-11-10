#include <iostream>
using namespace std;

struct Element {
    int row;
    int col;
    int val;
};

struct SparseMatrix {
    int rows;
    int cols;
    int nonZero;
    Element data[100];
};

void createSparse(SparseMatrix &s, int mat[10][10], int r, int c) {
    s.rows = r;
    s.cols = c;
    s.nonZero = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] != 0) {
                s.data[s.nonZero].row = i;
                s.data[s.nonZero].col = j;
                s.data[s.nonZero].val = mat[i][j];
                s.nonZero++;
            }
        }
    }
}

void displaySparse(const SparseMatrix &s) {
    cout << "Row\tCol\tValue\n";
    for (int i = 0; i < s.nonZero; i++) {
        cout << s.data[i].row << "\t" << s.data[i].col << "\t" << s.data[i].val << "\n";
    }
}

SparseMatrix transpose(const SparseMatrix &s) {
    SparseMatrix t;
    t.rows = s.cols;
    t.cols = s.rows;
    t.nonZero = s.nonZero;

    if (t.nonZero > 0) {
        int k = 0;
        for (int i = 0; i < s.cols; i++) {
            for (int j = 0; j < s.nonZero; j++) {
                if (s.data[j].col == i) {
                    t.data[k].row = s.data[j].col;
                    t.data[k].col = s.data[j].row;
                    t.data[k].val = s.data[j].val;
                    k++;
                }
            }
        }
    }
    return t;
}

int main() {
    int mat[10][10] = {
        {0, 0, 5},
        {0, 0, 0},
        {3, 0, 0}
    };
    int r = 3, c = 3;

    SparseMatrix s;
    createSparse(s, mat, r, c);

    cout << "Sparse Matrix (Triple Format):\n";
    displaySparse(s);

    SparseMatrix t = transpose(s);
    cout << "\nTranspose of Sparse Matrix:\n";
    displaySparse(t);

    return 0;
}
#include <iostream>
using namespace std;

void transposeRec(int** mat, int** trans, int i, int j, int rows, int cols) {
    if (i == rows)
        return;
    if (j == cols) {
        transposeRec(mat, trans, i + 1, 0, rows, cols);
        return;
    }
    trans[j][i] = mat[i][j];
    transposeRec(mat, trans, i, j + 1, rows, cols);
}

int main() {
    int rows, cols;
    cout << "\nEnter number of rows: ";
    cin >> rows;
    cout << "\nEnter number of columns: ";
    cin >> cols;

    int** mat = new int*[rows];
    int** trans = new int*[cols];
    for (int i = 0; i < rows; i++)
        mat[i] = new int[cols];
    for (int i = 0; i < cols; i++)
        trans[i] = new int[rows];

    cout << "\nEnter elements of the matrix:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++){
        	cout << "\nEnter element ["<<i<<"]["<<j<<"] : ";
            cin >> mat[i][j];
		}
    transposeRec(mat, trans, 0, 0, rows, cols);

    cout << "\nTranspose of the matrix:\n";
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++)
            cout << trans[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < rows; i++)
        delete[] mat[i];
    for (int i = 0; i < cols; i++)
        delete[] trans[i];
    delete[] mat;
    delete[] trans;
}

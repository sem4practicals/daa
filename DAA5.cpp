#include <iostream>
using namespace std;
int** multiplyMatrices(int** arr, int** brr, int n) {
    int** res = new int*[n];
    for(int i = 0; i < n; i++) {
        res[i] = new int[n]{0};
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                res[i][j] += arr[i][k] * brr[k][j];
            }
        }
    }
    return res;
}
void printMatrix(int** mat, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
void freeMatrix(int** mat, int n) {
    for(int i = 0; i < n; i++) {
        delete[] mat[i];
    }
    delete[] mat;
}
int main() {
    int n;
    cout << "Enter matrix size (n x n): ";
    cin >> n;
    int** arr = new int*[n];
    int** brr = new int*[n];
    cout << "Enter first matrix:" << endl;
    for(int i = 0; i < n; i++) {
        arr[i] = new int[n];
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    cout << "Enter second matrix:" << endl;
    for(int i = 0; i < n; i++) {
        brr[i] = new int[n];
        for(int j = 0; j < n; j++) {
            cin >> brr[i][j];
        }
    }
    int** res = multiplyMatrices(arr, brr, n);
    cout << "Result:" << endl;
    printMatrix(res, n);
    freeMatrix(arr, n);
    freeMatrix(brr, n);
    freeMatrix(res, n);
    return 0;
}

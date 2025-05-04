#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef vector<vector<int>> Matrix;

Matrix standardMatrixMultiply(const Matrix& A, const Matrix& B) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int colsB = B[0].size();
    
    Matrix C(rowsA, vector<int>(colsB, 0));
    
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    return C;
}

int nextPowerOfTwo(int n) {
    return n <= 1 ? 1 : pow(2, ceil(log2(n)));
}

Matrix padMatrix(const Matrix& A, int size) {
    int n = A.size();
    int m = A[0].size();
    
    Matrix padded(size, vector<int>(size, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            padded[i][j] = A[i][j];
        }
    }
    
    return padded;
}

Matrix unpadMatrix(const Matrix& A, int rows, int cols) {
    Matrix result(rows, vector<int>(cols, 0));
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j];
        }
    }
    
    return result;
}

Matrix add(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    
    return C;
}

Matrix subtract(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    
    return C;
}

Matrix strassenMultiplySquare(const Matrix& A, const Matrix& B) {
    int n = A.size();
    
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }
    
    int mid = n / 2;
    
    Matrix A11(mid, vector<int>(mid, 0));
    Matrix A12(mid, vector<int>(mid, 0));
    Matrix A21(mid, vector<int>(mid, 0));
    Matrix A22(mid, vector<int>(mid, 0));
    
    Matrix B11(mid, vector<int>(mid, 0));
    Matrix B12(mid, vector<int>(mid, 0));
    Matrix B21(mid, vector<int>(mid, 0));
    Matrix B22(mid, vector<int>(mid, 0));
    
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];
            
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }
    
    Matrix P1 = strassenMultiplySquare(add(A11, A22), add(B11, B22));
    Matrix P2 = strassenMultiplySquare(add(A21, A22), B11);
    Matrix P3 = strassenMultiplySquare(A11, subtract(B12, B22));
    Matrix P4 = strassenMultiplySquare(A22, subtract(B21, B11));
    Matrix P5 = strassenMultiplySquare(add(A11, A12), B22);
    Matrix P6 = strassenMultiplySquare(subtract(A21, A11), add(B11, B12));
    Matrix P7 = strassenMultiplySquare(subtract(A12, A22), add(B21, B22));
    
    Matrix C11 = add(subtract(add(P1, P4), P5), P7);
    Matrix C12 = add(P3, P5);
    Matrix C21 = add(P2, P4);
    Matrix C22 = add(subtract(add(P1, P3), P2), P6);
    
    Matrix C(n, vector<int>(n, 0));
    
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            C[i][j] = C11[i][j];
            C[i][j + mid] = C12[i][j];
            C[i + mid][j] = C21[i][j];
            C[i + mid][j + mid] = C22[i][j];
        }
    }
    
    return C;
}

Matrix strassenMultiply(const Matrix& A, const Matrix& B) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int rowsB = B.size();
    int colsB = B[0].size();
    
    if (colsA != rowsB) {
        cout << "Incompatible matrix dimensions!" << endl;
        return {};
    }
    
    int maxDim = max(max(rowsA, colsA), max(rowsB, colsB));
    int n = nextPowerOfTwo(maxDim);
    
    if (n <= 64) {
        return standardMatrixMultiply(A, B);
    }
    
    Matrix paddedA = padMatrix(A, n);
    Matrix paddedB = padMatrix(B, n);
    
    Matrix paddedC = strassenMultiplySquare(paddedA, paddedB);
    
    return unpadMatrix(paddedC, rowsA, colsB);
}

void printMatrix(const Matrix& A) {
    for (const auto& row : A) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    int rowsA, colsA, rowsB, colsB;
    
    cout << "Enter dimensions of first matrix (rows columns): ";
    cin >> rowsA >> colsA;
    
    Matrix A(rowsA, vector<int>(colsA));
    cout << "Enter elements of first matrix:" << endl;
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            cin >> A[i][j];
        }
    }
    
    cout << "Enter dimensions of second matrix (rows columns): ";
    cin >> rowsB >> colsB;
    
    if (colsA != rowsB) {
        cout << "Incompatible matrix dimensions for multiplication!" << endl;
        return 1;
    }
    
    Matrix B(rowsB, vector<int>(colsB));
    cout << "Enter elements of second matrix:" << endl;
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            cin >> B[i][j];
        }
    }
    
    Matrix C = strassenMultiply(A, B);
    
    cout << "Resultant matrix:" << endl;
    printMatrix(C);
    
    return 0;
}

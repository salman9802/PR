#include <stdio.h>

// Function to add two matrices
void matrixAddition(int n, int A[][n], int B[][n], int C[][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Function to subtract two matrices
void matrixSubtraction(int n, int A[][n], int B[][n], int C[][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// Function to multiply two matrices using Strassen's algorithm
void strassenMultiply(int n, int A[][n], int B[][n], int C[][n]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = n / 2;

    // Creating submatrices
    int A11[newSize][newSize], A12[newSize][newSize], A21[newSize][newSize], A22[newSize][newSize];
    int B11[newSize][newSize], B12[newSize][newSize], B21[newSize][newSize], B22[newSize][newSize];
    int C11[newSize][newSize], C12[newSize][newSize], C21[newSize][newSize], C22[newSize][newSize];
    int temp1[newSize][newSize], temp2[newSize][newSize];
    int M1[newSize][newSize],
        M2[newSize][newSize],
        M3[newSize][newSize],
        M4[newSize][newSize],
        M5[newSize][newSize],
        M6[newSize][newSize],
        M7[newSize][newSize];

    // Divide matrices into submatrices
    for (int i = 0; i < newSize; i++)
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }

    /** 
        M1 = (A11 + A22)(B11 + B22)
        M2 = (A21 + A22) B11
        M3 = A11 (B12 - B22)
        M4 = A22 (B21 - B11)
        M5 = (A11 + A12) B22
        M6 = (A21 - A11) (B11 + B12)
        M7 = (A12 - A22) (B21 + B22)
    **/

    // Calculating seven products
    
    // M1 = (A11 + A22)(B11 + B22)
    matrixAddition(newSize, A11, A22, temp1);
    matrixAddition(newSize, B11, B22, temp2);
    strassenMultiply(newSize, temp1, temp2, M1);

    // M2 = (A21 + A22) B11
    matrixAddition(newSize, A21, A22, temp1);
    strassenMultiply(newSize, temp1, B11, M2);

    // M3 = A11 (B12 - B22)
    matrixSubtraction(newSize, B12, B22, temp1);
    strassenMultiply(newSize, A11, temp1, M3);

    // M4 = A22 (B21 - B11)
    matrixSubtraction(newSize, B21, B11, temp1);
    strassenMultiply(newSize, A22, temp1, M4);

    // M5 = (A11 + A12) B22
    matrixAddition(newSize, A11, A12, temp1);
    strassenMultiply(newSize, temp1, B22, M5);

    // M6 = (A21 - A11) (B11 + B12)
    matrixSubtraction(newSize, A21, A11, temp1);
    matrixAddition(newSize, B11, B12, temp2);
    strassenMultiply(newSize, temp1, temp2, M6);

    // M7 = (A12 - A22) (B21 + B22)
    matrixSubtraction(newSize, A12, A22, temp1);
    matrixAddition(newSize, B21, B22, temp2);
    strassenMultiply(newSize, temp1, temp2, M7);


    /**
        C11 = M1 + M4 - M5 + M7
        C12 = M3 + M5
        C21 = M2 + M4
        C22 = M1 - M2 + M3 + M6
    **/
   
    // C11 = M1 + M4 - M5 + M7
    // matrixAddition(newSize, M1, M4, temp1);
    // matrixAddition(newSize, M5, M7, temp2);
    // matrixSubtraction(newSize, temp1, temp2, C11);

    matrixAddition(newSize, M1, M4, temp1);
    matrixSubtraction(newSize, temp1, M5, temp2);
    matrixAddition(newSize, temp2, M7, C11);


    // C12 = M3 + M5
    matrixAddition(newSize, M3, M5, C12);

    // C21 = M2 + M4
    matrixAddition(newSize, M2, M4, C21);

    // C22 = M1 - M2 + M3 + M6
    // matrixAddition(newSize, M2, M3, temp1);
    // matrixAddition(newSize, temp1, M6, temp2);
    // matrixSubtraction(newSize, M1, temp2, C22);

    matrixAddition(newSize, M1, M3, temp1);
    matrixSubtraction(newSize, temp1, M2, temp2);
    matrixAddition(newSize, temp2, M6, C22);


    // Combining results
    for (int i = 0; i < newSize; i++)
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
}

// Function to print a matrix
void printMatrix(int n, int matrix[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Example matrices
    int A[2][2] = {{2, 3}, {4, 5}};
    int B[2][2] = {{1, 0}, {7, 6}};
    int C[2][2] = {{0}};

    // Size of matrices
    int n = 2;

    // Calling Strassen's multiplication function
    strassenMultiply(n, A, B, C);

    // Displaying the result
    printf("Matrix A:\n");
    printMatrix(n, A);

    printf("\nMatrix B:\n");
    printMatrix(n, B);

    printf("\nResultant Matrix C (A * B):\n");
    printMatrix(n, C);

    return 0;
}
/* Output:
Matrix A:
2	3	
4	5	

Matrix B:
1	0	
7	6	

Resultant Matrix C (A * B):
23	18	
39	30	
*/
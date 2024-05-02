// Write a program in C/C++/ Java to find Minimum number of multiplications in Matrix Chain Multiplication

#include<stdio.h>
#include<limits.h>

// Function to find the minimum number of multiplications in Matrix Chain Multiplication
int matrix_chain_mul(int dims[], int n) {
    int m[n][n], i, j, k, L, cost;

    //  cost is 0 when multiplying one matrix (diagonals of table)
    for(i = 1; i < n; i++) m[i][i] = 0;

    // L is chain length
    // i is starting index of chain
    // j is ending index of chain
    for(L = 2; L < n; L++) {
        for(i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for(k = i; k <= j - 1; k++) {
                cost = m[i][k] + m[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if(cost < m[i][j]) m[i][j] = cost;
            }
        }
    }

    return m[1][n - 1];
}


int main() {
    int dims[] = {10, 20, 30, 40, 30}; // Matrix dimensions: 10x20, 20x30, 30x40, 40x30
    int n = sizeof(dims) / sizeof(dims[0]);

    printf("Minimum number of multiplications is %d\n", matrix_chain_mul(dims, n));

    return 0;
}
/* Minimum number of multiplications is 30000 */
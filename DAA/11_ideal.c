Sure, here's a C program to find the minimum number of multiplications in Matrix Chain Multiplication using dynamic programming:

```c
#include <stdio.h>
#include <limits.h>

// Function to find the minimum number of multiplications in Matrix Chain Multiplication
int matrixChainOrder(int p[], int n) {
    int m[n][n];

    // Cost is 0 when multiplying one matrix
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // L is the chain length
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }
    return m[1][n - 1];
}

int main() {
    int arr[] = {10, 20, 30, 40, 30}; // Matrix dimensions: 10x20, 20x30, 30x40, 40x30
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Minimum number of multiplications is %d\n", matrixChainOrder(arr, n));

    return 0;
}
```

This program computes the minimum number of multiplications needed to multiply a chain of matrices with given dimensions. It uses dynamic programming to solve the problem efficiently.

The time complexity of this program is \(O(n^3)\), where \(n\) is the number of matrices. This is because of the three nested loops used to fill in the `m` table.

***************************************************************************************

Certainly! Let's break down the dynamic programming part of the program:

1. **Initialization**: 
   - The outer loop `for (int L = 2; L < n; L++)` iterates over chain lengths from 2 to `n-1`. 
   - The inner loop `for (int i = 1; i < n - L + 1; i++)` iterates over the start index of the chain.

2. **Loop Variables**:
   - `L`: Represents the length of the chain of matrices being considered. 
   - `i`: Represents the starting index of the chain.
   - `j`: Represents the ending index of the chain, which is `i + L - 1`.

3. **Cost Calculation**:
   - For a chain of matrices starting at index `i` and ending at index `j`, the program computes the minimum cost (`m[i][j]`) of multiplying this chain.
   - It iterates over all possible positions `k` where the chain can be split into two sub-chains: `i` to `k` and `k+1` to `j`.
   - The cost of multiplying these sub-chains together is calculated as `m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]`, where `p[]` contains the dimensions of the matrices.

4. **Minimum Cost Update**:
   - The calculated cost is compared with the current minimum cost stored in `m[i][j]`.
   - If the calculated cost is less than the current minimum cost, the `m[i][j]` value is updated with the new cost.

5. **Optimal Substructure Property**:
   - The optimal cost for multiplying a chain of matrices is determined by considering the optimal costs of multiplying smaller sub-chains.

6. **Final Result**:
   - The minimum number of multiplications needed to multiply all matrices is stored at `m[1][n-1]`.

This approach ensures that each subproblem is solved only once, leading to an efficient solution with a time complexity of \(O(n^3)\), where \(n\) is the number of matrices.
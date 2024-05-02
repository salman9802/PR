// Write a program in C/C++/ Java to implement optimal binary search tree and also calculate the best case and worst case complexity.
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// Utility function to get sum of frequencies from freq[i] to freq[j]
int sum(int freq[], int i, int j) {
    int s = 0, k;
    for(k = i; k <= j; k++) s += freq[k];
    return s;
}

int optimal_search_tree_cost(int keys[], int freq[], int n) {
    // Create an auxiliary 2D table to store results of subproblems
    int cost[n][n], L, i, j, r;

    // For a single key, the cost is equal to its frequency
    for(i = 0; i < n; i++) cost[i][i] = freq[i];

    // Now, we need to consider chains of increasing lengths
    // Starting from chain length 2
    for(L = 2; L <= n; L++) {
        /*  x y z . . . n-1

            x . . . y |z| |n-1|
                      |i|  |j|  for L = 2

        */
        // For each chain of length L, we loop through all possible starting points i
        for(i = 0; i <= n - L + 1; i++) {
            j = i + L - 1; // Get ending point of the chain

            // Initialize cost of sub-tree is infinity (from keys[i] to keys[j])
            cost[i][j] = INT_MAX;

            // Try making all keys in interval keys[i..j] as root one by one
            for(r = i; r <= j; r++){
                // Cost when keys[r] becomes root of this subtree
                int c = ((r > i) ? cost[i][r-1] : 0) + ((r < j) ? cost[r+1][j] : 0) + sum(freq, i, j);
                if(c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }

    // Return the optimal cost from the entire range
    return cost[0][n - 1];
}

int main() {
    int keys[] = {10, 20, 30, 40};
    int freq[] = {4, 2, 6, 3};
    int n = sizeof(keys) / sizeof(keys[0]);

    printf("Optimal Cost of Binary Search Tree is: %d\n", optimal_search_tree_cost(keys, freq, n));

    return 0;
}
/* Optimal Cost of Binary Search Tree is: 26 */
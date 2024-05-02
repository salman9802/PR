// Write a program in C/C++/ Java to implement optimal binary search tree and also calculate the best case and worst case complexity.
#include <stdio.h>
#include <limits.h>

// Utility function to get sum of frequencies from freq[i] to freq[j]
int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++)
        s += freq[k];
    return s;
}

// Function to find optimal binary search tree cost
int optimalSearchTreeCost(int keys[], int freq[], int n) {
    // Create an auxiliary 2D table to store results of subproblems
    int cost[n][n];

    // For a single key, the cost is equal to its frequency
    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];

    // Now, we need to consider chains of increasing lengths
    // Starting from chain length 2
    for (int L = 2; L <= n; L++) {
        // For each chain of length L, we loop through all possible starting points i
        for (int i = 0; i <= n - L + 1; i++) {
            int j = i + L - 1; // Get ending point of the chain

            // Initialize cost of sub-tree from keys[i] to keys[j]
            cost[i][j] = INT_MAX;

            // Try making all keys in interval keys[i..j] as root one by one
            for (int r = i; r <= j; r++) {
                // Cost when keys[r] becomes root of this subtree
                int c = ((r > i) ? cost[i][r - 1] : 0) + ((r < j) ? cost[r + 1][j] : 0) + sum(freq, i, j);
                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }

    // Return the optimal cost from the entire range
    return cost[0][n - 1];
}

int main() {
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys) / sizeof(keys[0]);

    printf("Optimal Cost of Binary Search Tree is: %d\n", optimalSearchTreeCost(keys, freq, n));

    return 0;
}
/* This program calculates the optimal cost of a binary search tree given a set of keys and their corresponding frequencies. It utilizes dynamic programming to find the optimal cost.

The best-case complexity of this algorithm is O(n^2), and the worst-case complexity is also O(n^2), where n is the number of keys. This is because the algorithm uses a nested loop that iterates over each possible chain length and each possible starting point, resulting in a quadratic time complexity. */
Implementing the Traveling Salesman Problem (TSP) using the Branch and Bound approach in C involves several steps. Here's a basic outline of how you can do it:

1. **Input the graph**: Take input as a weighted adjacency matrix representing the distances between each pair of cities.

2. **Initialize variables**: Initialize variables to keep track of the minimum cost, visited cities, and the current path.

3. **Branch and Bound Algorithm**:
   - Start from the source city (let's say city 0).
   - Create a priority queue (min-heap) to store partial solutions (partial paths) sorted by their lower bound (minimum possible cost).
   - Initialize the priority queue with the source city.
   - While the priority queue is not empty:
     - Extract the minimum-cost partial solution from the priority queue.
     - If the partial solution represents a complete path (all cities visited), update the minimum cost if it's better than the current minimum.
     - Otherwise, generate child partial solutions by adding unvisited cities to the current path. Calculate the lower bound for each child and add them to the priority queue.
   - Continue until all partial solutions are explored.

4. **Output**: Print the minimum cost and the optimal path.

Below is a basic implementation of the Branch and Bound algorithm for the TSP in C:

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define N 4 // Number of cities

// Function to find the minimum of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to calculate the lower bound of a partial solution
int calculateLowerBound(int graph[N][N], bool visited[N], int current) {
    int lb = 0;
    // Add the minimum edge cost from the current city to any unvisited city
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            int minCost = INT_MAX;
            for (int j = 0; j < N; j++) {
                if (graph[current][j] && !visited[j]) {
                    minCost = min(minCost, graph[current][j]);
                }
            }
            lb += minCost;
        }
    }
    return lb;
}

// Function to perform Branch and Bound for TSP
void TSPBranchAndBound(int graph[N][N]) {
    // Initialize variables
    bool visited[N] = {false};
    visited[0] = true; // Start from city 0
    int minCost = INT_MAX;
    int currentPath[N];
    int currentWeight = 0;

    // Priority queue to store partial solutions
    // Each element contains the current city, path so far, and the lower bound
    // Here, we use a simple array instead of a priority queue for simplicity
    int priorityQueue[N * N][N + 2]; // Each element: city, path[], lower bound
    int queueSize = 0;

    // Initialize priority queue with the starting city
    priorityQueue[queueSize][0] = 0;
    priorityQueue[queueSize][1] = 0;
    priorityQueue[queueSize][N + 1] = 0;
    queueSize++;

    // Branch and Bound algorithm
    while (queueSize > 0) {
        // Extract the minimum-cost partial solution
        int minIndex = 0;
        for (int i = 1; i < queueSize; i++) {
            if (priorityQueue[i][N + 1] < priorityQueue[minIndex][N + 1]) {
                minIndex = i;
            }
        }
        int currentCity = priorityQueue[minIndex][0];
        currentWeight = priorityQueue[minIndex][N + 1];
        for (int i = 0; i < N; i++) {
            currentPath[i] = priorityQueue[minIndex][i + 1];
        }
        // Remove the extracted partial solution from the priority queue
        for (int i = minIndex; i < queueSize - 1; i++) {
            for (int j = 0; j < N + 2; j++) {
                priorityQueue[i][j] = priorityQueue[i + 1][j];
            }
        }
        queueSize--;

        // If the partial solution is a complete path
        if (currentCity == N - 1) {
            // Update the minimum cost if necessary
            if (currentWeight + graph[currentPath[N - 1]][0] < minCost) {
                minCost = currentWeight + graph[currentPath[N - 1]][0];
            }
        } else {
            // Generate child partial solutions by adding unvisited cities to the current path
            for (int i = 0; i < N; i++) {
                if (!visited[i] && graph[currentCity][i]) {
                    visited[i] = true;
                    currentPath[currentCity + 1] = i;
                    // Calculate the lower bound for the child partial solution
                    int lb = currentWeight + graph[currentCity][i] + calculateLowerBound(graph, visited, i);
                    // Add the child partial solution to the priority queue
                    priorityQueue[queueSize][0] = i;
                    for (int j = 0; j <= currentCity + 1; j++) {
                        priorityQueue[queueSize][j + 1] = currentPath[j];
                    }
                    priorityQueue[queueSize][N + 1] = lb;
                    queueSize++;
                    // Reset visited array for the next iteration
                    for (int j = 0; j < N; j++) {
                        visited[j] = (j == 0) ? true : false;
                    }
                }
            }
        }
    }

    // Output the result
    printf("Minimum cost: %d\n", minCost);
}

int main() {
    // Example graph represented as a weighted adjacency matrix
    int graph[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    // Find the solution for TSP using Branch and Bound
    TSPBranchAndBound(graph);

    return 0;
}
```

This program implements the Branch and Bound algorithm to solve the Traveling Salesman Problem (TSP). It takes an input weighted adjacency matrix representing the distances between cities and outputs the minimum cost of visiting all cities exactly once and returning to the starting city.
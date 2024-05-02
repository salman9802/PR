Sure, here's a C program to find out live nodes, E-nodes, and dead nodes from a given graph represented by an adjacency matrix:

```c
#include <stdio.h>
#include <stdbool.h>

#define V 5 // Number of vertices in the graph

// Function to find live nodes, E-nodes, and dead nodes from a given graph represented by an adjacency matrix
void findNodes(bool graph[V][V]) {
    bool visited[V];
    bool eNode[V];
    bool liveNode[V];

    // Initialize visited, E-node, and live node arrays
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        eNode[i] = true;
        liveNode[i] = false;
    }

    // Traverse the graph and mark visited nodes
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j]) {
                visited[j] = true;
                eNode[i] = false;
            }
        }
    }

    // Mark live nodes
    for (int i = 0; i < V; i++) {
        if (visited[i])
            liveNode[i] = true;
    }

    // Print live nodes
    printf("Live nodes: ");
    for (int i = 0; i < V; i++) {
        if (liveNode[i])
            printf("%d ", i);
    }
    printf("\n");

    // Print E-nodes
    printf("E-nodes: ");
    for (int i = 0; i < V; i++) {
        if (eNode[i])
            printf("%d ", i);
    }
    printf("\n");

    // Print dead nodes
    printf("Dead nodes: ");
    for (int i = 0; i < V; i++) {
        if (!liveNode[i])
            printf("%d ", i);
    }
    printf("\n");
}

int main() {
    // Example graph represented as an adjacency matrix
    bool graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    findNodes(graph);

    return 0;
}
```

This program traverses the given graph represented by an adjacency matrix and identifies live nodes, E-nodes, and dead nodes.

- **Live Node**: A node that has at least one outgoing edge.
- **E-node**: A node that has no outgoing edge.
- **Dead Node**: A node that is not reachable from any other node.

The time complexity of this program is \(O(V^2)\), where \(V\) is the number of vertices in the graph. This is because the program iterates through each cell of the adjacency matrix twice.
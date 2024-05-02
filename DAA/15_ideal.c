// To determine if a given graph is a Hamiltonian cycle or not, we need to verify whether it visits each vertex exactly once and returns to the starting vertex. Below is a C program to check if a given graph is a Hamiltonian cycle:

#include <stdio.h>
#include <stdbool.h>

#define V 5 // Number of vertices in the graph

// Function to check if vertex v can be added at position 'pos' in the path
bool isSafe(int v, bool graph[V][V], int path[], int pos) {
    // Check if the vertex has an edge to the previous vertex in the path
    if (!graph[path[pos - 1]][v])
        return false;

    // Check if the vertex is already in the path
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

// Function to recursively find Hamiltonian cycle starting from vertex 'pos'
bool hamiltonianCycleUtil(bool graph[V][V], int path[], int pos) {
    // If all vertices are included in the path, check if there is an edge from the last vertex to the first vertex
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]])
            return true;
        else
            return false;
    }

    // Try different vertices as the next vertex in the path
    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            // Recur to add the next vertex
            if (hamiltonianCycleUtil(graph, path, pos + 1))
                return true;
            // Backtrack if adding vertex 'v' doesn't lead to a solution
            path[pos] = -1;
        }
    }

    return false;
}

// Function to check if a Hamiltonian cycle exists in the graph
bool hamiltonianCycle(bool graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;

    // Start from vertex 0
    path[0] = 0;

    // Check if a Hamiltonian cycle exists starting from vertex 0
    if (!hamiltonianCycleUtil(graph, path, 1)) {
        printf("No Hamiltonian cycle exists\n");
        return false;
    }

    // Print the Hamiltonian cycle
    printf("Hamiltonian cycle exists: ");
    for (int i = 0; i < V; i++)
        printf("%d -> ", path[i]);
    printf("%d\n", path[0]);

    return true;
}

int main() {
    bool graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    hamiltonianCycle(graph);

    return 0;
}

// In this program:

// - The `isSafe` function checks if a vertex can be added at a given position in the Hamiltonian cycle.
// - The `hamiltonianCycleUtil` function recursively explores all possible Hamiltonian cycles starting from the first vertex.
// - The `hamiltonianCycle` function initializes the path with the starting vertex and checks if a Hamiltonian cycle exists.
// - If a Hamiltonian cycle is found, it prints the cycle; otherwise, it prints a message indicating that no Hamiltonian cycle exists.

// The time complexity of this program is exponential, \(O(V!)\), where \(V\) is the number of vertices in the graph. This is because the program explores all possible permutations of vertices to find a Hamiltonian cycle.
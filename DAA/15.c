// Write a program in C/C++/ Java to determine if a given graph is a Hamiltonian cycle or not 
#include<stdio.h>
#include<stdlib.h>

int V;

// Function to check if vertex v can be added at position 'pos' in the path
int is_safe(int v, int graph[V][V], int path[V], int pos) {
    int i;
    // Check if the vertex has an edge to the previous vertex in the path
    if(!graph[path[pos - 1]][v]) return 0;

    // Check if the vertex is already in the path
    for(i = 0; i < V; i++)
        if(path[i] == v) return 0;
    
    return 1;
}

// Function to recursively find Hamiltonian cycle starting from vertex 'pos'
int hamiltonian_cycle_util(int graph[V][V], int path[V], int pos) {
    int v;
    // if all vertices included in path, check if edge from last edge back to starting
    if(pos == V)
        if(graph[path[pos - 1]][path[0]])
            return 1;
        else return 0;
    
    // try different vertices as next in path
    for(v = 1; v < V; v++) {
        if(is_safe(v, graph, path, pos)) {
            path[pos] = v;
            
            // recursively add next vertex
            if(hamiltonian_cycle_util(graph, path, pos + 1))
                return 1;

            // Backtrack if adding vertex 'v' doesn't lead to a solution
            path[pos] = -1;
        }
    }

    return 0;
}

// Function to check if a Hamiltonian cycle exists in the graph
void hamiltonian_cycle(int graph[V][V]) {
    int path[V], i, j;

    for(i = 0; i < V; i++) path[i] = -1;

    // start from vertex 0
    path[0] = 0;

    // Check if a Hamiltonian cycle exists starting from vertex 0
    if(!hamiltonian_cycle_util(graph, path, 1)) {
        printf("Graph doesn't have hamiltonian cycle.");
        return;
    }

    // Print the Hamiltonian cycle
    printf("Hamiltonian cycle exists: ");
    for (int i = 0; i < V; i++)
        printf("%d -> ", path[i]);
    printf("%d\n", path[0]);
}

int main() {
    int i, j;
    printf("Enter number of vertices in the graph: ");
    scanf("%d", &V);

    int graph[V][V];
    printf("Enter adjacency matrix for the graph: ");
    for(i = 0; i < V; i++)
        for(j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    hamiltonian_cycle(graph);
    return 0;
}
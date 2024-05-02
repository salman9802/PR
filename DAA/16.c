// Write a Java Program in C/C++/ Java to implement Traveling Salesman Problem using nearest neighbor algorithm
#include<stdio.h>
#include<limits.h>

#define V 4 // No. of vertices


// Function to find the nearest neighbor of a given vertex
int nearest_neighbor(int graph[V][V], int visited[V], int src) {
    int nearest_vertex = -1, nearest_cost = INT_MAX, i;

    for(i = 0; i < V; i++) {
        if(graph[src][i] && !visited[i] && (graph[src][i] < nearest_cost)) {
            nearest_cost = graph[src][i];
            nearest_vertex = i;
        }
    }
    
    return nearest_vertex;
}



// Function to find the minimum spanning tree using nearest neighbor algorithm
void TSP(int graph[V][V], int start) {
    int path[V], visited[V] = { 0 }, total_cost = 0, i, current;

    visited[start] = 1;
    path[0] = start;
    current = start;

    // Find nearest neighbor for each vertex
    for(i = 1; i < V; i++) {
        int next = nearest_neighbor(graph, visited, start);
        path[i] = next;
        visited[next] = 1;
        total_cost += graph[current][next];
        current = next;;
    }

    // Return to starting vertex
    total_cost += graph[current][start];

    // Print tour
    printf("TSP Path: ");
    for(i = 0; i < V; i++) {
        printf("%d -> ", path[i]);
    }
    printf("%d\n", start);

    printf("Total Cost: %d\n", total_cost);
}

int main() {
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    TSP(graph, 0);
    return 0;
}
/* TSP Path: 0 -> 1 -> 2 -> 3 -> 0
Total Cost: 95 */
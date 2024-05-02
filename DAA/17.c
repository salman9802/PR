// Write a program in C/C++/ Java a to implement Graph Coloring Algorithm
#include<stdio.h>

#define V 4 // No. of vertices

int is_safe(int graph[V][V], int c, int v, int color[]) {
    int i;
    for(i = 0; i < V; i++) {
        if(graph[v][i] && color[i] == c) return 0;
    }
    return 1;
}

int graph_coloring_rec(int graph[V][V], int m, int color[V], int v) {
    int c;

    if(V == v) return 1; // Base condition
    
    for(c = 0; c < m; c++) {
        // Check if assignment of c to v is safe
        if(is_safe(graph, c, v, color)) {
            color[v] = c;
            // Recur to assign colors to rest of the vertices
            if(graph_coloring_rec(graph, m, color, v + 1)) return 1;

            // If assigning color c doesn't lead to a solution, remove it
            color[v] = 0;
        }
    }

    return 0;
}


void graph_coloring_problem(int graph[V][V], int m) {
    int color[V] = { 0 };

    if(!graph_coloring_rec(graph, m, color, 0)) {
        printf("Solution does not exists.\n");
        return;
    }

    printf("Solution exists and following are the assigned colors:\n");
    for (int i = 0; i < V; i++)
        printf("Vertex %d --> Color %d\n", i, color[i]);
}


int main() {
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int m = 3; // No. of colors

    graph_coloring_problem(graph, m);
    return 0;
}
/* Solution does not exists.

{0, 1, 1, 0},
{1, 0, 0, 1},
{1, 0, 0, 1},
{0, 1, 1, 0}
Solution exists and following are the assigned colors:
Vertex 0 --> Color 1
Vertex 1 --> Color 2
Vertex 2 --> Color 2
Vertex 3 --> Color 0 */
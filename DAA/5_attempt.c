#include<stdio.h>
#include<stdlib.h>

#define E 3 // No. of edges

// Edge structure containing two vertices it connects along with it's weight
typedef struct Edge {
    int v1, v2, w;
} Edge;

// Graph structure with list of vertices and edges
typedef struct Graph {
    int *vertices;
    Edge *edges;
    int i; // index for edges
} Graph;

// int PARENT[]

// Function to add edge in graph connnecting v1 & v2 with weight w
void add_edge(Graph *g, int v1, int v2, int w) {
    Edge *edge = (Edge *) malloc(sizeof(Edge));
    edge->v1 = v1;
    edge->v2 = v2;
    edge->w = w;

    g->edges[g->i++] = *edge;
}

void kruskal(Graph *g) {
    int V = 
}

int main() {
    int vertices[] = {1, 2, 3};
    Graph *g = (Graph *) malloc(sizeof(Graph));

    // Set vertices and edges of the graph
    g->vertices = vertices;
    g->edges = (Edge *) malloc(E *  sizeof(Edge));
    g->i = 0;

    add_edge(g, 1, 2, 5);
    add_edge(g, 2, 3, 2);
    add_edge(g, 1, 3, 3);

    kruskal(g);
    return 0;
}
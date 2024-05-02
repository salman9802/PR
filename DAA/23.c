// Write a program in C/C++/ Java to find out live node, E node and dead node from a given graph 
#include<stdio.h>
#include<stdlib.h>

int V;
/* 
Live Node: A node that has at least one outgoing edge.
E-node: A node that has no outgoing edge.
Dead Node: A node that is not reachable from any other node
*/
void find_nodes(int graph[V][V]) {
    int live_nodes[V], e_nodes[V], dead_nodes[V], i, j;

    for(i = 0; i < V; i++) {
        live_nodes[i] = 0;
        e_nodes[i] = 1;
        dead_nodes[i] = 1;
    }

    for(i = 0; i < V; i++)
        for(j = 0; j < V; j++)
            if(graph[i][j]) {
                live_nodes[i] = 1;
                e_nodes [i] = 0;
                dead_nodes[j] = 0;
            }
    
    printf("\nLive Nodes: ");
    for(i = 0; i < V; i++)
        if(live_nodes[i]) printf("%d ", i);
    
    printf("\nE Nodes: ");
    for(i = 0; i < V; i++)
        if(e_nodes[i]) printf("%d ", i);
    
    printf("\nDead Nodes: ");
    for(i = 0; i < V; i++)
        if(dead_nodes[i]) printf("%d ", i);
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

    find_nodes(graph);
    return 0;
}
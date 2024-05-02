// Write a program in C/C++/ Java for finding Topological sorting for Directed Acyclic Graph (DAG) 
#include<stdio.h>

#define MAX_VERTICES 100

int stack[MAX_VERTICES], tos = -1, visited[MAX_VERTICES] = { 0 };


void push(int x) { stack[++tos] = x; }

int pop() {
    if(tos == -1) return -1;
    return stack[tos--];
}

void dfs(int graph[][MAX_VERTICES], int V, int vertex) {
    int i;

    visited[vertex] = 1;
    // printf("%d ", vertex);
    push(vertex);

    for(i = 0; i < V; i++) { // loop through all neighbours
        if(graph[vertex][i] && !visited[i]) {
            visited[i] = 1;
            dfs(graph, V, i);
        }
    }
}

void topological_sort(int graph[][MAX_VERTICES], int V) {
    int i;
    for(i = 0; i < V; i++) {
        if(!visited[i]) {
            visited[i] = 1;
            dfs(graph, V, i);
        }
    }
    printf("Topological Sort of given graph: ");
    while((i = pop()) != -1) {
        printf("%d ", i);
    }
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int V, i, j;
    
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < V; i++) {
        for(j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    topological_sort(graph, V);
    return 0;
}
/* Enter number of vertices: 4
Enter adjacency matrix:
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0
Topological Sort of given graph: 2 3 1 0 */
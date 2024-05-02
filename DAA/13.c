// Write programs in C/C++/ Java to implement DFS and BFS. Compare the time complexity
#include<stdio.h>

#define MAX_VERTICES 100

int queue[MAX_VERTICES], queue_front, queue_back, visited[MAX_VERTICES] = { 0 };


void enqueue(int x) {
    queue[queue_back++] = x;
}

int dequeue() {
    return queue[queue_front++];
}

int isQueueEmpty() {
    return queue_front == queue_back;
}

void bfs(int graph[][MAX_VERTICES], int V, int start) {
    int i;

    printf("BFS of given graph: ");
    queue_front = queue_back = 0;
    
    visited[start] = 1;
    enqueue(start);

    while(!isQueueEmpty()) {
        int vertex = dequeue();
        printf("%d ", vertex);

        for(i = 0; i < V; i++) {
            if(graph[vertex][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}


void dfs(int graph[][MAX_VERTICES], int V, int vertex) {
    int i;

    visited[vertex] = 1;
    printf("%d ", vertex);

    for(i = 0; i < V; i++) { // loop through all neighbours
        if(graph[vertex][i] && !visited[i]) {
            visited[i] = 1;
            dfs(graph, V, i);
        }
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

    // bfs(graph, V, 0);

    printf("DFS of given graph: ");
    dfs(graph, V, 0);
    return 0;
}
/* Time Complexity Analysis:

The time complexity of both DFS and BFS is 
O(V+E), where 
V is the number of vertices and 
E is the number of edges in the graph.
This is because each vertex and edge is visited once during traversal.
This is because each vertex can have an edge to every other vertex in the worst case, resulting in V^2. */

/*
BFS
Enter number of vertices: 4
Enter adjacency matrix:
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0
BFS of given graph: 0 1 2 3 

DFS
Enter number of vertices: 4
Enter adjacency matrix:
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0
DFS of given graph: 0 1 3 2 */
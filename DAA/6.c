// Write a program in C/C++/ Java to find Minimum Cost Spanning Tree of a given undirected graph using Prim‟s algorithm

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX 10

int cost[MAX][MAX], visited[MAX] = { 0 };

void prims(int V) {
    int i, j, total_cost = 0, min, u, v;
    int n = 0;
    visited[0] = 1;
    while(n < V) {
        for(i = 0, min = INT_MAX; i < V; i++) {
            for(j = 0; j < V; j++) {
                if(cost[i][j] < min) {
                    if(visited[i] != 0) { // if first node is visited
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if(visited[u] == 0 || visited[v] == 0) { // if one is unvisited
            n++;
            printf("%d -> %d = %d\n", u, v, min);
            total_cost += min;
            visited[v] = 1;
        }
        cost[u][v] = cost[v][u]= INT_MAX;
    }
    printf("Minimum Cost: %d\n", total_cost);
}


int main() {
    int V, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter cost adjecency matrix:\n");
    for(i = 0; i < V; i++) {
        for(j = 0; j < V; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0) cost[i][j] = INT_MAX;
        }
    }
    
    prims(V);
    return 0;
}
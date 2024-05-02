// Write a program in C/C++/ Java  to from a given vertex in a weighted connected graph, find shortest paths to other vertices using Dijikstra‟s algorithm
#include<stdio.h>
#include<stdlib.h>

#define MAX 10
#define INF 9999

void dijkstra(int G[MAX][MAX], int n, int start) {
    // pred[] - stores predecessor of each node
    int cost[MAX][MAX], dist[MAX], pred[MAX];
    // count - no. of nodes seen so far
    int visited[MAX], i, j, count, min_dist, next_node;

     for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            cost[i][j] = (G[i][j] == 0 ? INF : G[i][j]);
    
    // initialize pred[], dist[], visited[]
    for(i = 0; i < n; i++) {
        dist[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }
    dist[start] = 0;
    visited[start] = 1;
    count = 1;
    while(count < n - 1) {
        min_dist = INF;
        
        // next_node gives min_dist
        for(i = 0; i < n; i++) {
            if(dist[i] < min_dist && !visited[i]) {
                min_dist = dist[i];
                next_node = i;
            }
        }

        // Check if better path exists through next_node
        for(i = 0; i < n; i++) {
            if(!visited[i]) {
                if(min_dist + cost[next_node][i] < dist[i]) {
                    dist[i] = min_dist + cost[next_node][i];
                    pred[i] = next_node;
                }
            }
        }
        count++;
    }

    // Print path & distance of each node
    for(i = 0; i < n; i++) {
        if(i != start) {
            printf("Distance of node %d = %d\n", i , dist[i]);
            printf("Path = %d", i);
            j = i;
            do {
                j = pred[j];
                printf("<- %d ", j);
            }while(j != start);
        }
    }
}

int main() {
    int G[MAX][MAX], i, j, n, s;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &G[i][j]);
    printf("Enter starting node: ");
    scanf("%d", &s);
    dijkstra(G, n, s);
    return 0;
}
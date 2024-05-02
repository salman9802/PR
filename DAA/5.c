// Write a program in C/C++/ Java to find Minimum Cost Spanning Tree of a given undirected graph using Kruskal‟s algorithm

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX 10

int cost[MAX][MAX], parent[MAX];

int find(int i) {
    while(parent[i]) i = parent[i]; // find root parent
    return i;
}

int make_union(int p1, int p2) {
    if(p1 != p2) {
        parent[p2] = p1;
        return 1;
    }
    return 0;
}

void kruskal(int V) {
    int i, j, total_cost, min, u, v;
    int n = 0;
    while(n < V) {
        for(i = 0, min = INT_MAX; i < V; i++) {
            for(j = 0; j < V; j++) {
                if(cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        if(make_union(find(u), find(v))) {
            n++;
            printf("%d -> %d = %d\n", u, v, min);
            total_cost += min;
        }

        cost[u][v] = INT_MAX;
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
    
    kruskal(V);
    return 0;
}
/* Enter number of vertices: 3
Enter cost adjecency matrix:
0 5 3
5 0 2
3 2 0
1 -> 2 = 2
0 -> 2 = 3
2 -> 0 = 3
Minimum Cost: 8 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// heap sort
void heapify(int *A, int n, int root) {
    int largest = root;
    int left_child = 2 * root + 1;
    int right_child = 2 * root + 2;

    if(left_child < n && A[left_child] > A[largest]) largest = left_child;

    if(right_child < n && A[right_child] > A[largest]) largest = right_child;

    if(largest != root) {
        int temp = A[root];
        A[root] = A[largest];
        A[largest] = temp;

        heapify(A, n, largest);
    }
}
void heap_sort(int *A, int n) {
    for(int i = (n/2)-1; i >= 0; i--) heapify(A, n, i);

    for(int i = n-1; i > 0; i--) {
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;

        heapify(A, i, 0);
    }
}

// Radix sort
int get_max(int *A, int n) {
    int max = A[0];
    for(int i = 1; i < n; i++) if(A[i] > max) max = A[i];
    return max;
}
/* int counting_sort(int *A, int n, int exp) {
    int output[n], count[n];

    for(int i = 0; i < n; i++)
        count[i] = 0;

    for(int i = 0; i < n; i++)
        count[(A[i]/exp) % 10]++;

    
    int k =0;
    for(int i=0; i < n; i++) {
        while(count[i] > 0) {
            for(int j = 0; )
        }

    }
}
void radix_sort(int *A, int n) {
    int max = get_max(A, n);
    for(int exp = 1; (max / exp) > 0; exp *= 10)
        counting_sort(A, n, exp);
} */

// dijkstra's
void dijikstra(int graph[5][5], int n, int start) {
    int path[n], pred[n], cost[n][n], dist[n];
    int visited[n], i, j, k;
    int count = 0;

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            cost[i][j] = (G[i][j] == 0 ? INF : G[i][j]);

    for(i = 0; i < n; i++) {
        pred[i] = start;
        visited[i] = 0;
        dist[i] = cost[start][i];
    }

    visited[start] = 1;
    dist[start] = 0;
    count = 1;

    while(count < n) {
        int min_cost = INT_MAX;
        for(i=0; i < n; i++) {
            if(dist[i] < min_cost && !visited[i]){
                min_cost = dist[i];
                min_node = i;
            }
        }

        for(i = 0; i < n;i++) {
            if(!visited[i]) {
                if(min_dist + cost[min_node][i] < dist[i]) {
                    dist[i] = min_dist + cost[min_node][i];
                    pred[i] = min_node;
                    visited[min_node] = 1;

                }
            }
        }
        count++;
    }

    for(i=0; i < n; i++) {
        if(i != start) {
            printf("Distance of node %d = %d", i, dist[i]);
            printf("Path = %d", i);
            int j = i;
            do{
                j = pred[j];
                printf("<=%d", j);
            }while(j != start);
        }
    }
}

// Hamiltonian cycle
int V = 5;
int is_safe(int graph[V][V], int v, int pos, int path[V]) {
    if(!graph[path[pos - 1][v]]) return 0;

    for(int i = 0; i<V;i++)
        if(path[i] == v) return 0;

    return 1;
}

int hamiltonian_cycle_util(int graph[V][V], int path[V], int pos) {
    if(pos == V) {
        if(graph[path[pos - 1]][path[0]]) return 1;
        else return 0;
    }

    for(int i = 0; i < V; i++) {
        if(is_safe(graph, i, pos, path)) {
            path[pos] = i;
            if(hamiltonian_cycle_util(graph, path, pos + 1)) return 1;
            path[pos] = -1;
        }
    }

    return 0;
}
void hamiltonian_cycle(int graph[V][V]) {
    int path[V];

    for(int i = 0; i < V; i++) path[i] = -1;

    path[0] = 0;

    if(hamiltonian_cycle_util(graph, path, 1)) {
        // Solution
        return;
    }
}

// graph coloring
int is_safe(int graph[V][V], int color[V], int c, int v) {
    for(i....)
        if(color[i] == c && graph[v][i]) reutrn 0;
    
    return 1;
}
int graph_coloring_rec(int graph[V][V], int color[V], int m, int v) {
    if(v == V) return 1;

    for(int c = 0; c < m; c++) {
        if(is_safe(graph, color, c, v)) {
            color[v] = c;
            if(graph_coloring_rec(graph, color, m, v + 1)) return 1;
            color[v] = 0;
        }
    }
    return 0;
}
void graph_coloring_problem(int graph[V][V], int m) {
    int color[V];

    if(graph_coloring_rec(graph, color, m, 0)) {
        // solution
    }
}

// lcs
char a[256], b[256], buff[256];
int lcs_table[256][256];

int max(int x, int y) { return x > y ? x : y; }

int lcs_len(int m, int n) {
    if(m == 0 || n == 0) return lcs_table[m][n];
    else if(lcs_table[m][n] != -1) return lcs_table[m][n];
    else if(a[m - 1] == b[n - 1]) return 1 + lcs_len(m - 1, n - 1);
    else max(lcs_len(m - 1, n), lcs_len(m, n - 1));
}

char *lcs_str(int m, int n) {
    int index = lcs_len(m, n);
    char *s = (char *) malloc((index + 1)*sizeof(char));
    s[index] = '\0';

    int i = m, j = n;
    while(i > 0 && j > 0) {
        if(a[i - 1] == b[j - 1]) {
            s[--index] = a[i-1];
            i--;
            j--;
        } else if(lcs_table[i - 1][j] > lcs_table[i][j - 1]) i--;
        else j--;
    }

    return s;
}
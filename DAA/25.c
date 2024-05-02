// Write a program in C/C++/ Java to find out solution for 0/1 knapsack problem
#include<stdio.h>
#include<stdlib.h>

typedef struct Item {
    int weight, profit;
} Item;

// Helper func to find max
int max(int x, int y) { return (x > y) ? x : y; }

// knapsack func
int knapsack(Item* items, int W, int n) {
    int i, w;
    int dp[n + 1][W + 1];

    // Build table in bottom-up manner
    for(i = 0; i <= n; i++)
        for(w = 0; w <= W; w++) {
            // when no items or no capacity is considered
            if(w == 0 || i == 0)
                dp[i][w] = 0;
            else if(items[i-1].weight <= w)
                dp[i][w] = max(dp[i-1][w], dp[i-1][w - items[i-1].weight] + items[i-1].profit);
            else dp[i][w] = dp[i-1][w];
    }

    return dp[n][W];
}

int main() {
    int W, n, i;

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);
    printf("Enter number of items: ");
    scanf("%d", &n);

    Item *items = (Item *) malloc(n * sizeof(Item));
    printf("Enter profit and weight of each item\n");
    for(i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].profit, &items[i].weight);
    }
    
    printf("Maximum Profit: %d", knapsack(items, W, n));

    free(items);
    return 0;
}
/* 
Enter capacity of knapsack: 8
Enter number of items: 4
Enter profit and weight of each item
Item 1: 1 2
Item 2: 2 3
Item 3: 5 4
Item 4: 6 5
Maximum Profit: 8
*/
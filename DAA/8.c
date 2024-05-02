// Write a program in C/C++/ Java to implement Knapsack problems using Greedy method
#include<stdio.h>
#include<stdlib.h>

typedef struct Item {
    int weight, profit;
} Item;

// Compare func to sort items according to profit-by-weight in descending order
int compare(const void *item1, const void *item2) {
    Item *i1 = (Item *) item1;
    Item *i2 = (Item *) item2;
    double ratio1 = i1->profit / i1->weight;
    double ratio2 = i2->profit / i2->weight;
    return ratio2 - ratio1;
}

double factorial_knapsack(int W, Item *items, int n) {
    // Sort items based of profit-by-weight
    qsort(items, n, sizeof(items[0]), compare);

    double total_profit = 0.0;
    int remaining_weight = W;
    int i;
    for(i = 0; i < n; i++) {
        if(items[i].weight <= remaining_weight) { // If adding current item won't overflow, add it completely
            total_profit += items[i].profit;
            remaining_weight -= items[i].weight;
        } else { // If adding current item will overflow, add fraction of it
            total_profit += (double) items[i].profit * remaining_weight / items[i].weight;
            break;
        }
    }
    return total_profit;
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

    double max_profit = factorial_knapsack(W, items, n);

    printf("Maximum Profit: %f", max_profit);

    free(items);
    return 0;
}
/* Enter capacity of knapsack: 15
Enter number of items: 7
Enter profit and weight of each item
Item 1: 10 2
Item 2: 5 3
Item 3: 15 5
Item 4: 7 7
Item 5: 6 1
Item 6: 18 4
Item 7: 3 1
Maximum Profit: 27.000000 */
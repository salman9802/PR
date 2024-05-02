#include <stdio.h>
#include <stdlib.h>

// Structure for an item which stores weight and value of item
struct Item {
    int value;
    int weight;
};

// Comparison function to sort items based on value per unit weight in non-increasing order
int compare(const void* a, const void* b) {
    double ratio1 = (double)(((struct Item*)b)->value) / ((struct Item*)b)->weight;
    double ratio2 = (double)(((struct Item*)a)->value) / ((struct Item*)a)->weight;
    return ratio1 - ratio2;
}

// Function to solve fractional knapsack problem using Greedy approach
double fractionalKnapsack(int W, struct Item arr[], int n) {
    // Sort items based on value per unit weight in non-increasing order
    qsort(arr, n, sizeof(arr[0]), compare);

    double totalValue = 0.0; // Initialize result

    // Loop through all items and fill the knapsack
    for (int i = 0; i < n; i++) {
        // If adding current item won't overflow, add it completely
        if (arr[i].weight <= W) {
            totalValue += arr[i].value;
            W -= arr[i].weight;
        } else {
            // If adding current item will overflow, add fraction of it
            totalValue += (double)arr[i].value * W / arr[i].weight;
            break;
        }
    }

    return totalValue;
}

int main() {
    int W; // Weight of knapsack
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &W);

    int n; // Number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item* arr = (struct Item*)malloc(n * sizeof(struct Item)); // Array to store items

    // Input items' value and weight
    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &arr[i].value, &arr[i].weight);
    }

    double maxValue = fractionalKnapsack(W, arr, n); // Solve knapsack problem

    printf("Maximum value in the knapsack: %.2lf\n", maxValue);

    free(arr);

    return 0;
}
/* Enter the capacity of knapsack: 15
Enter the number of items: 7
Enter the value and weight of each item:
Item 1: 10 2
Item 2: 5 3
Item 3: 15 5
Item 4: 7 7
Item 5: 6 1
Item 6: 18 4
Item 7: 3 1
Maximum value in the knapsack: 55.33 */
// Write a program in C/C++/ Java to implement Sum of Subset by Backtracking

#include<stdio.h>

void sum_of_subset(int set[], int n, int subset[], int subset_size, int sum, int total, int index) {
    if(total == sum) { // solution found
        printf("Subset( ");
        for(int i = 0; i < subset_size; i++) printf("%d ", subset[i]);
        printf(")\n");
        return;
    }

    // total exceeds sum or index out of bound
    if(total > sum || index == n) return;

    // include current element in subset
    subset[subset_size] = set[index];
    sum_of_subset(set, n, subset, subset_size + 1, sum, total + set[index], index + 1);

    // exclude current element in subset
    sum_of_subset(set, n, subset, subset_size, sum, total, index + 1);
}

int main() {
    int set[] = {10, 7, 5, 18, 12, 20, 15};
    int n = sizeof(set) / sizeof(set[0]);
    int sum = 35; // sum required

    int subset[100];
    sum_of_subset(set, n, subset, 0, sum, 0, 0);
    return 0;
}
/* Subset( 10 7 18 )
Subset( 10 5 20 )
Subset( 5 18 12 )
Subset( 20 15 ) */
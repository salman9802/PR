// Write a program in C/C++/ Java to sort a given set of elements using the Quick sort method and determine the time required to sort the elements. Repeat the experiment for different values of n, the number of elements in the list to be sorted. The elements can be read from a file or can be generated using the random number generator.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define N 10 // size of array

void create_array(int **A, int n) {
    int i;
    *A = (int *) calloc(n, sizeof(int));
    for(i = 0; i < n; i++) (*A)[i] = (rand() % 20) + 1;
}

void print_array(int *A, int n) {
    int i;
    for (i = 0; i < n; i++) printf("%d ", A[i]);
    printf("\n");
}

int quick_sort_partition(int *A, int low, int high) {
    int pivot = A[low], i = low + 1, j = high, temp;

    do{ // until i & j have crossed
        // i finds element greater than pivot (forwards)
        while(A[i] <= pivot) i++;

        // j finds element less than or equal to pivot (backwards)
        while(A[j] > pivot) j--;

        // Swap A[i] & A[j] if they have not crossed
        if(i < j) {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while(i < j);

    // Swap A[j] with pivot (not pivot variable)
    temp = A[j];
    A[j] = A[low];
    A[low] = temp;
    
    return j; // return pivot
}

void quick_sort(int *A, int low, int high) {
    if(low < high){
        int pivotIndex = quick_sort_partition(A, low, high);
        quick_sort(A, low, pivotIndex - 1);
        quick_sort(A, pivotIndex + 1, high);
    }
}

int main() {
    int *A;
    srand(time(NULL));

    create_array(&A, N);
    print_array(A, N);
    printf("Quick Sort: ");
    quick_sort(A, 0, N - 1);
    print_array(A, N);

    return 0;
}
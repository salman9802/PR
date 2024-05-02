// Write a program in C/C++/ Java to implement a Merge Sort algorithm to sort a given set of elements and determine the time required to sort the elements. Repeat the experiment for different values of n, the number of elements in the list to be sorted. The elements can be read from a file or can be generated using the random number generator.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define N 10 // size of array

// Generates random numbers in array
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

void merge(int *A, int low, int mid, int high) {
    int i, j, k, B[N];
    i = low; // starting index for first array
    j = mid + 1; // starting index for second array
    k = low; // starting index for B

    // Till none of both array is complete
    while(i <= mid && j <= high) {
        // Place smaller element
        if(A[i] < A[j]) B[k++] = A[i++];
        else B[k++] = A[j++];
    }

    // Place left out elements from respective array at the end
    while(i <= mid) B[k++] = A[i++];
    while(j <= high) B[k++] = A[j++];

    // Copy B back to A
    for(k = low; k <= high; k++) A[k] = B[k];
}

void merge_sort(int *A, int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;
        merge_sort(A, low, mid);
        merge_sort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}

int main() {
    int *A;
    srand(time(NULL));

    create_array(&A, N);
    print_array(A, N);
    printf("Merge Sort: ");
    merge_sort(A, 0, N - 1);
    print_array(A, N);

    return 0;
}
// Write programs in C/C++/ Java to sort a list of n numbers in ascending order using selection sort, insertion sort, heap sort, radix sort. Determine the time required to sort and compare on basis of time complexity for different values of n.

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

// Selection Sort
void selection_sort(int *A, int n) {
    int index_of_min = INT_MAX;
    int i, j, temp;
    for(i = 0; i < n-1; i++) {
        index_of_min = i;
        for(j = i+1; j < n; j++) { // find index of minimum value from remaining array
            if(A[index_of_min] > A[j]) index_of_min = j;
        }
        // Swap A[index_of_min] & A[i]
        temp = A[i];
        A[i] = A[index_of_min];
        A[index_of_min] = temp;
    }
}

// Insertion Sort
void insertion_sort(int *A, int n) {
    int i, j, key;
    
    for(i = 1; i < n; i++) {
        key = A[i];
        j = i - 1;
        while(j >=0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

// Heap Sort
void heapify(int *A, int n, int root) {
    int temp;
    int largest = root; // root is the largest by default
    int left_child = 2 * root + 1; // left child = 2*i+1
    int right_child = 2 * root + 2; // right child = 2*i+2
    
    // if left is greater than largest
    if(left_child < n && A[left_child] > A[largest]) largest = left_child;
    
    // if right is greater than largest
    if(right_child < n && A[right_child] > A[largest]) largest = right_child;
    
    // swap the largest (if found) with root
    if(largest != root) {
        temp = A[root];
        A[root] = A[largest];
        A[largest] = temp;
        
        // recursively heapify subtree
        heapify(A, n, largest);
    }
}

void heap_sort(int *A, int n) {
    int i, temp;
    // build a max heap
    for(i = n/2 - 1; i >=0; i--) heapify(A, n, i);
    
    // one by one extract elements from heap
    for(i = n-1; i > 0; i--) {
        // Swap first with current end
        temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        
        // heapify on reduced tree
        heapify(A, i, 0);
    }
    
}

// Radix Sort
// Function to get max element from array
int get_max(int *A, int n) {
    int max = A[0], i;
    for(i = 1; i < n; i++) if(max < A[i]) max = A[i];
    return max;
}

void counting_sort(int *A, int n, int exp) {
    int output[n], i, digit, j;
    int count[10] = {0};
    
    // dividing by exp reduces the number and mod 10 gives the last digit from reduced number
    // Store count of occurrences in count[]
    for(i = 0; i < n; i++)
        count[(A[i] / exp) % 10]++;


    // Change count[i] so that count[i] now contains
    // actual position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    
    // Build the output array
    for(i = n-1; i >= 0; i--){
        output[count[(A[i] / exp) % 10] - 1] = A[i];
        count[(A[i] / exp) % 10]--;
    }
    
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to the current digit
    for(i = 0; i < n; i++)
        A[i] = output[i];
}

void radix_sort(int *A, int n){
    int max = get_max(A, n), exp;
    // Do counting sort for every digit. Note that
    // instead of passing digit number, exp is passed.
    // exp is 10^i where i is the current digit number
    for(exp = 1; (max / exp) > 0; exp *= 10) 
        counting_sort(A, n, exp);
}

int main() {
    int *A;
    srand(time(NULL));
    
    // create_array(&A, N);
    // print_array(A, N);
    // printf("Selection Sort: ");
    // selection_sort(A, N);
    // print_array(A, N);
    // free(A);
    
    // create_array(&A, N);
    // print_array(A, N);
    // printf("Insertion Sort: ");
    // insertion_sort(A, N);
    // print_array(A, N);
    // free(A);
    
    // create_array(&A, N);
    // print_array(A, N);
    // printf("Heap Sort: ");
    // heap_sort(A, N);
    // print_array(A, N);
    // free(A);
    
    create_array(&A, N);
    print_array(A, N);
    printf("Radix Sort: ");
    radix_sort(A, N);
    print_array(A, N);
    free(A);
    
    
    return 0;
}


/*
heapify is a recursive function that ensures the max-heap property is maintained at a given index in the array. It compares the element at the current index with its left and right children and swaps the elements if needed. The function then recursively calls itself on the affected subtree.

heap_sort is the main function that performs the Heap Sort algorithm.
It first builds a max heap from the array by calling heapify for each non-leaf node from the bottom up.
It then repeatedly extracts the maximum element (root) and swaps it with the last element of the heap.
After each extraction, it calls heapify to restore the max heap property.
The process is repeated until the entire array is sorted.
*/

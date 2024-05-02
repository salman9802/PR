// Write a program in C/C++/ Java to implement huffman Code using greedy methods and also calculate the best case and worst case complexity.
#include<stdio.h>
#include<stdlib.h>

// A Huffman tree node (tree is represented as Min Heap)
typedef struct MinHeapNode {
    char data;
    int freq;
    struct MinHeapNode *left, *right;
} MinHeapNode;

// A Min Heap: Collection of min-heap (or Huffman tree) nodes
typedef struct MinHeap {
    int size, capacity;
    MinHeapNode **array;
} MinHeap;

// Function to create a new Min Heap node
MinHeapNode* createNode(char data, int freq) {
    MinHeapNode *node = (MinHeapNode *) malloc(sizeof(MinHeapNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

// Function to create a min heap of given capacity
MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap *) malloc(sizeof(MinHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (MinHeapNode **) malloc(capacity * sizeof(MinHeapNode*));
    return heap;
}

// Function to swap two min heap nodes
void swapMinHeapNodes(MinHeapNode **a, MinHeapNode **b) {
    MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}

// Function to heapify at given index
void minHeapify(MinHeap *minHeap, int idx) {
    int smallest = idx;
    int left = 2*idx + 1; // index of left child
    int right = 2*idx + 2; // index of right child
    
    if(left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if(right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if(smallest != idx) { // if current node was not the smallest
        swapMinHeapNodes(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Function to extract the minimum value node from heap
MinHeapNode* extractMin(MinHeap *heap) {
    MinHeapNode *node = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    --heap->size;
    minHeapify(heap, 0);
    return node;
}

// Function to insert a new node to min heap
void insertNode(MinHeap* heap, MinHeapNode* node) {
    heap->size++;
    int i = heap->size - 1;
    while(i && node->freq < heap->array[(i - 1) / 2] ->freq) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = node;
}

// Function to build the min heap
void buildMinHeap(MinHeap * heap) {
    int n = heap->size - 1;
    int i;
    for(i = (n - 1) / 2; i >= 0; --i) {
        minHeapify(heap, i);
    }
}

// Function to check if the node is a leaf
int isLeaf(MinHeapNode* root) {
    return !(root->left) && !(root->right);
}

// Function to create a min heap and insert all characters of data[]
MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) {
    int i;
    MinHeap *minHeap = createMinHeap(size);
    for(i = 0; i < size; i++)
        minHeap->array[i] = createNode(data[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

// Function to build Huffman tree
MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    MinHeapNode *left, *right, *top;
    MinHeap *heap = createAndBuildMinHeap(data, freq, size);

    while(!(heap->size == 1)) {
        // Extract the two minimum frequency items from the min heap
        left = extractMin(heap);
        right = extractMin(heap);

        // Create a new internal node with frequency equal to the sum of the two nodes frequencies. Make the two extracted node as left and right children of this new node. Add this node to the min heap.
        top = createNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertNode(heap, top);
    }

    // The remaining node is the root node and the tree is complete.
    return extractMin(heap);
}

// Function to print Huffman codes from the root of Huffman Tree
void printCodes(MinHeapNode* root, int arr[], int top) {
    // Assign 0 to left edge and recur
    if(root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    // Assign 1 to right edge and recur
    if(root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    // If this is a leaf node, it contains one of the input characters, print the character and its code from the array
    if(isLeaf(root)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Function to build Huffman Tree and print codes by traversing the built Huffman Tree
void HuffmanCodes(char data[], int freq[], int size) {
    // Construct Huffman Tree
    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);

    // Print Huffman codes using the Huffman tree built above
    int arr[100], top = 0;
    printCodes(root, arr, top);
}

int main() {
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(data) / sizeof(data[0]);

    printf("Huffman Codes:\n");
    HuffmanCodes(data, freq, size);

    return 0;
}
/* Huffman Codes:
f: 0
c: 100
d: 101
a: 1100
b: 1101
e: 111 */
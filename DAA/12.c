// Write a Program in C/C++/Java to find only length of Longest Common Subsequence.
#include<stdio.h>

char a[256], b[256];


int max(int x, int y) {
    if(x > y) return x;
    else return y;
}

int lcs(int i, int j) {
    if(a[i] == '\0' || b[j] == '\0') return 0;
    else if(a[i] == b[j]) return 1 + lcs(i + 1, j + 1);
    else max(lcs(i + 1, j), lcs(i, j + 1));
}

int main() {
    printf("Enter first string: ");
    scanf("%s", a);
    
    printf("Enter second string: ");
    scanf("%s", b);

    int l = lcs(0, 0);

    printf("Length of largest common subsequence: %d", l);

    return 0;
}
/* Enter first string: bd
Enter second string: abcd
Length of largest common subsequence: 2 */
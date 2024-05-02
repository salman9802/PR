// Write a program in C/C++/ Java to find out longest common subsequence from the given strings

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char a[256], b[256], buff[256];
int lcs_table[256][256];

int k = 0;

int max(int x, int y) {
    if(x > y) return x;
    else return y;
}

// int lcs_len(int i, int j) {
//     if(a[i] == '\0' || b[j] == '\0') return 0;
//     else if(a[i] == b[j]) return 1 + lcs(i + 1, j + 1);
//     else max(lcs(i + 1, j), lcs(i, j + 1));
// }

int lcs_len(int m, int n) {
    if(m == 0 || n == 0) return 0; // base condition
    else if(lcs_table[m][n] != -1) return lcs_table[m][n];
    else if(a[m - 1] == b[n - 1]) return 1 + lcs_len(m - 1, n - 1); // previous row & previous col char matches
    else return max(lcs_len(m - 1, n), lcs_len(m, n - 1)); // maximum of previous row value & previous col value
}

char* lcs(int m, int n) {
    // int index = lcs_len(0, 0);
    int index = lcs_len(m, n);
    char *lcs_str = (char *) malloc((index + 1) * sizeof(char));
    lcs_str[index] = '\0';

    int i = m, j = n;
    while(i > 0 && j > 0) {
        if(a[i - 1] == b[j - 1]) { // prev row & prev col char match
            lcs_str[--index] = a[i - 1];
            i--;
            j--;
        } else if(lcs_table[i - 1][j] > lcs_table[i][j - 1]) i--;
        else j--;
    }

    return lcs_str;
}

int main() {
    int i, j;
    printf("Enter first string: ");
    scanf("%s", a);
    
    printf("Enter second string: ");
    scanf("%s", b);

    int m = strlen((a));
    int n = strlen((b));

    for(i = 0; i < 256; i++)
        for(j = 0; j < 256; j++)
            lcs_table[i][j] = -1;

    char *str = lcs(m, n);

    printf("Largest common subsequence: %s", str);

    return 0;
}
/* Enter first string: acd
Enter second string: abcd
Largest common subsequence: acd */
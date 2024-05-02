// Write a program in C/C++/ Java to solve N Queens Problem using Backtracking
// Write a program in C/C++/ Java to solve 4 Queens Problem using Backtracking
// Write a program in C/C++/ Java to show board configuration of 4 queens problem

#include<stdio.h>

#define N 4


char board[N][N];

void print_board() {
    int i, j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
}

int is_safe(int row, int col) {
    int i, j;

    // check row on left side of current column
    for(j = 0; j < col; j++)
        if(board[row][j] == 'Q') return 0;

    // check upper left diagonal
    for(i = row, j = col; i>=0 && j>=0; i--, j--)
        if(board[i][j] == 'Q') return 0;
    

    // check lower left diagonal
    for(i = row, j = col; i < N && j >=0; i++, j--)
        if(board[i][j] == 'Q') return 0;

    return 1; // if no attack on current row & col
}

int queens_problem(int col) {
    int row;

    if(col >= N) return 1; // Base condition (all queens placed)

    for(row = 0; row < N; row++) {
        if(is_safe(row, col)) {
            board[row][col] = 'Q';

            if(queens_problem(col + 1)) return 1; // recursively place other queens

            board[row][col] = '.'; // if current queen doesn't lead to a solution, backtrack
        }
    }

    return 0;
}


int main() {
    int i, j;
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            board[i][j] = '.';

    printf("Board before:\n");
    print_board();
    
    if(queens_problem(0)) {
        printf("Solution found\n");
        print_board();
    } else {
        printf("No solution found");
    }
    
    return 0;
}
/* Board before:
. . . . 
. . . . 
. . . . 
. . . . 
Solution found
. . Q . 
Q . . . 
. . . Q 
. Q . .  */
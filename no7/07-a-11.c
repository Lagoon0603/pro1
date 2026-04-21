#include <stdio.h>
#include <stdlib.h>

#define N 8

int board[N];
int count = 0;

void print_solution(void)
{
    int r, c;
    count++;
    printf("solution = %d:\n", count);
    for (r = 0; r < N; r++) {
        for (c = 0; c < N; c++) {
            if (board[c] == r) {
                printf("Q");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int is_safe(int col, int row)
{
    int k;
    for (k = col + 1; k < N; k++) {
        int r_k = board[k];
        if (row == r_k) {
            return 0;
        }
        if (abs(col - k) == abs(row - r_k)) {
            return 0;
        }
    }
    return 1;
}

void solve_queen(int col)
{
    int row;
    
    if (col == -1) {
        print_solution();
        return;
    }

    for (row = 0; row < N; row++) {
        if (is_safe(col, row)) {
            board[col] = row;
            solve_queen(col - 1);
        }
    }
}

int main(void)
{
    solve_queen(N - 1);
    return 0;
}


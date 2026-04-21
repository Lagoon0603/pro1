#include <stdio.h>
#include <stdlib.h>

int h[205];
int memo[205];

int solve(int i)
{
    int cost1, cost2;

    if (i == 0) {
        return 0;
    }
    if (i == 1) {
        return abs(h[1] - h[0]);
    }
    
    if (memo[i] != -1) {
        return memo[i];
    }

    cost1 = solve(i - 1) + abs(h[i] - h[i - 1]);
    cost2 = solve(i - 2) + abs(h[i] - h[i - 2]);

    if (cost1 < cost2) {
        memo[i] = cost1;
    } else {
        memo[i] = cost2;
    }
    
    return memo[i];
}

int main(void)
{
    int n, i;
    printf("input # of stands: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }

    // メモ配列の初期化 (-1 は未計算を表す)
    for (i = 0; i < 205; i++) {
        memo[i] = -1;
    }

    printf("minimum cost is %d\n", solve(n - 1));

    return 0;
}


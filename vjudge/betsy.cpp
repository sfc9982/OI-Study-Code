#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
using namespace std;

int i, j, n;
int f[1005][1005], map[1005][1005];

int main()
{
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &map[i][j]);
    for (i = 1; i <= n; i++)
    {
        f[i][1] = map[i][1] + f[i - 1][1];
        f[1][i] = map[1][i] + f[1][i - 1];
    }
    for (i = 2; i <= n; i++)
        for (j = 2; j <= n; j++)
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + map[i][j];
    printf("%d\n", f[n][n]);
    return 0;
}
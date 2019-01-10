#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int sx[4] = {1, -1, 0, 0};
int sy[4] = {0, 0, 1, -1};
int queue[100][4], a[100][100];
int n, m, t, x1, y1, x2, y2, i, x, y, head, tail;

int main()
{
    scanf("%d%d%d", &n, &m, &t);
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    for (i = 1; i <= t; ++i)
    {
        scanf("%d%d", &x, &y);
        a[x][y] = 1;
    }
    head = 0;
    tail = 1;
    queue[tail][1] = x1;
    queue[tail][2] = y1;
    queue[tail][3] = 1;
    while (head < tail)
    {
        head++;
        for (i = 0; i < 4; ++i)
        {
            x = queue[head][1] + sx[i];
            y = queue[head][2] + sy[i];
            if (x > 0 && y > 0 && x <= n && y <= m && a[x][y] == 0)
            {
                tail++;
                queue[tail][1] = x;
                queue[tail][2] = y;
                queue[tail][3] = queue[head][3] + 1;
                a[x][y] = 1;
                if (x == x2 && y == y2)
                {
                    printf("%d", queue[tail][3]);
                    return 0;
                }
            }
        }
    }
    printf("-1");
    return 0;
}
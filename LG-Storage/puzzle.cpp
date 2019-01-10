#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <stack>
using namespace std;

int n, m, x1, y1, x2, y2, cnt;
int pos[4][2] = {0, -1, -1, 0, 0, 1, 1, 0};
int mapp[105][105];

stack<int> sx;
stack<int> sy;
stack<int> tmpx;
stack<int> tmpy;

void dfs(int x, int y);

int main()
{
    scanf("%d%d", &n, &m);
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &mapp[i][j]);
            }
        }

        scanf("%d%d", &x1, &y1);
        scanf("%d%d", &x2, &y2);

        cnt = 0;
        sx.push(x1);
        sy.push(y1);
        mapp[x1][y1] = 0;
        dfs(x1, y1);
        if (cnt == 0)
        {
            printf("-1\n");
        }
    }

    system("pause");
    return 0;
}

void dfs(int x, int y)
{
    if ((x == x2) && (y == y2))
    {
        cnt++;
        int j = sx.size();
        for (int i = 1; i <= j; i++)
        {
            tmpx.push(sx.top());
            sx.pop();

            tmpy.push(sy.top());
            sy.pop();
        }
        for (int i = 1; i < j; i++)
        {
            printf("(%d,%d)->", tmpx.top(), tmpy.top());
            sx.push(tmpx.top());
            tmpx.pop();

            sy.push(tmpy.top());
            tmpy.pop();
        }
        printf("(%d,%d)", tmpx.top(), tmpy.top());
        sx.push(tmpx.top());
        tmpx.pop();

        sy.push(tmpy.top());
        tmpy.pop();

        printf("\n");
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx, ny;
        nx = x + pos[i][0];
        ny = y + pos[i][1];

        if ((nx >= 1) && (nx <= n) && (ny >= 1) && (ny <= m) && (mapp[nx][ny] == 1))
        {
            sx.push(nx);
            sy.push(ny);
            mapp[nx][ny] = 0;
            dfs(nx, ny);

            sx.pop();
            sy.pop();
            mapp[nx][ny] = 1;
        }
    }
}
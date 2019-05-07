#include <iostream>
#include <cstdio>
using namespace std;
int w1[10005], dis[10005], w2[10005];
int a[10005][1505], b[10005][1505];
int s, e, n, m;
int Q[20005];
int sta[10005];
bool flag[10005];

void bfs(int s, int e)
{
    int h = 0, t = 1;
    Q[t] = s;
    while (h < t)
    {
        h++;
        int x = Q[h];
        for (int i = 1; i <= w1[x]; i++)
        {
            int y = a[x][i];
            if (!sta[y])
                continue;
            if (dis[y] > dis[x] + 1)
            {
                t++;
                Q[t] = y;
                dis[y] = dis[x] + 1;
            }
        }
    }
}

void dfs(int v)
{
    flag[v] = true;
    for (int i = 1; i <= w2[v]; i++)
    {
        int u = b[v][i];
        if (!flag[u])
            dfs(u);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        w1[x]++;
        a[x][w1[x]] = y;
        w2[y]++;
        b[y][w2[y]] = x;
    }
    for (int i = 1; i <= n; i++)
        sta[i] = true;
    scanf("%d%d", &s, &e);
    dfs(e);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w1[i]; j++)
            sta[i] = sta[i] && flag[a[i][j]];
        sta[i] = sta[i] && flag[i];
    }

    if (!sta[s])
    {
        printf("%d\n", -1);
        return 0;
    }
    for (int i = 1; i <= n; i++)
        dis[i] = 1000000;
    dis[s] = 0;
    bfs(s, e);
    if (dis[e] != 1000000)
        printf("%d", dis[e]);
    else
        printf("%d", -1);
    return 0;
}
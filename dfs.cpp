#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int s, e, n, m;
int a[10005][1505], b[10005][1505];
int q[20005], sta[10005], w1[10005], dis[10005], w2[10005];
bool flag[10005];

void bfs(int s, int e)
{
    int h = 0, t = 1;
    q[t] = s;
    while (h < t)
    {
        h++;
        int x = q[h];
        for (int i = 1; i <= w1[x]; i++)
        {
            int y = a[x][i];
            if (!sta[y])
                continue;
            if (dis[y] > dis[x] + 1)
            {
                t++;
                q[t] = y;
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
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        w1[x]++;
        a[x][w1[x]] = y;
        w2[y]++;
        b[y][w2[y]] = x;
    }
    for (int i = 1; i <= n; i++)
        sta[i] = true;
    cin >> s >> e;
    dfs(e);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w1[i]; j++)
            sta[i] = sta[i] && flag[a[i][j]];
        sta[i] = sta[i] && flag[i];
    }
    if (!sta[s])
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
        dis[i] = INF;
    dis[s] = 0;
    bfs(s, e);
    if (dis[e] != INF)
        cout << dis[e] << flush;
    else
        cout << -1 << flush;
    // system("pause");
    return 0;
}
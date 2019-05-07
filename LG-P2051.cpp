#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>

using namespace std;
struct Edge
{
    int v, w, nxt;
} edge[100050];
struct City
{
    int v, cost, f;
    const bool operator<(const City &a)
    {
        return a.cost < cost;
    }
};
const int INF = 1e9;
int head[1050], e, n, m, c;
int sta[1050][105], flag[1050][105], p[1050];
int s, t, T;
priority_queue<City> Q;
void init()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= 100; j++)
            sta[i][j] = INF;
    sta[s][0] = 0;
    memset(flag, 0, sizeof(flag));
    while (!Q.empty())
        Q.pop();
}
void insert(int x, int y, int w)
{
    edge[e].v = y;
    edge[e].w = w;
    edge[e].nxt = head[x];
    head[x] = e++;
}
int bfs()
{
    City a, b;
    a.v = s, a.cost = 0, a.f = 0;
    Q.push(a);
    while (!Q.empty())
    {
        a = Q.top();
        Q.pop();
        int u = a.v;
        int cost = a.cost;
        int f = a.f;
        flag[u][f] = 1;
        if (u == t)
            return cost;
        if (f + 1 <= c && !flag[u][f + 1] && sta[u][f + 1] > sta[u][f] + p[u])
        {
            sta[u][f + 1] = sta[u][f] + p[u];
            b.v = u;
            b.f = f + 1;
            b.cost = sta[u][f + 1];
            Q.push(b);
        }
        for (int i = head[u]; i != -1; i = edge[i].nxt)
        {
            int v = edge[i].v;
            int w = edge[i].w;
            if (f >= w && !flag[v][f - w] && sta[v][f - w] > cost)
            {
                sta[v][f - w] = cost;
                b.v = v;
                b.f = f - w;
                b.cost = sta[v][f - w];
                Q.push(b);
            }
        }
    }
    return -1;
}
int main()
{
    int x, y, w;
    scanf("%d%d", &n, &m);
    memset(head, -1, sizeof(head));
    e = 0;
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);
    while (m--)
    {
        scanf("%d%d%d", &x, &y, &w);
        insert(x, y, w);
        insert(y, x, w);
    }
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &c, &s, &t);
        init();
        int ans = bfs();
        if (ans != -1)
            printf("%d\n", ans);
        else
            printf("impossible\n");
    }
    return 0;
}
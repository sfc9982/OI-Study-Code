#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

struct Edge
{
    int v, w, nxt;
} edge[100050];

struct City
{
    int v, cost, f;
    bool operator<(const City &a) const
    {
        return a.cost < cost;
    }
};

const int INF = 1e9;
int s, t, T, e, n, m, c;
int to[1050], sta[1050][105], flag[1050][105], p[1050];
priority_queue<City> Q;

inline void add(int x, int y, int w)
{
    edge[e].v = y;
    edge[e].w = w;
    edge[e].nxt = to[x];
    to[x] = e++;
}

int bfs()
{
    City a, b;
    a.v = s;
    a.cost = 0;
    a.f = 0;
    Q.push(a);
    while (!Q.empty())
    {
        a = Q.top();
        Q.pop();
        int u = a.v;
        int cost = a.cost;
        int f = a.f;
        flag[u][f] = -1;
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
        for (int i = to[u]; i != -1; i = edge[i].nxt)
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

int main()
{
    int x, y, w, ans;
    e = 0;
    cin >> n >> m;
    memset(to, -1, sizeof(to));
    for (int i = 0; i < n; i++)
        cin >> p[i];
    while (m--)
    {
        cin >> x >> y >> w;
        add(x, y, w);
        add(y, x, w);
    }
    cin >> T;
    while (T--)
    {
        cin >> c >> s >> t;
        init();
        ans = bfs();
        if (ans != -1)
            cout << ans << endl;
        else
            cout << "impossible" << endl;
    }
    // system("pause");
    return 0;
}

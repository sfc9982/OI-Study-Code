#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int cost[30001], w[10000][10000] = {};
int cnt = 0, ans = 0, cur = 0;

struct str
{
    int x, y, dist;
} e[60001];
int fa[30001];

inline bool cmp(const str &_a, const str &_b)
{
    return _a.dist < _b.dist;
}

inline int f(const int x)
{
    if (fa[x] == x)
        return fa[x];
    return fa[x] = f(fa[x]);
}

void kru()
{
    int fx, fy;
    for (int i = 0; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            cur++;
            e[cur].x = i;
            e[cur].y = j;
            e[cur].dist = w[i][j];
        }
    }
    stable_sort(e, e + cur + 1, cmp);
    for (int i = 1; i <= cur; i++)
    {
        fx = f(e[i].x);
        fy = f(e[i].y);
        if (fx != fy)
        {
            fa[fy] = fx;
            cnt++;
            ans += e[i].dist;
            if (cnt == n)
                break;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
        fa[i] = i;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> w[i][j];
    for (int i = 1; i <= n; i++)
        w[i][0] = w[0][i] = cost[i];
    kru();
    cout << ans << endl;
    system("pause");
    return 0;
}

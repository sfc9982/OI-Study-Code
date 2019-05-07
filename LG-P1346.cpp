#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct str
{
    int u, v, w;
} e[1e6];
int fa[1050];
int n, m, ans;
inline bool cmp(const str &a, const str &b)
{
    return a.w < b.w;
}
int f(int x)
{
    return fa[x] == x ? x : fa[x] = f(fa[x]);
}
void kru()
{
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    int cnt = 0;
    for (int i = 1; i <= m; ++i)
    {
        int u = e[i].u, v = e[i].v;
        int a = f(u), b = f(v);
        if (a != b)
        {
            fa[a] = b;
            ans = e[i].w;
            cnt++;
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        cin >> e[i].u >> e[i].v >> e[i].w;
    sort(e + 1, e + m + 1, cmp);
    kru();
    cout << n - 1 << ' ' << ans << endl;
    return 0;
}

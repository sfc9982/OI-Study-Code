#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct str
{
    int u, v, w;
} e[1000050];

int n, m, ans;
int fa[1050];

inline bool cmp(const str &a, const str &b)
{
    return a.w < b.w;
}

int f(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = f(fa[x]);
}

void kru()
{
    int u, v, a, b, cnt = 0;
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++)
    {
        u = e[i].u;
        v = e[i].v;
        a = f(u);
        b = f(v);
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

    system("pause");
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, m, l, r, x;
long long c[500010], k, a;

inline int lowbit(int x)
{
    return x & (-x);
}

void update(int x, long long y)
{
    while (x <= n)
    {
        c[x] += y;
        x += lowbit(x);
    }
}

long long solve(int x)
{
    long long cnt = 0;
    while (x)
    {
        cnt += c[x];
        x -= lowbit(x);
    }
    return cnt;
}

int main()
{
    scanf("%d%d", &n, &m);
    long long now = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a);
        update(i, a - now);
        now = a;
    }
    while (m--)
    {
        scanf("%d", &x);
        if (x == 1)
        {
            scanf("%d%d%lld", &l, &r, &k);
            update(l, k);
            update(r + 1, -k);
        }
        else
        {
            int s;
            scanf("%d", &s);
            printf("%lld\n", solve(s));
        }
    }
    return 0;
}
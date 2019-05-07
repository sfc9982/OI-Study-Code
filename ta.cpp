#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long c[50150];
int n, q;
int t[1000050];
int val[50050], pre[50050];

struct str
{
    int L, R;
    int o;
} sumv[300010];
long long ans[300010];

inline int lowbit(int x)
{
    return x & (-x);
}

inline bool cmp(const str &_a, const str &_b)
{
    return _a.R < _b.R;
}

long long getSum(int p)
{
    long long ans = 0;
    for (int i = p; i > 0; i -= lowbit(i))
        ans += c[i];
    return ans;
}

void update(int p, int add)
{
    for (int i = p; i <= n + 2; i += lowbit(i))
        c[i] += add;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k;
    int T = 0;
    while (k--)
    {
        cin >> n;
        memset(t, 0, sizeof(t));
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= n; i++)
        {
            cin >> val[i];
            if (t[val[i]] == 0)
            {
                t[val[i]] = i;
                pre[i] = t[val[i]];
            }
            else
            {
                pre[i] = t[val[i]];
                t[val[i]] = i;
            }
        }
        cin >> q;
        for (int i = 1; i <= q; i++)
        {
            cin >> sumv[i].L >> sumv[i].R;
            sumv[i].o = i;
        }
        stable_sort(sumv + 1, sumv + q + 1, cmp);
        int cnt = 1;
        for (int i = 1; i <= n; i++)
        {
            int v = val[i];
            int p = pre[i];
            if (p == i)
                update(p, v);
            else
            {
                update(p, -v);
                update(i, v);
            }
            while (sumv[cnt].R == i)
            {
                ans[sumv[cnt].o] = getSum(sumv[cnt].R) - getSum(sumv[cnt].L - 1);
                cnt++;
            }
        }
        for (int i = 1; i <= q; i++)
            cout << ans[i] << endl;
    }
    // system("pause");
    return 0;
}
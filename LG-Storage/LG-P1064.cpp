#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
long long n, m, tmp = 0, v, s, l, x;
long long f[65][3205], a[65][3], jz[65][3], o[65];
int main()
{
    cin >> n >> m;
    n = n / 10;
    for (int i = 1; i <= m; i++)
    {
        cin >> v >> s >> l;
        v /= 10;
        if (l == 0)
        {
            tmp += 1;
            a[tmp][0] = v;
            jz[tmp][0] = v * s;
            o[i] = tmp;
        }
        else
        {
            if (a[o[l]][1])
            {
                a[o[l]][2] = v;
                jz[o[l]][2] = v * s;
            }
            else
            {
                a[o[l]][1] = v;
                jz[o[l]][1] = v * s;
            }
        }
    }
    for (int i = 1; i <= tmp; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((j - a[i][0]) >= 0)
            {
                f[i][j] = max(f[i - 1][j], f[i - 1][j - a[i][0]] + jz[i][0]);
            }
            else
            {
                f[i][j] = f[i - 1][j];
                continue;
            }
            if ((j - a[i][0] - a[i][1]) >= 0)
                f[i][j] = max(f[i][j], f[i - 1][j - a[i][0] - a[i][1]] + jz[i][0] + jz[i][1]);
            if ((j - a[i][0] - a[i][2]) >= 0)
                f[i][j] = max(f[i][j], f[i - 1][j - a[i][0] - a[i][2]] + jz[i][0] + jz[i][2]);
            if ((j - a[i][0] - a[i][1] - a[i][2]) >= 0)
                f[i][j] = max(f[i][j], f[i - 1][j - a[i][0] - a[i][1] - a[i][2]] + jz[i][0] + jz[i][1] + jz[i][2]);
        }
    }
    cout << f[tmp][n] * 10;
    return 0;
}
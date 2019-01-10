#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int a, b, k, n, m;
long long f[1005][1005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> k >> n >> m;
    f[0][0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }
            f[i][j] = 0;
            if (i > 0)
            {
                f[i][j] = (f[i][j] + f[i - 1][j] * a) % 10007;
            }
            if (j > 0)
            {
                f[i][j] = (f[i][j] + f[i][j - 1] * b) % 10007;
            }
        }
    }
    cout << f[n][m] << endl;
    return 0;
}
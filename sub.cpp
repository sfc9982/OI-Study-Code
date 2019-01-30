#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

bool dp[110][20010];
int cnt, n, t, a[110], pre[110][20010], flag[110];

int main()
{
    while (cin >> n >> t)
    {
        memset(dp, 0, sizeof(dp));
        dp[0][10000] = 1;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= 20000; j++)
            {
                if (dp[i - 1][j])
                {
                    if (i == 1)
                    {
                        dp[i][j + a[i]] = 1;
                        pre[i][j + a[i]] = -1;
                        continue;
                    }
                    if (i == 2)
                    {
                        dp[i][j - a[i]] = 1;
                        pre[i][j - a[i]] = 1;
                        continue;
                    }
                    dp[i][j + a[i]] = 1;
                    pre[i][j + a[i]] = -1;
                    dp[i][j - a[i]] = 1;
                    pre[i][j - a[i]] = 1;
                }
            }
        }
        int x = t + 10000;
        for (int i = n; i >= 1; i--)
        {
            flag[i] = -pre[i][x];
            x += pre[i][x] * a[i];
        }
        cnt = n - 1;
        while (cnt)
        {
            int k = 1;
            while (flag[k] != flag[k + 1] && k <= cnt)
                k++;
            for (int i = k; i <= cnt; i++)
                a[i] = a[i + 1];
            cout << k - 1 << endl;
            cnt--;
        }
    }
    return 0;
}
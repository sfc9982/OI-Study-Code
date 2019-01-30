#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

long long a[300], b[300];
long long dp[30][1000], f[30][1000];
long long ans[300];

bool cmp(int a, int b)
{
    return a < b;
}

int main()
{
    int n, m, T = 0, d;
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> m)
    {
        if (n == 0 || m == 0)
            break;
        memset(dp, 0, sizeof(dp));
        memset(f, -1, sizeof(f));
        T++;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i] >> b[i];
        }
        d = m * 20;
        f[0][d] = 0;
        int t1, t2;
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k <= d * 2; k++)
                if (f[j][k] >= 0)
                {
                    for (int i = 1; i <= n; i++)
                        if (f[j][k] + a[i] + b[i] > f[j + 1][k + a[i] - b[i]])
                        {
                            t1 = j;
                            t2 = k;
                            while (t1 > 0 && dp[t1][t2] != i)
                            {
                                t2 -= a[dp[t1][t2]] - b[dp[t1][t2]];
                                t1--;
                            }
                            if (t1 == 0)
                            {
                                f[j + 1][k + a[i] - b[i]] = f[j][k] + a[i] + b[i];
                                dp[j + 1][k + a[i] - b[i]] = i;
                            }
                        }
                }
        }
        int i = d;
        int j = 0;
        int k = 2 * d;
        while (f[m][i + j] < 0 && f[m][i - j] < 0)
            j++;
        if (f[m][i + j] > f[m][i - j])
            k = i + j;
        else
            k = i - j;
        cout << "Jury #" << T << endl;
        cout << "Best jury has value " << ((k - d + f[m][k]) / 2) << " for prosecution and value " << ((f[m][k] - k + d) / 2) << " for defence:" << endl;
        for (i = 1; i <= m; i++)
        {
            ans[i] = dp[m - i + 1][k];
            k -= a[ans[i]] - b[ans[i]];
        }
        sort(ans + 1, ans + 1 + m, cmp);
        for (i = 1; i <= m; i++)
            cout << " " << ans[i];
        cout << endl
             << endl;
    }
    system("pause");
    return 0;
}

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <climits>
using namespace std;

const int inf = 0x3f3f3f3f;
int dp[500050];
int a[110], b[110];

int main()
{
    int n;
    while (cin >> n)
    {
        memset(dp, -inf, sizeof(dp));
        dp[100000] = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i] >> b[i];
        for (int i = 1; i <= n; i++)
        {
            if (a[i] >= 0)
            {
                for (int j = 200000; j >= a[i]; j--)
                    if (dp[j - a[i]] != -inf)
                        dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
            }
            else
            {
                for (int j = 0; j <= 200000; j++)
                    if (dp[j - a[i]] != -inf)
                        dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
            }
        }
        int ans = 0;
        for (int j = 100001; j <= 200000; j++)
            if (dp[j] != -inf && dp[j] > 0)
                ans = max(ans, j + dp[j] - 100000);
        cout << ans << endl;
    }
    return 0;
}
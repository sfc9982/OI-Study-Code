#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int T, M, ans;
int t[101], w[100], dp[101][1001];
void ZhangXinGang()
{
    cin >> T >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> t[i] >> w[i];
    }
}
int main()
{
    ZhangXinGang();
    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= T; j++)
        {
            if (t[i] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t[i]] + w[i]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    for (int j = 1; j <= T; j++)
        ans = max(ans, dp[M][j]);
    cout << ans;
    return 0;
}
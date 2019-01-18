#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, a[100] = {0};
int ans = 0, dp[100][100], b[100] = {1};

int work()
{
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; i++)
        for (int j = m; j >= i; j--)
            dp[i][j] = max(dp[i - 1][j] + b[m - j + i - 1] * a[i - 1], dp[i][j + 1] + b[m - j + i - 1] * a[j + 1]);
    int maxx = -1;
    for (int i = 1; i <= m; i++)
        maxx = max(maxx, dp[i][i] + a[i] * b[m]);
    return maxx;
}

int main()
{
    for (int i = 1; i <= 99; i++)
        b[i] = b[i - 1] * 2;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> a[j];
        ans += work();
    }
    cout << ans;
    //system("pause");
    return 0;
}
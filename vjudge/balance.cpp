#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int l = 25;
int dp[l][600 * l + 1];
int c[l + 1], w[l + 1];

int main()
{
    int n, m;
    memset(dp, 0, sizeof(dp));
    dp[0][300 * l] = 1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    for (int i = 1; i <= m; i++)
        for (int j = 0; j <= 600 * l; j++)
            if (dp[i - 1][j])
                for (int k = 1; k <= n; k++)
                    dp[i][j + c[k] * w[i]] += dp[i - 1][j];
    cout << dp[m][300 * l] << endl;
    //system("pause");
    return 0;
}

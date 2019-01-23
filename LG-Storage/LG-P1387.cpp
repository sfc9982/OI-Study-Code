#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int dp[105][105][105];
int sum = 1, l;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> dp[i][j][1];
    l = min(n, m);
    for (int len = 2; len <= l; len++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            for (int j = 1; j + len - 1 <= m; j++)
            {
                int k = (len + 1) >> 1;
                if (dp[i][j][k] && dp[i + len - k][j][k] && dp[i][j + len - k][k] && dp[i + len - k][j + len - k][k])
                {
                    dp[i][j][len] = 1;
                    sum = max(sum, len);
                }
            }
        }
    }
    cout << sum << endl;
    //system("pause");
    return 0;
}
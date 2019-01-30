#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

string a, b;
int dp[250][250], f[250];

void solve(int i, int j)
{
    if (dp[i][j] >= 0)
        return;
    solve(i + 1, j);
    if (b[i] == b[j])
    {
        dp[i][j] = dp[i + 1][j];
        return;
    }
    dp[i][j] = dp[i + 1][j] + 1;
    for (int k = i + 1; k <= j - 1; k++)
        if (b[i] == b[k])
        {
            solve(i + 1, k);
            solve(k + 1, j);
            if (dp[i + 1][k] + dp[k + 1][j] < dp[i][j] || dp[i][j] == -1)
            {
                dp[i][j] = dp[i + 1][k] + dp[k + 1][j];
            }
        }
}

int main()
{
    while (cin >> a >> b)
    {
        int len = a.length();
        memset(dp, -1, sizeof(dp));
        memset(f, -1, sizeof(f));
        for (int i = 0; i < len; i++)
            dp[i][i] = 1;
        for (int i = 0; i < len; i++)
            for (int j = i; j < len; j++)
                if (dp[i][j] == -1)
                    solve(i, j);
        if (b[0] != 0)
        {
            f[0] = 0;
            a[0] = 0;
        }
        else
        {
            f[0] = 1;
            a[0] = 1;
        }
    }

    system("pause");
    return 0;
}

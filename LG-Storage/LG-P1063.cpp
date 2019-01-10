#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int num[1050], dp[1050][1050], sum, n;

int main()
{
    memset(dp, 0, sizeof(dp));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        num[i + n] = num[i];
    }
    for (int i = (n << 1) - 2; i > 0; i--)
        for (int j = i + 1; j <= n + i; j++)
            for (int k = i + 1; k < j; k++)
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + num[i] * num[k] * num[j]);
    for (int i = 1; i <= n; i++)
        sum = max(dp[i][i + n], sum);
    cout << sum << endl;
    //system("pause");
    return 0;
}
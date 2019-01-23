#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n, a[10010], dp[10010];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        dp[i] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (a[j] < a[i] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
    for (int i = 2; i <= n; i++)
        dp[i] = max(dp[i - 1], dp[i]);
    cout << dp[n] << endl;
    return 0;
}
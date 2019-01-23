#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

long long dp[1000005], a[1000005], n, sum = 0, mid = 0, ans = 0;

int main()
{
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    dp[0] = 0;
    sum /= n;
    for (long long i = 1; i < n; i++)
        dp[i] = dp[i - 1] - sum + a[i];
    sort(dp, dp + n);
    mid = dp[n / 2];
    for (long long i = 0; i < n; i++)
        ans += abs(dp[i] - mid);
    cout << ans << endl;
    //system("pause")
    return 0;
}

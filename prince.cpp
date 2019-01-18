#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

const int inf = INT_MAX;
int dp[70000], sta[70000], a[70000], b[70000];

int main()
{
    int t, k = 1, n, p, q, ans;
    cin >> t;
    while (t--)
    {
        cin >> n >> p >> q;
        ans = 0;
        memset(sta, 0, sizeof(sta));
        for (int i = 1; i <= p + 1; i++)
        {
            cin >> a[i];
            sta[a[i]] = i;
        }
        for (int i = 1; i <= q + 1; i++)
        {
            cin >> n;
            b[i] = sta[n];
            dp[i] = inf;
        }
        for (int i = 1; i <= q + 1; i++)
        {
            int x = lower_bound(dp + 1, dp + 1 + i, b[i]) - dp;
            dp[x] = b[i];
            ans = max(ans, x);
        }
        cout << "Case " << k++ << ": " << ans << endl;
    }
    // system("pause");
    return 0;
}

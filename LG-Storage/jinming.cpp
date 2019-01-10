#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int m, n, v[30], p[30], ans;

void dfs(int i, int old, int now)
{
    if (i == n + 1)
    {
        ans = max(ans, now);
        return;
    }
    dfs(i + 1, old, now);
    if (old >= v[i])
    {
        dfs(i + 1, old - v[i], now + v[i] * p[i]);
    }
}

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> p[i];
    }
    ans = 0;
    dfs(1, m, 0);
    cout << ans << endl;
    return 0;
}
#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

const int inf = INT_MAX;

int n, m, T, dp[1000010];

struct str
{
    int a, b, c;
} w[1000010];

bool cmp(str a, str b)
{
    return a.c * b.b <= b.c * a.b;
}

int main()
{
    cin >> T >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i].a;
    for (int i = 1; i <= n; i++)
        cin >> w[i].b;
    for (int i = 1; i <= n; i++)
        cin >> w[i].c;
    dp[0] = 0;
    sort(w + 1, w + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        for (int j = T; j >= w[i].c; j--)
        {
            if (j - w[i].c < 0)
            {
                dp[j] = max(dp[j], w[i].a - (j * w[i].b));
                continue;
            }
            dp[j] = max(dp[j], dp[j - w[i].c] + w[i].a - (j * w[i].b));
        }
    int sum = 0;
    for (int i = 1; i <= T; i++)
        sum = max(sum, dp[i]);
    cout << sum << endl;
    system("pause");
    return 0;
}
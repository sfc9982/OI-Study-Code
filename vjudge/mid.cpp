#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct str
{
    int x, y;
} num[1010];
int c, n, sum, dx, dy, d[1010][1010], b[10010];

void work()
{
    sort(b + 1, b + sum + 1);
    sum = unique(b + 1, b + sum + 1) - b - 1;
    for (int i = 1; i <= n; i++)
    {
        dx = lower_bound(b + 1, b + sum + 1, num[i].x) - b;
        dy = lower_bound(b + 1, b + sum + 1, num[i].y) - b;
        d[dx][dy]++;
    }
    b[++sum] = 10001;
    for (int i = 1; i <= sum; i++)
        for (int j = 1; j <= sum; j++)
            d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + d[i][j];
}

bool ok(int now)
{
    int p;
    if (now >= b[sum])
    {
        return true;
    }
    p = upper_bound(b + 1, b + sum + 1, b[sum] - now + 1) - b - 1;
    for (int i = 1; i <= p; i++)
    {
        for (int j = 1; j <= p; j++)
        {
            dx = upper_bound(b + 1, b + sum + 1, b[i] + now - 1) - b - 1;
            dy = upper_bound(b + 1, b + sum + 1, b[j] + now - 1) - b - 1;
            if (d[dx][dy] - d[i - 1][dy] - d[dx][j - 1] + d[i - 1][j - 1] >= c)
                return true;
        }
    }
    return false;
}

int main()
{
    cin >> c >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i].x >> num[i].y;
        b[++sum] = num[i].x;
		b[++sum] = num[i].y;
	}
	work();
    int l = 1, r = 10000;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (ok(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
    return 0;
}

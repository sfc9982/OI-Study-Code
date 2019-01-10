#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

long long l, r, mid;
long long zuo, you, sum, ans, R, n;
long long x, y, w, h, i, maxx = -1;

struct rctStr
{
    long long x, y, xx, h;
    long long s;
} ta[10010];

long long td(long mid)
{
    int i;
    long long s1, s2;
    s1 = 0;
    s2 = 0;
    for (i = 0; i <= n; i++)
    {
        if (ta[i].xx <= mid)
            s1 += ta[i].s;
        else if (ta[i].x >= mid)
            s2 += ta[i].s;
        else
        {
            s1 += (mid - ta[i].x) * ta[i].h;
            s2 += (ta[i].xx - mid) * ta[i].h;
        }
    }
    return s1 - s2;
}
int main()
{
    cin >> R >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> x >> y >> w >> h;
        ta[i].x = x;
        ta[i].y = y;
        ta[i].xx = x + w;
        ta[i].h = h;
        ta[i].s = w * h;
        if (x + w > maxx)
            maxx = x + w;
    }
    l = 0;
    r = R;
    while (l + 1 < r)
    {
        mid = (l + r) / 2;
        sum = td(mid);
        if (sum > 0)
            r = mid;
        else if (sum <= 0)
            l = mid;
        else if (sum == 0)
        {
            cout << mid;
            return 0;
        }
    }
    zuo = td(l);
    you = td(r);
    if (abs(zuo) >= abs(you))
        ans = r;
    else
        ans = l;
    if (ans == maxx)
        ans = R;
    cout << ans << endl;
    return 0;
}
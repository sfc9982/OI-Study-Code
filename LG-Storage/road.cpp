#include <iostream>
#include <algorithm>
using namespace std;

int last[100005], n, m, cnt, k;

struct point
{
    int tou;
    int over;
    int wei;
} a[100005];

int finish(int x)
{
    if (last[x] != x)
        last[x] = finish(last[x]);
    return last[x];
}

void jia(int x, int y)
{
    int fa = finish(x);
    int fb = finish(y);
    if (fa != fb)
        last[fa] = fb;
}

bool cmp(point a, point b)
{
    if (a.wei < b.wei)
        return true;
    else
        return false;
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].tou >> a[i].over >> a[i].wei;
    }

    for (int i = 1; i <= n; i++)
    {
        last[i] = i;
    }

    sort(a + 1, a + m + 1, cmp);

    for (int i = 1; i <= m; i++)
    {
        if (finish(a[i].tou) != finish(a[i].over))
        {
            jia(a[i].tou, a[i].over);
            cnt = max(cnt, a[i].wei);
            k++;
        }
        if (k == n - 1)
        {
            break;
        }
    }

    if (k == n - 1)
    {
        cout << cnt << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}
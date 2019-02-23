#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

bool ok;
long long h[5000], sum[5000], low[5000];

struct str
{
    double l, r;
} a[1010];

bool cmp(str a, str b)
{
    return a.l * a.r < b.l * b.r;
}

void times(long long x)
{
    long long t = 0;
    for (long long i = 1; i <= h[0]; i++)
    {
        h[i] = h[i] * x + t;
        t = h[i] / 10;
        h[i] %= 10;
        if (t > 0 && i >= h[0])
            h[0]++;
    }
}

void div(long long x)
{
    long long t = 0;
    ok = true;
    memset(sum, 0, sizeof(sum));
    for (long long i = h[0]; i > 0; i--)
    {
        sum[i] = (h[i] + 10 * t) / x;
        t = (h[i] + 10 * t) % x;
        if (sum[i] && ok)
        {
            sum[0] = i;
            ok = false;
        }
    }
}

bool status(long long b[], long long w[])
{
    if (b[0] > w[0])
        return false;
    if (b[0] < w[0])
        return true;
    for (long long i = b[0]; i > 0; i--)
    {
        if (b[i] < w[i])
            return true;
        if (b[i] > w[i])
            return false;
    }
    return false;
}

void Print(long long b[])
{
    long long i;
    for (i = b[0]; i > 0 && b[i] == 0; i--)
        ;
    for (; i > 0; i--)
        cout << b[i];
    cout << endl;
}

int main()
{
    long long n;
    cin >> n;
    for (int i = 0; i <= n; i++)
        cin >> a[i].l >> a[i].r;
    stable_sort(a + 1, a + 1 + n, cmp);
    h[0] = 1;
    h[1] = 1;
    for (int i = 0; i < n; i++)
    {
        times(a[i].l);
        div(a[i + 1].r);
        if (status(low, sum))
            memcpy(low, sum, sizeof(sum));
    }
    Print(low);
    system("pause");
    return 0;
}
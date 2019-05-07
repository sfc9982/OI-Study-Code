#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

long long n, m, fib[150];

struct v
{
    long long l, r;
    long long e, fib;
    long long flag, len;
} a[10000000];

void makefib()
{
    fib[0] = 1;
    fib[1] = 1;
    for (long long i = 2; i < 80; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    return;
}
s
void push_low(long long i, long long m)
{
    if (a[i].flag)
    {
        a[i << 1].flag = a[i << 1 + 1].flag = a[i].flag;
        a[i << 1].len = a[i].flag * (m - m >> 1);
        a[i << 1 + 1].len = a[i].flag * (m >> 1);
        a[i << 1].e = a[i << 1].fib;
        a[i << 1 + 1].e = a[i << 1 + 1].fib;
        a[i].flag = 0;
    }
}

void push(long long i)
{
    a[i].e = a[i << 1].e + a[i << 1 + 1].e;
    a[i].fib = a[i << 1].fib + a[i << 1 + 1].fib;
}

void build(long long l, long long r, long long i)
{
    a[i].l = l;
    a[i].r = r;
    a[i].e = 0;
    a[i].flag = 0;
    a[i].len = 0;
    if (l == r)
    {
        a[i].fib = 1;
        return;
    }
    long long mid = (l + r) >> 1;
    build(l, mid, i << 1);
    build(mid + 1, r, i << 1 + 1);
    push(i);
}

void add(long long t, long long m, long long l, long long r, long long i)
{
    if (t < l || t > r)
        return;
    if (l == r)
    {
        if (a[i].flag)
        {
            a[i].e = m + a[i].fib;
            a[i].flag = 0;
            a[i].len = 0;
        }
        else
            a[i].e += m;
        long long low = lower_bound(fib, fib + 80, a[i].e) - fib;
        if (!low)
            a[i].fib = 1;
        else if (abs(a[i].e - fib[low]) < abs(a[i].e - fib[low - 1]))
            a[i].fib = fib[low];
        else
            a[i].fib = fib[low - 1];
        return;
    }
    push_low(i, r - l + 1);
    long long mid = (l + r) >> 1;
    if (t <= mid)
        add(t, m, l, mid, i << 1);
    else
        add(t, m, mid + 1, r, i << 1 + 1);
    push(i);
}

long long query(long long L, long long R, long long l, long long r, long long i)
{
    if (R < l || L > r)
        return 0;
    else if (L <= l && R >= r)
        return a[i].e;
    push_low(i, r - l + 1);
    long long ans = 0;
    long long mid = (l + r) >> 1;
    if (L <= mid)
        ans += query(L, R, l, mid, i << 1);
    if (R > mid)
        ans += query(L, R, mid + 1, r, i << 1 + 1);
    return ans;
}

void update(long long L, long long R, long long l, long long r, long long i)
{
    if (R < l || L > r)
        return;
    if (L <= l && R >= r)
    {
        a[i].e = a[i].fib;
        a[i].flag = 1;
        a[i].len = r - l + 1;
        return;
    }
    push_low(i, r - l + 1);
    long long mid = (l + r) >> 1;
    if (L <= mid)
        update(L, R, l, mid, i << 1);
    if (R > mid)
        update(L, R, mid + 1, r, i << 1 + 1);
    push(i);
}

int main()
{
    while (cin >> n >> m)
    {
        build(1, n, 1);
        while (m--)
        {
            long long x;
            cin >> x;
            if (x == 1)
            {
                long long low, q;
                cin >> low >> q;
                add(low, q, 1, n, 1);
            }
            else
            {
                long long l, r;
                cin >> l >> r;
                if (x == 2)
                    cout << query(l, r, 1, n, 1) << endl;
                else
                    update(l, r, 1, n, 1);
            }
        }
    }
    return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
long long p;
long long sumv[1000050 * 3], add1[1000050], add2[1000050];

void push(int o)
{
    sumv[o] = (sumv[o * 2] + sumv[o * 2 + 1]) % p;
}

void push_low(int l, int r, int o)
{
    int mid = (l + r) / 2;
    sumv[o * 2] = (sumv[o * 2] * add1[o] + add2[o] * (mid - l + 1)) % p;
    sumv[o * 2 + 1] = (sumv[o * 2 + 1] * add1[o] + add2[o] * (r - mid)) % p;
    add1[o * 2] = (add1[o * 2] * add1[o]) % p;
    add1[o * 2 + 1] = (add1[o * 2 + 1] * add1[o]) % p;
    add2[o * 2] = (add2[o * 2] * add1[o] + add2[o]) % p;
    add2[o * 2 + 1] = (add2[o * 2 + 1] * add1[o] + add2[o]) % p;
    add1[o] = 1;
    add2[o] = 0;
}

void update(int l, int r, int o, int L, int R, long long x)
{
    if (l >= L && r <= R)
    {
        add2[o] = (add2[o] + x) % p;
        sumv[o] = (sumv[o] + x * (r - l + 1)) % p;
        return;
    }
    int mid = (l + r) / 2;
    push_low(l, r, o);
    if (mid >= L)
        update(l, mid, o * 2, L, R, x);
    if (mid <= R - 1)
        update(mid + 1, r, o * 2 + 1, L, R, x);
    push(o);
}

void update2(int l, int r, int o, int L, int R, long long x)
{
    if (l >= L && r <= R)
    {
        add1[o] = (add1[o] * x) % p;
        add2[o] = (add2[o] * x) % p;
        sumv[o] = (sumv[o] * x) % p;
        return;
    }
    int mid = (l + r) / 2;
    push_low(l, r, o);
    if (mid >= L)
        update2(l, mid, o * 2, L, R, x);
    if (mid <= R - 1)
        update2(mid + 1, r, o * 2 + 1, L, R, x);
    push(o);
}

long long query(int l, int r, int o, int L, int R)
{
    if (l >= L && r <= R)
        return sumv[o];
    int mid = (l + r) / 2;
    push_low(l, r, o);
    long long ans = 0;
    if (mid >= L)
        ans += query(l, mid, o * 2, L, R);
    if (mid <= R - 1)
        ans += query(mid + 1, r, o * 2 + 1, L, R);
    return ans % p;
}

void build(int l, int r, int o)
{
    add1[o] = 1;
    if (l == r)
    {
        cin >> sumv[o];
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, o * 2);
    build(mid + 1, r, o * 2 + 1);
    push(o);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> p;
    build(1, n, 1);
    for (int i = 1; i <= m; i++)
    {
        int k, L, R;
        long long v;
        cin >> k;
        if (k == 1)
        {
            cin >> L >> R >> v;
            update2(1, n, 1, L, R, v);
        }
        if (k == 2)
        {
            cin >> L >> R >> v;
            update(1, n, 1, L, R, v);
        }
        if (k == 3)
        {
            cin >> L >> R;
            cout << query(1, n, 1, L, R) << flush;
            if (i != m)
                cout << endl;
        }
    }
    system("pause");
    return 0;
}

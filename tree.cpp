#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, T, l, r;
long long c[500010], k, a;

inline int lowbit(int op)
{
    return op & (-op);
}

void update(int op, long long y)
{
    for (; op <= n; op += lowbit(op))
        c[op] += y;
}

long long query(int op)
{
    long long cnt;
    for (cnt = 0; op; op -= lowbit(op))
        cnt += c[op];
    return cnt;
}

int main()
{
    cin >> n >> T;
    long long cur = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        update(i, a - cur);
        cur = a;
    }
    while (T--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            cin >> l >> r >> k;
            update(l, k);
            update(r + 1, -k);
        }
        else
        {
            int s;
            cin >> s;
            cout << query(s) << endl;
        }
    }
    // system("pause");
    return 0;
}
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, t;
int a[500050], b[500050];

int main()
{
    while (cin >> n && n)
    {
        for (int i = 0; i < n; i++)
            cin >> b[i];
        cin >> m;
        if (m < 5)
        {
            cout << m << endl;
            continue;
        }
        stable_sort(b, b + n);
        memset(a, 0, sizeof(a));
        t = m - 5;
        for (int i = 0; i <= t; i++)
            if (b[0] <= i)
                a[i] = b[0];
        for (int i = 1; i < n - 1; i++)
            for (int j = t; j >= 0; j--)
                if (j >= b[i])
                    a[j] = max(a[j], a[j - b[i]] + b[i]);
        m -= a[t] + b[n - 1];
        cout << m << endl;
    }
    return 0;
}
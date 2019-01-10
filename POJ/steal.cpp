#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n, q, p[2018], l[2018], r[2018], w[2018];
int main()
{
    freopen("steal.in", "r", stdin);
    freopen("steal.out", "w", stdout);
    w[1] = 1;
    l[1] = p[1];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 0; i <= n; i++)
        l[i] = 0;
    for (int i = 2; i <= n; i++)
    {
        q = -123456789;
        for (int j = 0; j < i; j++)
        {
            //q = max(q, p[j] + l[i - j]);
            if (q < l[j] + p[i - j])
            {
                q = l[j] + p[i - j];
                w[i] = i - j;
            }
        }
        l[i] = q;
    }
    cout << l[n] << endl;
    int k = n;
    while (k > 0)
    {
        cout << w[k] << " ";
        k = k - w[k];
    }
    //system("pause");
    return 0;
}

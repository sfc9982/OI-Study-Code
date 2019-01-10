#include <iostream>
using namespace std;

int m, n, ans, k;
int a[200505], line[400505][2], e[200505], ed[200505], f[200505];

int find(int x)
{
    while (a[x] != x)
        x = a[x] = a[a[x]];
    return x;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
        f[i] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> line[i][0] >> line[i][1];
    }
    cin >> k;
    for (int i = k; i >= 1; i--)
    {
        cin >> e[i];
        a[e[i]] = -1;
        f[i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        if (a[line[i][0]] != -1 && a[line[i][1]] != -1)
        {
            x = find(line[i][0]), y = find(line[i][1]);
            if (x == y)
            {
                continue;
            }
            a[x] = a[y];
            ans--;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (f[i] == 1)
        {
            ans++;
        }
    }
    ed[k] = ans;
    for (int j = 1; j <= k; j++)
    {
        a[e[j]] = e[j];
        ans++; //f[e[i]]=1;
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            if (a[line[i][0]] != -1 && a[line[i][1]] != -1)
            {
                x = find(line[i][0]);
                y = find(line[i][1]);
                if (x == y)
                {
                    continue;
                }
                a[x] = a[y];
                ans--;
            }
        }
        ed[k - j] = ans;
    }
    for (int i = 0; i <= k; i++)
    {
        cout << ed[i] << endl;
    }
    return 0;
}
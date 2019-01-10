#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int cha1[50050], cha2[50050];
int vis[50050];
int c[50050];
int l1[50050], l2[50050];
int si = 1, n, ans = 0;

void Build()
{
    c[1] = 1;
    c[2] = l1[1];
    vis[c[1]] = vis[c[2]] = 1;
    for (int i = 2; i <= n - 1; i++)
    {
        if (c[i - 1] == l1[c[i]])
            c[i + 1] = l2[c[i]], vis[c[i + 1]] = 1;
        else if (c[i - 1] == l2[c[i]])
            c[i + 1] = l1[c[i]], vis[c[i + 1]] = 1;
        else
        {
            si = 0;
            cout << -1;
            return;
        }
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            si = 0;
    cout << -1;
}
void Simulation()
{
    for (int i = 1; i <= n; i++)
    {
        cha1[(c[i] - i + n) % n]++;
        cha2[(c[n - i + 1] - i + n) % n]++;
    }
    for (int i = 0; i <= n - 1; i++)
        ans = max(ans, max(cha1[i], cha2[i]));
    cout << n - ans;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> l1[i] >> l2[i];
    }
    Build();
    if (si)
        Simulation();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
bool vis[10000];
vector<int> dfs[10000];
int i, j, m, n, x, y;
int mp[10000], h[10000];
void Search(int k)
{
    int head = 0, tail = 1;
    h[1] = k;
    mp[k] = k;
    vis[k] = true;
    while (head < tail)
    {
        head++;
        if (dfs[h[head]].size() != 0)
            for (j = 0; j <= dfs[h[head]].size() - 1; j++)
                if (vis[dfs[h[head]][j]] == false)
                {
                    vis[dfs[h[head]][j]] = true;
                    mp[dfs[h[head]][j]] = k;
                    tail++;
                    h[tail] = dfs[h[head]][j];
                }
    }
}
int main()
{
    cin >> n >> m;
    for (i = 1; i <= n; i++)
        vis[i] = false;
    for (i = 1; i <= m; i++)
    {
        cin >> x >> y;
        dfs[y].push_back(x);
    }
    for (i = n; i >= 1; i--)
        if (vis[i] == false)
            Search(i);
    for (i = 1; i <= n; i++)
        cout << mp[i] << ' ';
    return 0;
}
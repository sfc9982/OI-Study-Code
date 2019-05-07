#include <bits/stdc++.h>
using namespace std;
struct Str
{
    int x1, y1, x2, y2, color;
} a[17];
vector<int> G[17];
int n, s = 1000000, flag[17];
int chack(int w)
{
    int t = G[w].size();
    for (int i = 0; i < t; i++)
    {
        if (flag[G[w][i]] == 0)
            return 0;
    }
    return 1;
}
void dfs(int cnt, int sum, int lst)
{
    if (cnt == n)
    {
        s = min(s, sum);
        return;
    }
    if (sum >= s)
        return;
    for (int i = 1; i <= n; i++)
    {
        if (flag[i] == 0 && chack(i) == 1)
        {
            flag[i] = 1;
            dfs(cnt + 1, sum + (lst != a[i].color), a[i].color);
            flag[i] = 0;
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2 >> a[i].color;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j && a[i].x1 == a[j].x2 && (a[i].y2 >= a[j].y1 && a[i].y1 <= a[j].y2))
                G[i].push_back(j);
        }
    }
    dfs(0, 0, 0);
    cout << s << endl;
    return 0;
}
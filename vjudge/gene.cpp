#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

map<char, int> f;
bool flag[1050][1050];
char dp[1050][1050], s1[1050], s2[1050];
int ans[1050][1050];
int p1[1050], p2[1050];

int mapp[5][5] =
    {{5, -1, -2, -1, -3},
     {-1, 5, -3, -2, -4},
     {-2, -3, 5, -2, -2},
     {-1, -2, -2, 5, -1},
     {-3, -4, -2, -1, 0}};

int dfs(int x, int y)
{
    int t = 0;
    if (x == -1)
    {
        for (int i = 0; i <= y; i++)
            t += mapp[p2[i]][4];
        return t;
    }
    if (y == -1)
    {
        for (int i = 0; i <= x; i++)
            t += mapp[4][p1[i]];
        return t;
    }
    if (flag[x][y])
        return ans[x][y];
    flag[x][y] = true;
    ans[x][y] = max(dfs(x - 1, y - 1) + mapp[p1[x]][p2[y]], max(dfs(x, y - 1) + mapp[4][p2[y]], dfs(x - 1, y) + mapp[p1[x]][4]));

    return ans[x][y];
}
int main()
{
    f['A'] = 0;
    f['C'] = 1;
    f['G'] = 2;
    f['T'] = 3;
    f['-'] = 4;
    int n1, n2;
    cin >> n1 >> s1 >> n2 >> s2;
    for (int i = 0; i < n1; i++)
        p1[i] = f[s1[i]];
    for (int i = 0; i < n2; i++)
        p2[i] = f[s2[i]];
    memset(flag, 0, sizeof(flag));
    cout << dfs(n1 - 1, n2 - 1) << endl;
    return 0;
}
#include <iostream>
#include <cstring>
#include <stack>
#include <map>
using namespace std;

const int mod = 1000000007;
int dp[750][750][3][3];
string ss;
stack<int> s;
map<int, int> pos;

void right()
{
    for (int i = 0; i < ss.size(); ++i)
    {
        if (ss[i] == '(')
            s.push(i);
        else
        {
            pos[i] = s.top();
            pos[s.top()] = i;
            s.pop();
        }
    }
}

void dfs(int l, int r)
{
    if (l + 1 == r)
    {
        dp[l][r][0][1] = dp[l][r][1][0] = 1;
        dp[l][r][0][2] = dp[l][r][2][0] = 1;
        return;
    }
    if (pos[l] == r)
    {
        dfs(l + 1, r - 1);
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
            {
                if (j != 1)
                    dp[l][r][0][1] = (dp[l][r][0][1] + dp[l + 1][r - 1][i][j]) % mod;
                if (j != 2)
                    dp[l][r][0][2] = (dp[l][r][0][2] + dp[l + 1][r - 1][i][j]) % mod;
                if (i != 1)
                    dp[l][r][1][0] = (dp[l][r][1][0] + dp[l + 1][r - 1][i][j]) % mod;
                if (i != 2)
                    dp[l][r][2][0] = (dp[l][r][2][0] + dp[l + 1][r - 1][i][j]) % mod;
            }
        return;
    }
    int mid = pos[l];
    dfs(l, mid);
    dfs(mid + 1, r);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
                for (int s = 0; s < 3; ++s)
                    if (!(k == 1 && s == 1) && !(k == 2 && s == 2))
                        dp[l][r][i][j] = (dp[l][r][i][j] + dp[l][mid][i][k] * dp[mid + 1][r][s][j]) % mod;
}

int main()
{
    getline(cin, ss);
    right();
    dfs(0, ss.size() - 1);
    int ans = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            ans = (ans + dp[0][ss.size() - 1][i][j]) % mod;
    cout << ans << endl;
    //system("pause");
    return 0;
}
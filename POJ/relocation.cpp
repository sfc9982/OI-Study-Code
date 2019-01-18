#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 0x3f3f3f3f;
int w[105], dp[1050], flag[1050];
int n, t, c, c1, c2, sum;

bool judge(int x)
{
    int sum = 0;
    memset(flag, false, sizeof(flag));
    flag[0] = true;
    for (int i = 0; i < n; i++)
    {
        if (x)
        {
            sum += w[i];
            for (int j = c1; j >= w[i]; j--)
                if (flag[j - w[i]])
                    flag[j] = true;
        }
    }
    if (sum > c1 + c2)
        return false;
    for (int i = 0; i <= c1; i++)
        if (flag[i] && sum - i <= c2)
            return true;
    return false;
}

int main()
{
    cin >> t;
    while (t--)
    {
        c++;
        cin >> n >> c1 >> c2;
        memset(dp, MAX, sizeof(dp));
        for (int i = 0; i < n; i++)
            cin >> w[i];
        dp[0] = 0;
        sum = 0;
    }
    system("pause");
    return 0;
}

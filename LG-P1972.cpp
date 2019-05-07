#include <iostream>

using namespace std;

int n, m, sum = 0, ans = 0;
int f[50][30500][30500], a[30500];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < (1 << m); i++)
    {
        int num = 0;
        for (int j = 0; j < m; j++)
        {
            if ((i >> j) & 1)
                ++num;
        }
        if (num <= 2)
            a[++sum] = i;
    }
    f[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            int t = a[j];
            for (int k = 0; k < (1 << m); k++)
            {
                for (int l = 0; l < (1 << m); l++)
                {
                    if ((k & l) || (l & t))
                        continue;
                    f[i][t ^ k][(t & k) | l] = (f[i][t ^ k][(t & k) | l] + f[i - 1][k][l]) % 9999973;
                }
            }
        }
    }
    for (int k = 0; k < (1 << m); k++)
        for (int l = 0; l < (1 << m); l++)
            ans = (ans + f[n][k][l]) % 9999973;
    cout << ans << endl;
    return 0;
}
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

char s[1050];
int p[1050][1050], f[1050];
int t, l;

int main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> (s + 1);
        l = strlen(s + 1);
        memset(p, 0, sizeof(p));
        for (int i = 1; i <= l; i++)
        {
            int x = 0;
            while (i - x > 0 && i + x <= l && s[i - x] == s[i + x])
            {
                p[i - x][i + x] = 1;
                x++;
            }
            x = 1;
            while (i - x > 0 && i + x - 1 <= l && s[i - x] == s[i + x - 1])
            {
                p[i - x][i + x - 1] = 1;
                x++;
            }
        }
        f[0] = -1;
        for (int i = 1; i <= l; i++)
        {
            f[i] = i - 1;
            for (int j = 0; j < i; j++)
            {
                if (p[j + 1][i])
                {
                    f[i] = min(f[i], f[j] + 1);
                }
            }
        }
        cout << f[l] << endl;
    }

    //system("pause");
    return 0;
}

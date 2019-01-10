#include <iostream>
#include <cstring>
using namespace std;

int len = 100;
int a[101] = {}, ans[101] = {}, n, x, total;

void add(int *des, int *ori)
{
    for (int i = 1; i <= len; i++)
        des[i] = des[i] + ori[i];
    for (int i = 1; i <= len; i++)
    {
        des[i + 1] += des[i] / 10;
        des[i] %= 10;
    }
}

int main()
{
    memset(ans,0,sizeof(ans));
    cin >> n;
    for (int k = 1; k <= n; k++)
    {
        memset(a, 0, sizeof(a));
        a[1] = 1;
        for (int i = 1; i <= k; i++)
        {
            x = 0;
            for (int j = 1; j <= len; j++)
                if (a[j] != 0 || x != 0)
                {
                    a[j] = a[j] * i + x;
                    x = a[j] / 10;
                    a[j] %= 10;
                }
        }
        add(ans, a);
    }
    while (a[len] == 0 && len > 0)
        len--;
    for (int i = len; i >= 1; i--)
        cout << ans[i];
    return 0;
}
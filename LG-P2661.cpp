#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int tar, rnd = 0, t, pre[200050];
bool flag[200050];

void getRt(int x)
{
    if ((flag[x] && x == tar) || (pre[x] == x))
    {
        return;
    }
    else if (flag[x] && x != tar)
    {
        t = 0;
        return;
    }
    else
    {
        flag[x] = true;
        t++;
        getRt(pre[x]);
    }
}

int main()
{
    int n;
    memset(pre, 0, sizeof(pre));
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> pre[i];
    for (int i = 1; i <= n; i++)
    {
        memset(flag, 0, sizeof(flag));
        t = 0;
        tar = i;
        getRt(i);
        rnd = max(rnd, t);
    }
    cout << rnd << endl;
    system("pause");
    return 0;
}

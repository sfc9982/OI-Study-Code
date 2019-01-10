#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;

long long n, num[1005], pre[1005], amax = INT_MAX, amin = 0;
long long dpmin[10005][10005], dpmax[10005][10005];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        num[i + n] = num[i];
    }
    for (int i = 1; i <= 2 * n; ++i)
        pre[i] = pre[i - 1] + num[i];

    for (int r = 2; r <= n; r++)
        for (int i = 1; i <= 2 * n - r + 1; i++)
        {
            int dis = i + r - 1;
            dpmax[i][dis] = INT_MAX;
            dpmin[i][dis] = 0;
            for (int k = i; k < dis; k++)
            {
                dpmax[i][dis] = min(dpmax[i][dis], dpmax[i][k] + dpmax[k + 1][dis] + pre[dis] - pre[i - 1]);
                dpmin[i][dis] = max(dpmin[i][dis], dpmin[i][k] + dpmin[k + 1][dis] + pre[dis] - pre[i - 1]);
            }
        }
    for (int i = 1; i <= n; ++i)
    {
        amin = max(amin, dpmin[i][i + n - 1]);
        amax = min(amax, dpmax[i][i + n - 1]);
    }
    cout << amax << endl;
    cout << amin << endl;
    //system("pause");
    return 0;
}

//Prim
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int flag[10005];
double cnt[10005];
double near[10005];
double mins[10005];
double x[10005], y[10005];
double dist(int a, int b)
{
    return sqrt(1.0 * (x[a] - x[b]) * (x[a] - x[b]) + 1.0 * (y[a] - y[b]) * (y[a] - y[b]));
}
int main()
{
    int T;
    int s, p;
    cin >> T;
    while (T--)
    {
        int cnt = 1;
        memset(flag, 0, sizeof(flag));
        cin >> s >> p;
        for (int i = 0; i < p; i++)
            cin >> x[i] >> y[i];
        flag[0] = 1;
        for (int i = 0; i < p; i++)
            if (!flag[i])
            {
                cnt[i] = dist(i, 0);
                near[i] = 0;
            }
        while (cnt < p)
        {
            double min1 = 10000000;
            int k;
            for (int i = 0; i < p; i++)
                if (!flag[i])
                {
                    if (min1 > cnt[i])
                    {
                        k = i;
                        min1 = cnt[i];
                    }
                }
            flag[k] = 1;
            mins[cnt - 1] = min1;
            cnt++;
            for (int i = 0; i < p; i++)
                if (!flag[i])
                {
                    if (cnt[i] > dist(k, i))
                    {
                        cnt[i] = dist(k, i);
                        near[i] = k;
                    }
                }
        }
        sort(mins, mins + cnt - 1);
        printf("%.2lf\n", mins[cnt - 1 - s]);
    }
    return 0;
}

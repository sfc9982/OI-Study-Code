#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const double PI = 3.1415926;

int n, bx, by, ex, ey;
int order[10];
double ans = 0.0;
double ri[10];

struct round1
{
    int x;
    int y;
    double r;
} a[7];

int small(int a, int b, int c, int d)
{
    int ans = min(a, min(b, min(c, d)));
    return ans;
}

double dist(int i, int j)
{
    return sqrt((a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y));
}

double work()
{
    double s = 0.0;
    for (int i = 1, cur; i <= n; ++i)
    {
        cur = order[i];
        ri[cur] = a[cur].r;
        for (int j = 1; j < i; ++j)
        {
            ri[cur] = min(ri[cur], dist(cur, order[j]) - ri[order[j]]);
        }
        if (ri[cur] < 0)
        {
            ri[cur] = 0.0;
        }
        s += PI * ri[cur] * ri[cur];
    }
    return s;
}

int main()
{
    cin >> n >> bx >> by >> ex >> ey;
    for (int i = 1; i <= n; i++)
    {
        order[i] = i;
        cin >> a[i].x >> a[i].y;
        a[i].r = small(abs(a[i].x - bx), abs(a[i].x - ex), abs(a[i].y - by), abs(a[i].y - ey));
    }
    do
    {
        ans = max(ans, work());
    } while (next_permutation(order + 1, order + n + 1));
    cout << (int)round(abs((bx - ex) * (by - ey)) - ans) << endl;

    system("pause");
    return 0;
}

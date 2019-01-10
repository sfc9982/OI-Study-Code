#include <iostream>
#include <cstdio>
using namespace std;
int map[100001][100001];
int n, x, y;
int b = 1;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int ii = 1; ii <= 4; ++ii)
            cin >> map[i][ii];
    }
    cin >> x >> y;
    for (int q = n; q >= 1; --q)
    {
        if ((map[q][1] <= x) && (map[q][3] + map[q][1] >= x) && (map[q][2] <= y) && (map[q][2] + map[q][4] >= y))
        {
            cout << q;
            b = 2;
        }
        if (b == 2)
            break;
        if (q == 1)
        {
            cout << -1;
            break;
        }
    }
    return 0;
}

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int map[102][102], f[102][102];

int main()
{
    int n;
    memset(map, 0, sizeof(map));
    memset(f, 0, sizeof(f));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        f[i][1] = map[i][1] + f[i - 1][1];
        f[1][i] = map[1][i] + f[1][i - 1];
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + map[i][j];
        }
    }
    cout << f[n][n] << endl;
    //system("pause");
    return 0;
}

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int n, m;
int hx, hy;
int ans[405][405], map[405][405];
int jump[8][2] = {{-2, 1}, {-1, 2}, {2, 1}, {1, 2}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

void Search(int x, int y, int stp, int sum)
{
    if (stp > 600)
    {
        return;
    }

    if (ans[x][y] > stp || map[x][y] == 0)
    {
        ans[x][y] = stp;
        map[x][y] = 1;
        sum++;
    }

    for (int i = 0; i < 8; i++)
    {
        int c;
        c = x + jump[i][0];
        int e;
        e = y + jump[i][1];
        if (c > 0 && c <= n && e > 0 && e <= m)
        {
            if (ans[c][e] > stp + 1 || map[c][e] == 0)
            {
                Search(c, e, stp + 1, sum);
            }
        }
    }
    return;
}

int main()
{
    memset(ans, 0, sizeof(ans));
    memset(map, 0, sizeof(map));
    cin >> n >> m >> hx >> hy;

    Search(hx, hy, 0, 1);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (map[i][j] == 0)
            {
                cout << left << setw(5) << -1;
            }
            else
            {
                cout << left << setw(5) << ans[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int pos[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int maps[1510][1510];
int dx, dy, n, m, sx, sy;
int flag;
char a;

void dfs(int x, int y)
{
    if (maps[x][y] == 2)
    {
        flag = 1;
        return;
    }
    maps[x][y] = 0;
    for (int i = 0; i <= 3; i++)
    {
        if (flag == 1)
        {
            return;
        }

        int tx = x + pos[i][0];
        if (tx == 0)
            tx = n;
        else if (tx == n + 1)
            tx = 1;
        int ty = y + pos[i][1];
        if (ty == 0)
            ty = m;
        else if (ty == m + 1)
            ty = 1;

        if (x == dx && y == dy && tx == sx && ty == sy)
        {
            continue;
        }

        if (maps[tx][ty] != 0)
        {
            dfs(tx, ty);
        }
    }
}

int main()
{
    cin >> n ; 
    cin >> m; 
    while (cin >> n >> m)
    {
           cout << "aa1" << endl;
        //memset(maps, 0, sizeof(maps));
        flag = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                //scanf("%c ", &a);
                cin >> a;
                if (a == '.')
                {
                    maps[i][j] = 1;
                    break;
                }
                if (a == 'S')
                {
                    maps[i][j] = 2;
                    sx = i;
                    sy = j;
                    break;
                }
            }
            //scanf("\n");
        }
/*
        for (int i = 0; i <= 3; i++)
        {
            dx = sx + pos[i][0];
            dy = sy + pos[i][1];
            if (maps[dx][dy] == 1)
                dfs(dx, dy);
        }
*/
        if (flag == 1)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
                    cout << "aa" << endl;
    }
    system("pause");
    return 0;
}

#include <iostream>
using namespace std;

int b[101][101];
char a[101][101];
char k[] = {"yizhong"};

int main()
{
    int n, x, y, z, p;
    cin >> n;
    for (int i = 0; i < 101; ++i)
        for (int j = 0; j < 101; ++j)
            b[i][j] = -1;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (a[i][j] == 'y')
            {
                x = i, y = j, z = 0;
                bool flag = 1;
                while (x < n && z < 7)
                    if (a[x++][y] != k[z++])
                    {
                        flag = 0;
                        break;
                    }
                p = z;
                x = i, y = j, z = 0;
                if (flag && p == 7)
                    while (x < n && z < 7)
                    {
                        b[x++][y] = z++;
                    }
                x = i, y = j, z = 0;
                flag = 1;
                while (x >= 0 && z < 7)
                    if (a[x--][y] != k[z++])
                    {
                        flag = 0;
                        break;
                    }
                p = z;
                x = i, y = j, z = 0;
                if (flag && p == 7)
                    while (x >= 0 && z < 7)
                    {
                        b[x--][y] = z++;
                    }
                x = i, y = j, z = 0;
                flag = 1;
                while (y < n && z < 7)
                    if (a[x][y++] != k[z++])
                    {
                        flag = 0;
                        break;
                    }
                p = z;
                x = i, y = j, z = 0;
                if (flag && p == 7)
                    while (y < n && z < 7)
                    {
                        b[x][y++] = z++;
                    }
                x = i, y = j, z = 0;
                flag = 1;
                while (y >= 0 && z < 7)
                    if (a[x][y--] != k[z++])
                    {
                        flag = 0;
                        break;
                    }
                p = z;
                x = i, y = j, z = 0;
                if (flag && p == 7)
                    while (x < n && z < 7)
                    {
                        b[x][y--] = z++;
                    }
                x = i, y = j, z = 0;
                flag = 1;
                while (y < n && x >= 0 && z < 7)
                    if (a[x--][y++] != k[z++])
                    {
                        flag = 0;
                        break;
                    }
                p = z;
                x = i, y = j, z = 0;
                if (flag && p == 7)
                    while (y < n && x >= 0 && z < 7)
                    {
                        b[x--][y++] = z++;
                    }
                x = i, y = j, z = 0;
                flag = 1;
                while (y >= 0 && x >= 0 && z < 7)
                    if (a[x--][y--] != k[z++])
                    {
                        flag = 0;
                        break;
                    }
                p = z;
                x = i, y = j, z = 0;
                if (flag && p == 7)
                    while (y >= 0 && x >= 0 && z < 7)
                    {
                        b[x--][y--] = z++;
                    }
                x = i, y = j, z = 0;
                flag = 1;
                while (y < n && x < n && z < 7)
                    if (a[x++][y++] != k[z++])
                    {
                        flag = 0;
                        break;
                    }
                p = z;
                x = i, y = j, z = 0;
                if (flag && p == 7)
                    while (y < n && x < n && z < 7)
                    {
                        b[x++][y++] = z++;
                    }
                x = i, y = j, z = 0;
                flag = 1;
                while (y >= 0 && x < n && z < 7)
                    if (a[x++][y--] != k[z++])
                    {
                        flag = 0;
                        break;
                    }
                p = z;
                x = i, y = j, z = 0;
                if (flag && p == 7)
                    while (y >= 0 && x < n && z < 7)
                    {
                        b[x++][y--] = z++;
                    }
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (b[i][j] == -1)
                cout << "*";
            else
                cout << k[b[i][j]];
        }
        cout << endl;
    }
    return 0;
}
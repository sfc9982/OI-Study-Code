#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, sum;
int a[2510][2510], b[2510][2510];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j])
            {
                if (i && j)
                {
                    int dpl = 0;
                    bool side = false;
                    if (a[i - 1][j - 1])
                    {
                        for (int z = 1; z <= b[i - 1][j - 1]; z++)
                        {
                            if (a[i][j - z])
                            {
                                dpl = z;
                                break;
                            }
                            if (a[i - z][j])
                            {
                                dpl = z;
                                break;
                            }
                        }
                        if (!dpl)
                            dpl = b[i - 1][j - 1] + 1;
                        sum = max(sum, dpl);
                    }
                    else if (a[i - 1][j + 1])
                    {
                        if (dpl)
                        {
                            dpl = 0;
                            side = true;
                        }
                        for (int z = 1; z <= b[i - 1][j + 1]; z++)
                        {
                            if (a[i][j + z])
                            {
                                dpl = z;
                                break;
                            }
                            if (a[i - z][j])
                            {
                                dpl = z;
                                break;
                            }
                        }
                        if (dpl == 0)
                            dpl = b[i - 1][j + 1] + 1;
                        sum = max(sum, dpl);
                    }
                    if (side)
                        b[i][j] = 1;
                    else
                        b[i][j] = dpl;
                }
                else if (i && j)
                {
                    int dpl = 0;
                    if (a[i - 1][j + 1])
                    {
                        for (int z = 1; z <= b[i - 1][j + 1]; z++)
                        {
                            if (a[i][j + z])
                            {
                                dpl = z;
                                break;
                            }
                            if (a[i - z][j])
                            {
                                dpl = z;
                                break;
                            }
                        }
                        if (dpl == 0)
                            dpl = b[i - 1][j + 1] + 1;
                        sum = max(sum, dpl);
                    }
                    b[i][j] = 1;
                }
                else
                    b[i][j] = 1;
            }
        }
    }
    cout << sum << endl;
    getchar();
    return 0;
}
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n[10];

bool full()
{
    for (int i = 1; i <= 9; i++)
    {
        if (n[i] != 1)
            return false;
    }
    return true;
}

int main()
{
    for (int i = 192; i <= 334; i++)
    {
        for (int j = 384; j <= 667; j++)
        {
            for (int k = 576; k <= 999; k++)
            {
                if (j == i * 2 && k == i * 3)
                {
                    memset(n, 0, sizeof(n));
                    int a = i, b = j, c = k;
                    for (int q = 1; q <= 3; q++)
                    {
                        n[a % 10]++;
                        a = a / 10;
                        n[b % 10]++;
                        b = b / 10;
                        n[c % 10]++;
                        c = c / 10;
                    }
                    if (full())
                        cout << i << " " << j << " " << k << endl;
                }
            }
        }
    }
    system("pause");
    return 0;
}

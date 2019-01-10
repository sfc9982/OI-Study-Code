#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a[32] = {};
    a[0] = 1;
    int q;
    cin >> q;
    while (q--)
    {
        for (int i = 0; i <= 32; i++)
        {
            a[i] <<= 1;
            if (a[i] >= 10)
            {
                a[i + 1] += 1;
                a[i] = a[i] % 10;
            }
        }
    }
    bool b = false;
    for (int i = 31; i >= 0; i--)
    {
        if (a[i] != 0)
            b = true;
        if (b)
            cout << a[i] << flush;
    }
    system("pause");
    return 0;
}

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    const int len = 201;
    int n;
    int a[201] = {};
    cin >> n;
    a[0] = 2;
    n--;
    while (n--)
    {
        for (int i = 0; i < len; i++)
            a[i] = a[i] + a[i];
        for (int i = 0; i < len; i++)
        {
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
        }
    }

    bool first = false, stat = false;
    for (int i = len; i >= 0; i--)
    {
        if (a[i])
            first = true;
        if (first)
        {
            cout << a[i];
            stat = true;
        }
    }
    if (!stat)
        cout << 0;
    cout << endl;
    return 0;
}
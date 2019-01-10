#include <iostream>
using namespace std;
int num[350][350];

int next(int m, int n)
{
    if (m < n)
    {
        return next(m, m);
    }
    if (!num[m][n])
    {
        if (m == 0 || n == 1)
        {
            num[m][n] = 1;
        }
        else
        {
            num[m][n] = next(m - n, n) + next(m, n - 1);
        }
    }
    return num[m][n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    cout << next(a - b, b) << endl;
    return 0;
}
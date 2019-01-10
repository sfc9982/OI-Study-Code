#include <iostream>
using namespace std;
int n, k, price, color, min, s, num;
int a[60], b[60], u[60];
int main()
{
    cin >> n >> k >> price;
    for (int i = 1; i <= n; i++)
    {
        cin >> color >> min;
        if (min <= price)
            num = i;
        if (num >= u[color])
            b[color] = a[color];
        s += b[color];
        a[color]++;
        u[color] = i;
    }
    cout << s;
    return 0;
}
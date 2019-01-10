#include <iostream>
using namespace std;

int b, p, k, a;

int qpow(int p)
{
    int tmp;
    if (p == 0)
    {
        return 1;
    }
    tmp = qpow(p >> 1) % k;
    tmp = (tmp * tmp) % k;
    if (p % 2 == 1)
    {
        tmp = (tmp * b) % k;
    }
    return tmp % k;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> b >> p >> k;
    cout << b << " ^ " << p << " mod " << k << " = ";
    if (p == 0)
    {
        cout << 1 % k;
        return 0;
    }
    b %= k;
    cout << qpow(p) << endl;
    getchar();
    return 0;
}
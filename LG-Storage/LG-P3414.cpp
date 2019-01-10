#include <iostream>
#include <cmath>
using namespace std;

unsigned long long n;
const int mod = 6662333;
unsigned long long sum;

int qpow(unsigned long long a, unsigned long long x)
{
    unsigned long long y = 1;
    while (x)
    {
        if (x & 1)
        {
            y = (unsigned long long)y * a % mod;
        }
        x >>= 1;
        a = a * a % mod;
    }
    return y;
}

int main()
{
    cin >> n;
    sum = qpow(2, n - 1);
    cout << (unsigned long long)sum << endl;
    //getchar();
    //getchar();
    return 0;
}
//
#include <iostream>
#include <cmath>
using namespace std;

unsigned long long a, b, c, d, ans;

int main()
{
    cin >> a >> b >> c;
    d = pow(a, b);
    ans = d % c;
    cout << a << "^" << b << " mod " << c << "=" << ans << endl;
    system("pause");
    return 0;
}

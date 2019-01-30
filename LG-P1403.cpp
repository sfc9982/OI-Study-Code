#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    int sum = 0, n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        sum += n / i;
    cout << sum << endl;
    //system("pause");
    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    int k;
    double n, s = 0;

    cin >> k;
    for (n = 1; s <= k; n++)
    {
        s += 1 / n;
    }
    cout << n - 1 << endl;
    //system("pause");
    return 0;
}

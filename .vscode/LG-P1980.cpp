#include <iostream>
using namespace std;

int main()
{
    int a, b, sum = 0;
    cin >> a >> b;
    for (int i = 1; i <= a; i++)
    {
        int d = i;
        while (d > 0)
        {
            int c = d % 10;
            d = d / 10;
            if (c == b)
            {
                sum++;
            }
        }
    }
    cout << sum << endl;
    //system("pause");
    return 0;
}
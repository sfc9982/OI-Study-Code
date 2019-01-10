#include <iostream>
using namespace std;

int main()
{
    int n, save = 0, s = 0, left, y;
    for (int i = 1; i <= 12; i++)
    {
        s += 300;
        cin >> n;
        left = s - n;
        if (left < 0)
        {
            cout << -i;
            break;
        }
        if (left / 100 != 0)
        {
            save = save + (left / 100) * 100;
            left = left - (left / 100) * 100;
        }
        s = left;
        if (i == 12)
        {
            y = s + save + (save / 10) * 2;
            cout << y;
        }
    }
    return 0;
}

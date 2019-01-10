#include <iostream>
using namespace std;

const int l = 10;
float low = -1e9, hig = 1e9;
int p[l], s[l];

int abs(int a)
{
    if (a < 0)
        return -a;
    else
        return a;
}

int main()
{
    int ex, o, b;
    int y, x, k;
    cin >> ex;
    cin >> o >> b;
    for (int i = 1;; i++)
    {
        int p0, s0;
        cin >> p0 >> s0;
        if (p0 == -1 && s0 == -1)
            break;
        p[i] = p0;
        s[i] = s0;
    }
    cin >> k;
    system("pause");
    return 0;
}

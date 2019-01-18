#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const char dict[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'};
string ans[10050];

int main()
{
    int m, n, s, num = 0;
    cin >> m >> n;
    s = m;
    while (m != 0)
    {
        int k, t;
        k = m % n;
        t = m / n;
        if (k < 0)
        {
            k -= n;
            t++;
        }
        m = t;
        ans[++num] = dict[k];
    }
    cout << s << "=";
    for (int i = num; i >= 1; i--)
        cout << ans[i];
    cout << "(base" << n << ")";
    //system("pause");
    return 0;
}
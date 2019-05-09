#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int p, q;
char s[5000001 * 4];

inline int min(const int &_a, const int &_b)
{
    if (_a < _b)
        return _a;
    return _b;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; cin >> (s + i); i += 72)
    {
    }
    for (int i = 1; i <= n; i++)
        s[i + n] = s[i];
    for (int i = 2, j = 1, k = 0; (i <= n && j <= n) && k <= n;)
    {
        if (s[j + k] == s[i + k])
            k++;
        else
        {
            if (s[j + k] < s[i + k])
                i += k + 1;
            else
                j += k + 1;
            k = 0;
            if (j == i)
                i++;
        }
        q = i - 1;
        p = j - 1;
    }
    cout << min(p, q) << endl;
    // system("pause");
}
#include <iostream>
#include <cstring>

using namespace std;

char s[1000002];
int n, f[1000002];

void Next(char *s)
{
    int i = 1, j = 0;
    f[0] = 0;
    f[1] = 0;
    for (i = 1; i < n; i++)
    {
        j = f[i];
        while (j && s[i] != s[j])
            j = f[j];
        if (s[i] == s[j])
            f[i + 1] = j + 1;
        else
            f[i + 1] = 0;
    }
}

int main()
{
    int T;
    T = 0;
    while (cin >> n && n)
    {
        cin >> s;
        Next(s);
        cout << "Test case #" << ++T << endl;
        for (int i = 2; i <= n; i++)
            if (f[i] > 0 && i % (i - f[i]) == 0)
                cout << i << " " << i / (i - f[i]) << endl;
        cout << endl;
    }
    return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s[20010100];
int main()
{
    int n;
    cin >> n;
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)
        s[i + n] = s[i];
    int i = 1, j = 2, k = 0;
    while ((i <= n && j <= n) && k <= n)
    {
        if (s[i + k] == s[j + k])
            k++;
        else
        {
            if (s[i + k] < s[j + k])
                j += k + 1;
            else
                i += k + 1;
            k = 0;
            if (i == j)
                j++;
        }
    }
    cout << min(i - 1, j - 1) << endl;
}
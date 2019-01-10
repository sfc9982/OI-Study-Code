#include <iostream>
#include <cstdio>
using namespace std;
int n;
int m;
int s[100002];
int l;
int main()
{
    cin >> n >> m;
    l = n + 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        if (s[i] + s[i - 1] <= m)
            s[i] += s[i - 1], l--;
    }
    cout << l << endl;
    return 0;
}
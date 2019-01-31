#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;

int a, b, n, j;
string name[256], s1, s2;
map<string, int> in, out;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> name[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> s1 >> b >> j;
        for (int k = 1; k <= j; k++)
        {
            cin >> s2;
            in[s2] += b / j;
            out[s1] += b / j;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << name[i] << " " << in[name[i]] - out[name[i]] << endl;
    //system("pause");
    return 0;
}
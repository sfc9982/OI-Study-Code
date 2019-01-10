#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    //freopen("out.txt", "w", stdout);
    string a, b, e;
    char dict['Z' + 1], r['Z' + 1];
    bool flag['Z' + 1];
    memset(dict, 0, sizeof(dict));
    memset(r, 0, sizeof(r));
    memset(flag, false, sizeof(flag));
    cin >> a >> b >> e;
    if (a.length() != b.length())
    {
        cout << "Failed";
        return 0;
    }
    int l = a.length();
    if (l < 26)
    {
        cout << "Failed";
        return 0;
    }
    for (int i = 0; i < l; i++)
    {
        if ((dict[a[i]] != 0 || r[b[i]] != 0) && (b[i] != dict[a[i]] || r[b[i]] != a[i]))
        {
            cout << "Failed";
            return 0;
        }
        dict[a[i]] = b[i];
        r[b[i]] = a[i];
    }
    for (int i = 0; i < e.length(); i++)
    {
        e[i] = dict[e[i]];
    }
    cout << e << flush;
    //system("pause");
    return 0;
}

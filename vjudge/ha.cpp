#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string a, b;
    int xa[201] = {}, xb[201] = {}, ans[201] = {};
	cin >> a >> b;
    for (int i = 0; i < a.length(); i++)
        xa[i] = a[a.length() - i - 1] - '0';
    for (int i = 0; i < b.length(); i++)
        xb[i] = b[b.length() - i - 1] - '0';
    int len = max(a.length(), b.length());
    for (int i = 0; i < len; i++)
        ans[i] = xa[i] + xb[i];
    for (int i = 0; i < len; i++)
    {
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
    }
    //if (ans[len] != 0)
    //    cout << ans[len];
    bool first = false, stat = false;
    for (int i = len; i >= 0; i--)
    {
		if (ans[i])
			first = true;
		if (first)
		{
			cout << ans[i];
			stat = true;	
		}
    }
    if (!stat)
    	cout << 0;
    cout << endl;
    return 0;
}
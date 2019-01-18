#include <iostream>
#include <climits>

using namespace std;

int a[200050];

int main()
{
    int n, b, ans;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    b = 0;
    ans = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        if (b > 0)
            b += a[i];
        else
            b = a[i];
        if (ans < b)
            ans = b;
    }
    cout << ans << endl;
    return 0;
}

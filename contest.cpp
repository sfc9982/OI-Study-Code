#include <iostream>
#include <algorithm>

using namespace std;
int a[100050];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    stable_sort(a, a + n);
    cin >> m;
    while (m--)
    {
        int x, l = 0, r = n - 1, mid;
        cin >> x;
        if (x <= a[0])
        {
            cout << a[0] << endl;
            continue;
        }
        if (x >= a[n - 1])
        {
            cout << a[n - 1] << endl;
            continue;
        }
        while (l + 1 < r)
        {
            mid = (l + r) / 2;
            if (a[mid] > x)
                r = mid;
            else if (a[mid] < x)
                l = mid;
            else
            {
                l = r = mid;
                break;
            }
        }
        cout << (abs(a[l] - x) <= abs(a[r] - x) ? a[l] : a[r]) << endl;
    }
    return 0;
}

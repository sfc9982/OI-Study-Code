#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a[100032], minn = 100000000, f;
int td(int l, int r, int x)
{
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (x == a[mid])
            return mid;
        if (x < a[mid])
            r = mid;
        else
            l = mid + 1;
    }
    return -1;
}
int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cin >> m;

    sort(a, a + n);

    for (int i = 0; i < n; i++)
    {
        int tmp = m - a[i];
        int p = td(0, n - 1, tmp);

        if (p != -1 && p != i)
        {
            minn = min(minn, min(a[i], tmp));
            f = 1;
        }
    }

    if (f)
        cout << minn << " " << m - minn;
    else
        cout << "No" << endl;

    //system("pause");
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, pre, now, h1 = 1, h2 = 1;
    cin >> n >> pre;
    for (int i = 2; i <= n; i++)
    {
        cin >> now;
        if (now > pre)
            h1 = max(h1, h2 + 1);
        if (now < pre)
            h2 = max(h2, h1 + 1);
        pre = now;
    }
    cout << max(h1, h2) << endl;
    //system("pause");
    return 0;
}
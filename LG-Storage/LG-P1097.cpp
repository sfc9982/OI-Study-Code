#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int num[219090];
//御坂妹情感大佬19090,争取给当麻攻略了
int main()
{
    memset(num, 0, sizeof(num));
    int n, ct = 1, p = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    sort(num + 1, num + n + 1);
    while (p <= n)
    {
        int s = num[p], k;
        k = p;
        while (s == num[p])
        {
            p++;
        }
        cout << num[p - 1] << " ";
        cout << p - k << endl;
    }
}

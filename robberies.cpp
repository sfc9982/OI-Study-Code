#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int m[50005];
double p[50005], ans[50005];

int main()
{
    int t, m0;
    double p0;
    cin >> t;
    while (t--)
    {
        cin >> p0 >> m0;
        int sum = 0;
        for (int i = 0; i < m0; i++)
        {
            cin >> m[i] >> p[i];
            sum += m[i];
        }
        memset(ans, 0, sizeof(ans));
        ans[0] = 1;
        for (int i = 0; i < m0; i++)
            for (int j = sum; j >= m[i]; j--)
                ans[j] = max(ans[j], ans[j - m[i]] * (1 - p[i]));
        for (int i = sum; i >= 0; i--)
        {
            if (ans[i] > (1 - p0))
            {
                cout << i << endl;
                break;
            }
        }
    }
    //system("pause");
    return 0;
}

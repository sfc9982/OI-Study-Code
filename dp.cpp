#include <iostream>

using namespace std;

const int INF = 1000010;
int pre[1000010], b[1000010], nxt[1000010], a[1000010];

int lis(int s[], int l)
{
    int L, R;
    int len = 0;
    int t;
    a[0] = -INF;
    for (int i = 0; i < l; i++)
    {
        t = s[i];
        if (t > a[len])
        {
            len++;
            a[len] = t;
        }
        else
        {
            int x;
            L = 1;
            R = len;
            while (L <= R)
            {
                x = (L + R) >> 1;
                if (t > a[x])
                    L = x + 1;
                else
                    R = x - 1;
            }
            a[L] = t;
        }
    }
    return len;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
        nxt[pre[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        b[i] = nxt[b[i]];
    }
    cout << lis(b, n) << endl;
    // system("pause");
    return 0;
}
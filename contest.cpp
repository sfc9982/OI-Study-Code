#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool stat;
int n, m, l, r, s;
int x, y, p[100050], a[100050];
vector<int> G[100050];

void Search(int c)
{
    cin >> l >> r >> s;
    int x = 0, y = 0;
    stat = true;
    for (int i = 2; i * i <= s; i++)
    {
        y = 0;
        if (s % i == 0)
        {
            while (s % i == 0)
            {
                s /= i;
                y++;
            }
            int t;
            t = upper_bound(G[i].begin(), G[i].end(), r) - lower_bound(G[i].begin(), G[i].end(), l);
            if (t < y)
            {
                stat = false;
                break;
            }
        }
    }
    if (s > 1)
    {
        x = s;
        y = 1;
        int t;
        t = upper_bound(G[s].begin(), G[s].end(), r) - lower_bound(G[s].begin(), G[s].end(), l);
        if (t < 1)
            stat = 0;
    }
    if (stat)
        cout << "Yes";
    else
        cout << "No";
    if (c)
        cout << endl;
    return;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int a[100050];
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            for (int j = 2; j * j <= a[i]; j++)
            {
                while (a[i] % j == 0)
                {
                    G[j].push_back(i);
                    a[i] /= j;
                }
            }
            if (a[i] > 1)
                G[a[i]].push_back(i);
        }
        while (m--)
            Search(m);
    }
    return 0;
}
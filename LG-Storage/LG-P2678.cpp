#include <iostream>
using namespace std;

int n;
int m;
int s;
int l;
int pos[1926817];

bool ZXG(int ctr)
{
    int ans = 0, st = 0;
    for (int i = 1; i <= n; ++i)
        if (pos[i] - st < ctr)
            ans = ans + 1;
        else
            st = pos[i];
    return ans <= m;
}

int main()
{
    scanf("%d%d%d", &s, &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &pos[i]);
    int l =1, r = s, ctr;
    while (l < r)
    {
        ctr = (l + r) >> 1;
        if (ZXG(ctr))
            l = ctr + 1;
        else
            r = ctr - 1;
    }
    if (!ZXG(l))
        l -= 1;
    printf("%d\n", l);
    return 0;
}
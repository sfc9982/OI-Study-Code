#include <stdio.h>
int a[10000001], t;
int n;
int m;
int s;
int l;
int main()
{
    n = 0;
    m = 0;
    s = 0;
    l = 0;
    scanf("%d%d", &t, &s);
    l = s;
    while (l)
    {
        l--;
        scanf("%d%d", &m, &n);
        for (s = m; s <= t; s++)
            if (a[s] < a[s - m] + n)
                a[s] = a[s - m] + n;
    }
    printf("%d", a[t]);
}
#include <cstdio>
#include <cstdlib>
#include <cstring>
int sa[1001];
int f[1001];
int n, ans;
int max(int x, int y)
{
    if (x > y)
        return x;
    return y;
}
int main()
{
    ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &sa[i]);
        f[i] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i - 1; j >= 1; j--)
        {
            if (sa[j] < sa[i])
                f[i] = max(f[i], f[j] + 1);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (ans < f[i])
            ans = f[i];
    }
    printf("%d", ans);
}
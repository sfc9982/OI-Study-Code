#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int a, b, k, n, m, c[1050][1050];
long long ans;
void produce_c()
{
    for (int i = 1; i <= k; i++)
        c[i][0] = c[i][i] = 1;
    for (int i = 1; i < 1050; i++)
        for (int j = 1; j < i; j++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % 10007;
}

int qpow(int x, int y)
{
    if (y == 0)
        return 1;
    int result = 1;
    while (y > 0)
    {
        if (y & 1)
            result = (result % 10007) * (x % 10007) % 10007;
        x = (x) * (x) % 10007;
        y = y >> 1;
    }
    return result;
}
int main()
{
    scanf("%d%d%d%d%d", &b, &a, &k, &n, &m);
    c[0][0] = 1;
    produce_c();
    ans = ((c[k][m] % 10007) * (qpow(a, m) % 10007) * (qpow(b, n) % 10007)) % 10007;
    printf("%lld", ans);
    return 0;
}
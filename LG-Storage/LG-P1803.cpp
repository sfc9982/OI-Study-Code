#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;
struct time_len
{
    int op;
    int ed;
};
bool JudgeLight(time_len a, time_len b)
{
    if (a.ed != b.ed)
        return a.ed < b.ed;
    return a.op < b.op;
}
time_len work[1000233];
int f[1000233];
int i, n, tmp;
int main()
{
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> work[i].op >> work[i].ed;
    sort(work + 1, work + 1 + n, JudgeLight);
    f[0] = 0;
    tmp = 0;
    for (i = 1; i <= n; i++)
    {
        while (work[tmp + 1].ed <= work[i].op)
            tmp++;
        f[i] = max(f[i - 1], f[tmp] + 1);
    }
    cout << f[n] << endl;
    return 0;
}
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int inf = INT_MAX;
int dp[300];

struct stuStr
{
    int a;
    int b;
} stu[201];

bool cmp(stuStr A, stuStr B)
{
    return A.b > B.b;
}

int main()
{
    int n;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> stu[i].a >> stu[i].b;
        dp[i] = i;
    }
    dp[n + 1] = n + 1;
    dp[n + 2] = n + 2;

    int maxx = inf 

    system("pause");
    return 0;
}

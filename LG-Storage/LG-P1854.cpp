#include <iostream>
#include <climits>
using namespace std;

const int INF = INT_MAX;
int f, v, max;
int w[105][105], dp[105][105];

int main()
{
    cin >> f >> v;
    for (int i = 1; i <= f; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            cin >> w[i][j];
            dp[i][j] = INF;
        }
    }
    max = v - f + 1;
    system("pause");
    return 0;
}

#include <iostream>
using namespace std;

int n, m;
bool face[1000001];
char job[1000001][51];
int num = 1;
bool hand; //0-left 1-right
int distce;

void jia(int d)
{
    if (num + d > n)
    {
        num = d - n + num;
    }
    else
    {
        num += d;
    }
    return;
}

void jian(int d)
{
    if (num - d < 1)
    {
        num = n - d + num;
    }
    else
    {
        num -= d;
    }
    return;
}

void pos(int hand, int dist) //0-left 1-right
{
    if (face[num])
    {
        if (hand == 0)
        {
            jia(dist);
        }
        else
        {
            jian(dist);
        }
    }
    else
    {
        if (hand == 0)
        {
            jian(dist);
        }
        else
        {
            jia(dist);
        }
    }
    return;
}

int main()
{
    //ios::sync_with_stdio(false);
    //freopen("out.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> face[i] >> job[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> hand >> distce;
        pos(hand, distce);
    }

    cout << job[num];
    //system("pause");
    return 0;
}

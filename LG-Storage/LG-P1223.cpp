#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int n;
double m;
int s;

struct DataStu
{
    int t;
    int num;
} t[100005];

bool cmp(DataStu x, DataStu y)
{
    return x.t < y.t;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &t[i].t);
        t[i].num = i;
    }
    stable_sort(t + 1, t + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", t[i].num);
        m += s;
        s += t[i].t;
    }
    printf("\n%.2lf", m / n);
    return 0;
}
#include <iostream>
using namespace std;

int n, k, price, color[200001], num, minp[200001];
int hotel1[101], hotel2[101], ans[101];
int s;
void work(int i)
{
    s = s + hotel2[color[i]];
    hotel1[color[i]]++;
    ans[color[i]] = i;
    return;
}

int main()
{
    cin >> n >> k >> price;
    for (int i = 1; i <= n; i++)
    {
        cin >> color[i] >> minp[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (minp[i] <= price)
            num = i;
        if (num >= ans[color[i]])
            hotel2[color[i]] = hotel1[color[i]];
        work(i);
    }

    cout << s << endl;

    //system("pause");
    return 0;
}
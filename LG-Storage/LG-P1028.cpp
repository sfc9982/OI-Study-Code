#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
long int num = 0, buy = 0, money = 0;

struct seller
{
    int price;
    long int milk;
} s[5005];

bool cmp(seller a, seller b)
{
    return a.price < b.price;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> s[i].price >> s[i].milk;
    }
    sort(s, s + m, cmp);
    while (1)
    {
        if (n == 0 || m == 0)
        {
            money = 0;
            break;
        }
        buy += s[num].milk;
        if (buy < n)
        {
            money += s[num].milk * s[num].price;
        }
        if (buy > n)
        {
            money += (n - (buy - s[num].milk)) * s[num].price;
            break;
        }
        if (buy == n)
        {
            money += s[num].milk * s[num].price;
            break;
        }
        num++;
    }
    cout << money;
    //system("pause");
    return 0;
}

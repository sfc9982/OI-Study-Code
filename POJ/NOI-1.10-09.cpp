#include <iostream>
using namespace std;

int n, cnt;
int ds[10032];
int num[10032] = {0};
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ds[i];
        if (0 == num[ds[i]])
            cnt++;
        num[ds[i]]++;
    }

    cout << cnt << endl;

    for (int i = 1; i <= 1000; i++)
    {
        if (num[i] != 0)
            cout << i << " ";
    }

    //system("pause");
    return 0;
}

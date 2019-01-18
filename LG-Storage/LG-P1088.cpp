#include <iostream>
#include <algorithm>

using namespace std;

int num[10050];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    for (int i = 1; i <= m; i++)
        next_permutation(num + 1, num + n + 1);
    for (int i = 1; i <= n; i++)
    {
        cout << num[i];
        if (i != n)
            cout << " ";
    }
    //system("pause");
    return 0;
}

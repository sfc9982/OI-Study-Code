#include <iostream>
using namespace std;
int m, n;
int f[20010];
int obj[40];
int main(){
    int i, j;
    cin >> m >> n;
    for (i = 1; i <= n; i++)
        cin >> obj[i];
    for (i = 1; i <= n; i++)
        for (j = m; j >= obj[i]; j--)
            if (f[j] < f[j - obj[i]] + obj[i])
                f[j] = f[j - obj[i]] + obj[i];
    cout << m - f[m] << endl;
}
#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main()
{
    int x;
    double w;
    cin >> x;
    if (x <= 150)
        w = 0.4463 * x;
    else if (x >= 151 && x <= 400)
        w = 0.4463 * 150 + 0.4663 * (x - 150);
    else if (x >= 401)
        w = 0.4463 * 150 + 0.4663 * 250 + 0.5663 * (x - 400);
    cout << fixed << setprecision(1) << w << endl;
    //printf("%.1lf\n", w);
    //system("pause");
    return 0;
}

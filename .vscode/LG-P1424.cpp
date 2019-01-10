#include <iostream>
using namespace std;

int n, x, s;

void add()
{
    if (x <= 6)
        x++;
    else
        x = 1;
    return;
}

int main()
{
    cin >> x >> n;
    s = 0;
    while (n--)
    {
        if (x <= 5)
        {
            s += 250;
            add();
        }
        else
            add();
    }
    cout << s << endl;
    //system("pause");
    return 0;
}

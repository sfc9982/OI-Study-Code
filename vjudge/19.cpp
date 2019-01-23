#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;
    string a, b, c;
    bool stat;
        cin >> a >> b;
        stat = false;

        for (int i = 0; i < a.length(); i++)
        {
            c.clear();
            c += a.substr(i, a.length() - i);
            c += a.substr(0, i);

            if (c.find(b) < c.length())
            {
                stat = true;
                break;
            }
        }

        for (int i = 0; i < b.length(); i++)
        {
            c.clear();
            c += b.substr(i, b.length() - i);
            c += b.substr(0, i);

            if (c.find(a) < c.length())
            {
                stat = true;
                break;
            }
        }
        if (stat)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    return 0;
}

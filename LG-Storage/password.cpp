#include <iostream>
#include <string>
using namespace std;

int len, txt, x;
string str;

struct stack
{
    int n;
    string str;
} s[20];

void Init()
{
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> str;
    len = str.size();
    txt = 0;
    return;
}

bool left(int pos)
{
    if (str[pos] == '[')
        return true;
    else
        return false;
}

bool right(int pos)
{
    if (str[pos] == ']')
        return true;
    else
        return false;
}

bool num(int pos)
{
    if (str[pos] <= '9' && str[pos] >= '0')
        return true;
    else
        return false;
}

bool letter(int pos)
{
    if (str[pos] <= 'Z' && str[pos] >= 'A')
        return true;
    else
        return false;
}

void Search()
{
    for (int i = 0; i < len; i++)
    {
        if (letter(i))
            s[txt].str += str[i];
        else if (left(i))
        {
            txt++;
            s[txt].str = "";
            s[txt].n = 0;
        }
        else if (num(i))
        {
            s[txt].n = s[txt].n * 10 + str[i] - '0';
        }
        else if (right(i))
        {
            for (int j = 1; j <= s[txt].n; j++)
            {
                s[txt - 1].str += s[txt].str;
            }
            txt--;
        }
    }
    return;
}

void Print()
{
    cout << s[0].str << endl;
    return;
}

int main()
{
    Init();
    Search();
    Print();
    //system("pause");
    return 0;
}
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char s[101], c;
int len, outlen;
int fmt, rpt, rvs;

bool cap(char c)
{
    if (c >= 'a' && c <= 'z')
        return false;
    else if (c >= 'A' && c <= 'Z')
        return true;
    else
        return false;
}

bool judge(int n)
{
    if (s[n] == '-' && n != 0 && n != len - 1)
    {
        if (s[n - 1] >= 'a' && s[n + 1] <= 'z' && s[n - 1] < s[n + 1])
        {
            return true;
        }
        else if (s[n - 1] >= '0' && s[n + 1] <= '9' && s[n - 1] < s[n + 1])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

void print(int n) //TODO:reverse
{
    bool first;
    if (judge(n)) //fmt(1=Ð¡Ð´,2=´óÐ´,3=*), rpt(¸ö), rvs(2=ÄæÐò)
    {
        outlen = s[n + 1] - s[n - 1] - 1;
        if (rvs != 2)
        {
            if (first)
            {
                c = s[n - 1] + 1;
                first = false;
            }
            //aaaabbbbcccc
            for (int j = 1; j <= outlen; j++) //aaaabbbbcccc
            {
                for (int k = 1; k <= rpt; k++) //bbbb
                {
                    if (fmt == 3)
                    {
                        cout << "*";
                    }
                    else
                    {
                        if (fmt == 1)
                        {
                            if (cap(c))
                            {
                                cout << c + 32;
                            }
                            else
                            {
                                cout << c;
                            }
                        }
                        else
                        {
                            if (cap(c))
                            {
                                cout << (char)c;
                            }
                            else
                            {
                                cout << (char)(c - 32);
                            }
                        }
                    }
                }
                c = c + 1;
            }
        }
        else
        {
            if (first)
            {
                c = s[n + 1] - 1;
                first = false;
            }
            //aaaabbbbcccc
            for (int j = 1; j <= outlen; j++) //aaaabbbbcccc
            {
                for (int k = 1; k <= rpt; k++) //bbbb
                {
                    if (fmt == 3)
                    {
                        cout << "*";
                    }
                    else
                    {
                        if (fmt == 1)
                        {
                            if (cap(c))
                            {
                                cout << c + 32;
                            }
                            else
                            {
                                cout << c;
                            }
                        }
                        else
                        {
                            if (cap(c))
                            {
                                cout << (char)c;
                            }
                            else
                            {
                                cout << (char)(c - 32);
                            }
                        }
                    }
                }
                c--;
            }
        }
    }
    else
    {
        first = true;
        cout << s[n];
        return;
    }
    return;
}

int main()
{
    //ios::sync_with_stdio(false);

    freopen("out.txt", "w", stdout);
    cin >> fmt >> rpt >> rvs;
    cin >> s;
    len = strlen(s);

    for (int i = 0; i < len; i++)
    {
        print(i);
    }

    //system("pause");
    return 0;
}

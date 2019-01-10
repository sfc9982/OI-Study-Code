#include <iostream>
#include <cstring>
using namespace std;
struct wordStr
{
    char word[22];
    int len;
    int vis;
} c[22];

int n, maxn;

void work(int x, int len)
{
    for (int i = 1; i <= n; i++)
    {
        if (c[i].vis < 2)
        {
            for (int j = 0; j < c[x].len; j++)
            {
                if (c[x].word[j] == c[i].word[0])
                {
                    int k = 1, judge = 1;
                    for (int l = j + 1; l < c[x].len && k < c[i].len; k++, l++)
                    {
                        if (c[x].word[l] != c[i].word[k])
                        {
                            judge = 0;
                            break;
                        }
                    }
                    if (judge)
                    {
                        c[i].vis++;
                        work(i, len + c[i].len - k);
                        c[i].vis--;
                    }
                }
                //cout << "vis: " << c[i].vis << " len: " << len << endl;
            }
        }
    }
    if (len > maxn)
    {
        maxn = len;
    }
    return;
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> c[i].word;
        c[i].len = strlen(c[i].word);
    }

    cin >> c[0].word;

    c[0].len = strlen(c[0].word);
    work(0, c[0].len);

    cout << maxn << endl;
    //system("pause");
}
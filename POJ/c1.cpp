#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char chS[100050];
char chW[100050];
int lenb, lena;
int a, b;
int first = 0, cnt = 0, tmp = 0, good = 0;

void addb()
{
    if (b < lenb - 1)
        b++;
    else
    {
        b = 0;
    }
    return;
}

bool judge(int s)
{
    if (chS[s] > 96)
    {
        chS[s] -= 32;
    }
    if (chW[b] > 96)
    {
        chW[b] -= 32;
    }
    if (chS[s] == chW[b])
        return true;
    else
        return false;
}

int main()
{
    freopen("in.txt","r",stdin);
    //freopen("stat.out","w",stdout);
    gets(chW);
    gets(chS);

    lenb = strlen(chW);
    lena = strlen(chS);
    chS[lena] = ' ';

    b = 0;

    //cout << "lena: " << lena << " lenb: " << lenb << endl;
    for (int i = 0; i <= lena; i++)
    {
        if (chS[i] == ' ')
        {
            //cout << "test" << endl;
            b = 0;
            if (good == lenb && (i - tmp) == lenb &&i == 1)
            {
                //cout << "succ" << endl;
                cnt++;
                if (cnt == 1)
                    first = tmp;
                good = 0;
            }
            if (good == lenb && (i - tmp) == lenb && i > 0 && chS[tmp - 1] == ' ')
            {
                //cout << "succ" << endl;
                cnt++;
                if (cnt == 1)
                    first = tmp;
                good = 0;
            }
            else
            {
                //cout << "fail" << endl;
                good = 0;
            }
        }
        if (judge(i) && chS[i] != ' ')
        {
            //cout << "word" << endl;
            if (b == 0)
            {
                tmp = i;
            }
            addb();
            good++;
        }
        //cout << "count: " << cnt;
        //cout << " good word: " << first;
        //cout << " good letter: " << good;
        //cout << " i: " << i << " lena: " << lena << endl;
    }

    if (cnt == 0)
    {
        cout << -1;
    }
    else
    {
        cout << cnt << " " << first << endl;
    }
    system("pause");
    return 0;
}

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char chS[1000050];
char chW[1000050];
long int lenb, lena;
long int a, b;
long int first = 0, cnt = 0, tmp = 0, good = 0;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("stat.out","w",stdout);
    gets(chW);
    gets(chS);

    lenb = strlen(chW);
    lena = strlen(chS);
    chS[lena] = ' ';

    for (long ll = 0; ll < lenb; ll++)
        if (chW[ll] >= 'A' && chW[ll] <= 'Z')
            chW[ll] += 32;

    for (long ll = 0; ll < lena; ll++)
        if (chS[ll] >= 'A' && chS[ll] <= 'Z')
            chS[ll] += 32;

    //cout << "lena: " << lena << " lenb: " << lenb << endl;
    for (long int i = 0; i <= lena - lenb; i++)
    {

        long j;

        for (j = 0; j < lenb; j++)
        {
            if (chS[i + j] != chW[j])
                break;
            if (i > 0 && chS[i - 1] != ' ')
                break;
        }

        if ((j == lenb) && (chS[i + j] == ' '))
        {
            cnt++;

            if (1 == cnt)
            {
                first = i;
            }
        }
        if ( blog == true )
           cout << "count: " << cnt;
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
    //system("pause");
    return 0;
}

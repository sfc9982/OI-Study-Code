#include <iostream>
using namespace std;

int flag = 0, num[9][9] = {0};
int x[9][9] = {0}, y[9][9] = {0};
bool rt = false;

int check(int i, int j, int ipt)
{
    i = i / 3 * 3;
    j = j / 3 * 3;
    for (int x1 = 0; x1 < 3; x1++)
    {
        for (int y1 = 0; y1 < 3; y1++)
        {
            if (num[i + x1][j + y1] == ipt)
            {
                return 0;
            }
        }
    }
    return 1;
}

void Print()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << num[i][j] << ' ';
        }
        cout << endl;
    }
}

void dfs(int flag)
{
    if (rt)
    {
        return;
    }
    if (flag == 9 * 9)
    {
        Print();
        rt = true;
        return;
    }
    else
    {
        if (num[flag / 9][flag % 9] != 0)
        {
            dfs(flag + 1);
        }
        else
        {
            for (int i = 1; i <= 9; i++)
            {
                if ((x[flag / 9][i - 1] == 0) && (y[flag % 9][i - 1] == 0) && check(flag / 9, flag % 9, i))
                {
                    num[flag / 9][flag % 9] = i;
                    x[flag / 9][i - 1] = 1;
                    y[flag % 9][i - 1] = 1;
                    dfs(flag + 1);

                    num[flag / 9][flag % 9] = 0;
                    x[flag / 9][i - 1] = 0;
                    y[flag % 9][i - 1] = 0;
                }
            }
        }
    }
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> num[i][j];
            if (num[i][j])
            {
                x[i][num[i][j] - 1] = 1;
                y[j][num[i][j] - 1] = 1;
            }
        }
    }
    dfs(0);
    //system("pause");
    return 0;
}

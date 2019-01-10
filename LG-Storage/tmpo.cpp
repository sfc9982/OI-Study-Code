#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
/*==============================*/ //一些全局变量
int flag = 0;
int num[9][9] = {0}; //原始数据数组
int x[9][9] = {0};   //标记这一行是否有重复的
int y[9][9] = {0};   //标记这一列是否有重复的
/*==============================*/
int inspect(int i, int j, int dj) //检查当前这个数字是否在九宫格中有重复，传入的是当前数字的坐标i，j，和这个数dj也就是传过来的i值
{
    i = i / 3 * 3;
    j = j / 3 * 3;
    for (int ii = 0; ii < 3; ii++)
    {
        for (int jj = 0; jj < 3; jj++)
        {
            if (num[i + ii][j + jj] == dj) //在这个九宫格出现过，返回非
            {
                return 0;
            }
        }
    }
    return 1; //否则是真
}
void shuchu() //输出这个数组
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d ", num[i][j]);
        }
        printf("\n");
    }
}

void DFS(int flag)
{
    if (flag == 9 * 9) //如果所有空都被填满，传入输出结果函数，输出结果
    {
        shuchu();
        exit(0); //毁灭程序
    }
    else
    {
        if (num[flag / 9][flag % 9] != 0) //如果这个位置已经填好数字了，直接跳过即可
        {
            DFS(flag + 1); //搜索下一个
        }
        else //如果是空位，放数字
        {
            for (int i = 1; i <= 9; i++)
            {
                if ((x[flag / 9][i - 1] == 0) && (y[flag % 9][i - 1] == 0) && (inspect(flag / 9, flag % 9, i))) //这个数字在当前行和列没有重复并且在九宫格中也没有重复哦~ 我就放上去好了
                {
                    num[flag / 9][flag % 9] = i;    //把当前i放入数组
                    x[flag / 9][i - 1] = 1;         //在当前行已经使用过了
                    y[flag % 9][i - 1] = 1;         //在当前列已经使用过了
                    DFS(flag + 1);                  //搜索下一个
                    /*===========================*/ //还原现场，回溯
                    num[flag / 9][flag % 9] = 0;
                    x[flag / 9][i - 1] = 0;
                    y[flag % 9][i - 1] = 0;
                    /*===========================*/
                }
            }
        }
    }
}
int main()
{
    int i, j;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            scanf("%d", &num[i][j]);
            /*==================================*/
            if (num[i][j])
            {
                x[i][num[i][j] - 1] = 1; //标记这个数字在当前行已经被使用过
                y[j][num[i][j] - 1] = 1; //标记这个数字在当前行已经被使用过
            }
            /*==================================*/
        }
    }
    DFS(0); //调用深度优先搜索
    return 0;
}
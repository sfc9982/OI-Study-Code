#include <stdio.h>
#include <queue>
#include <string.h>
#include <iostream>
using namespace std;

typedef struct node
{
    int x;
    int y;
    int step;
} Node;

int map[310][310];
int dir[8][2] = {-1, 2, 1, 2, 2, 1, 2, -1, 1, -2, -1, -2, -2, -1, -2, 1};

void BFS(int n, int sx, int sy, int tx, int ty)
{
    if (sx == tx && sy == ty)
    {
        printf("0\n");
        return;
    }
    Node a;
    queue<Node> q;
    a.x = sx;
    a.y = sy;
    a.step = 0;
    map[sx][sy] = 1;
    q.push(a);
    while (!q.empty())
    {
        a.x = q.front().x;
        a.y = q.front().y;
        a.step = q.front().step;
        q.pop();
        if (a.x == tx && a.y == ty)
        {
            printf("%d\n", a.step);
            return;
        }
        for (int i = 0; i < 8; i++)
        {
            Node Next;
            Next.x = a.x + dir[i][0];
            Next.y = a.y + dir[i][1];
            Next.step = a.step + 1;
            if (Next.x >= 0 && Next.x < n && Next.y >= 0 && Next.y < n && map[Next.x][Next.y] == 0)
            {
                map[Next.x][Next.y] = 1;
                q.push(Next);
            }
        }
    }
}

int main()
{
    int nCase;
    int n;
    int sx, sy, tx, ty;
    scanf("%d", &nCase);
    for (int i = 0; i < nCase; i++)
    {
        memset(map, 0, sizeof(map));
        scanf("%d", &n);
        scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
        BFS(n, sx, sy, tx, ty);
    }
    return 0;
}
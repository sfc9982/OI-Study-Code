#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int r, c, li, ri;
int dist[512][512];
char map[512][512];
bool flag[512][512];
pair<int, int> queue[500010 * 2];

inline bool ok(int x, int y)
{
    if (x >= 0 && x <= r && y >= 0 && y <= c)
        return true;
    return false;
}

inline void add(int x, int y, int v)
{
    if (dist[x][y] < 0 || v < dist[x][y])
    {
        dist[x][y] = v;
        if (li == ri || v > dist[queue[li].first][queue[li].second])
            queue[ri++] = make_pair(x, y);
        else
            queue[--li] = make_pair(x, y);
    }
}
int main()
{
    int T;
    for (scanf("%d", &T); T; --T)
    {
        scanf("%d %d", &r, &c);
        if ((r + c) % 2)
        {
            for (int i = 0; i < r; i++)
                scanf("%s", map[i]);
            printf("NO SOLUTION\n");
        }
        else
        {

            for (int i = 0; i < r; i++)
                scanf("%s", map[i]);
            li = ri = 500010;
            queue[ri++] = make_pair(0, 0);
            memset(dist, -1, sizeof dist), dist[0][0] = 0;
            memset(flag, false, sizeof flag);
            while (li != ri)
            {
                int tx = queue[li].first, ty = queue[li].second;
                ++li;
                if (ok(tx - 1, ty - 1))
                {
                    if (map[tx - 1][ty - 1] == '\\')
                        add(tx - 1, ty - 1, dist[tx][ty]);
                    else
                        add(tx - 1, ty - 1, dist[tx][ty] + 1);
                }
                if (ok(tx - 1, ty + 1))
                {
                    if (map[tx - 1][ty] == '/')
                        add(tx - 1, ty + 1, dist[tx][ty]);
                    else
                        add(tx - 1, ty + 1, dist[tx][ty] + 1);
                }
                if (ok(tx + 1, ty - 1))
                {
                    if (map[tx][ty - 1] == '/')
                        add(tx + 1, ty - 1, dist[tx][ty]);
                    else
                        add(tx + 1, ty - 1, dist[tx][ty] + 1);
                }
                if (ok(tx + 1, ty + 1))
                {
                    if (map[tx][ty] == '\\')
                        add(tx + 1, ty + 1, dist[tx][ty]);
                    else
                        add(tx + 1, ty + 1, dist[tx][ty] + 1);
                }
            }
            printf("%d\n", dist[r][c]);
        }
    }
    return 0;
}
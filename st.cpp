#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int INF = 1e9;
char tstr[30][30];
int f[30][30];
int cnt, query, ans, lst;
int pre[30], fa[30], best[30], dist[30];
bool sta[30], flag[30], w[30][30];
char str[30][30];

int NameHash(char name[])
{
    bool flag = true;
    for (int i = 1; i <= cnt; i++)
        if (strcmp(name, tstr[i]) == 0)
        {
            flag = false;
            return i;
        }
    if (flag)
        strcpy(tstr[++cnt], name);
    return cnt;
}

void dfs(int rt)
{
    int i;
    for (i = 1; i <= cnt; i++)
        if (!flag[i] && !w[rt][i])
        {
            fa[i] = rt;
            flag[i] = true;
            dfs(i);
        }
}

void prim(int s)
{
    int i, j, min, k;
    memset(flag, true, sizeof(flag));
    for (i = 1; i <= cnt; i++)
    {
        pre[i] = s;
        dist[i] = f[s][i];
    }
    flag[s] = false;
    sta[s] = false;
    while (1)
    {
        min = INF;
        k = -1;
        for (i = 1; i <= cnt; i++)
            if (sta[i] && flag[i] && dist[i] < min)
            {
                min = dist[i];
                k = i;
            }
        if (k == -1)
            break;
        flag[k] = false;
        sta[k] = false;
        w[pre[k]][k] = w[k][pre[k]] = false;
        ans += min;
        for (i = 1; i <= cnt; i++)
            if (sta[i] && flag[i] && f[k][i] < dist[i])
            {
                dist[i] = f[k][i];
                pre[i] = k;
            }
    }
    min = INF;
    int rt = -1;
    for (i = 1; i <= cnt; i++)
        if (!flag[i] && f[lst][i] < min && i != lst)
        {
            min = f[lst][i];
            rt = i;
        }
    flag[rt] = true;
    dfs(rt);
    fa[rt] = lst;
    ans += min;
}
int getmax(int j)
{
    if (fa[j] == lst)
        return best[j] = -1;
    if (best[j] != -1)
        return best[j];
    int tmp = getmax(fa[j]);
    if (tmp != -1)
    {
        if (f[tmp][fa[tmp]] > f[fa[j]][j])
            best[j] = tmp;
        else
            best[j] = j;
    }
    else
        best[j] = j;
    return best[j];
}
void solve()
{
    int i, j;
    int mst = 0;
    memset(fa, -1, sizeof(fa));
    memset(sta, true, sizeof(sta));
    memset(w, true, sizeof(w));
    sta[lst] = false;
    for (i = 1; i <= cnt; i++)
        if (sta[i])
        {
            mst++;
            prim(i);
        }
    for (i = mst + 1; i <= cnt && i <= query; i++)
    {
        memset(best, -1, sizeof(best));
        for (j = 1; j <= cnt; j++)
            if (j != lst && best[j] == -1 && fa[j] != lst)
                getmax(j);
        int minadd = INF;
        int tx, ty, to;
        for (j = 1; j <= cnt; j++)
            if (f[lst][j] != INF && fa[j] != lst)
            {
                tx = best[j];
                ty = fa[tx];
                if (minadd > f[lst][j] - f[tx][ty])
                {
                    minadd = f[lst][j] - f[tx][ty];
                    to = j;
                }
            }
        if (minadd >= 0)
            break;
        ans += minadd;
        tx = best[to];
        ty = fa[tx];
        f[tx][ty] = f[ty][tx] = INF;
        fa[to] = lst;
        f[lst][to] = f[to][lst] = INF;
    }
}

int main()
{
    char c1[30], c2[30];
    int n, x, y, dis;
    for (x = 1; x <= 30 - 1; x++)
        for (y = 1; y <= 30 - 1; y++)
            f[x][y] = INF;
    scanf("%d", &n);
    cnt = 0;
    while (n--)
    {
        scanf("%s%s%d", &c1, &c2, &dis);
        x = NameHash(c1);
        y = NameHash(c2);
        if (f[x][y] > dis)
            f[x][y] = f[y][x] = dis;
    }
    strcpy(c1, "Park");
    lst = NameHash(c1);
    scanf("%d", &query);
    ans = 0;
    solve();
    printf("Total miles driven: %d\n", ans);
    system("pause");
    return 0;
}
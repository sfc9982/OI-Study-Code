#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, m;
char map[105][105];
int cnt = 0;
int i ,j;
void Init()
{
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    memset(map, '0', sizeof(map));
    cin >> n >> m;
    
     //   memset(map, '0', sizeof(map));
    //cin >> n >> m;
    
   //     scanf("%d%d\n",&n,&m);
    for(i=1;i<=n;i++) 
        for(j=1;j<=m;j++) 
            cin>>map[i][j]; 

    return;
}

void Input1()
{
    for (int i = 1; i <= n; i++)
    {
        gets(map[i] );
    }
    return;
}

void dfs(int x, int y, bool first)
{
    if (x < 1 || y < 1 || y > m  || x > n )
         return;
    if (map[x][y] != '#')
    {
        return;
    }
    else
    { 
        map[x][y] = '-';
    }

    dfs(x + 2, y, false);
    dfs(x + 1, y + 1, false);
    dfs(x + 1, y, false);
    dfs(x + 1, y - 1, false);
    dfs(x, y + 2, false);
    dfs(x, y + 1, false);
    dfs(x, y - 1, false);
    dfs(x, y - 2, false);
    dfs(x - 1, y + 1, false);
    dfs(x - 1, y, false);
    dfs(x - 1, y - 1, false);
    dfs(x - 2, y, false);

    if (first)
    {
        cnt++;
    }
    return;
}

void Search()
{
    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= m; x++)
        {
            dfs(y, x, true);
        }
    }
    return;
}

int main()
{
    Init();
    //Input1();
    Search();
    /*/for (int y = 1; y <= n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            cout << map[y][x] << " ";
        }
        cout << endl;
    }*/
    cout << cnt ;
   // system("pause");
    return 0;
}


#include<bits/stdc++.h>
#define sc second;
using namespace std;
vector<int>v[350110],e[350110];
bool vis[350110];
priority_queue< pair<int,int> > q;
int t,r,c,dist[350110];
char ff;
void dij()
{
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    q.push(make_pair(0,1));
    while(q.size())
    {
        int x=q.top().sc;q.pop();
        if(vis[x]) continue;
        vis[x]=1;
        for(register int i=0;i<v[x].size();i++)
        {
            int y=v[x][i],z=e[x][i];
            if(dist[y]>dist[x]+z)
            {
                dist[y]=dist[x]+z;
                q.push(make_pair(-dist[y],y));
            }
        }
        if(vis[(r+1)*(c+1)]==1)
        {
        	cout<<dist[(r+1)*(c+1)]<<endl;
        	return;
        }
    }
}
int main()
{
    cin>>t;
    for(register int l=1;l<=t;l++)
    {
        for(register int y=1;y<=(r+1)*(c+1);y++) vis[y]=0;
        while(q.size())
        {
            q.pop();
        }
        for(register int x=1;x<=(r+1)*(c+1);x++)
        {
            v[x].clear();e[x].clear();
        }
        cin>>r>>c;
        for(register int i=1;i<=r;i++)
        for(register int j=1;j<=c;j++)
        {
            cin>>ff;
            if(ff=='\\')
            {
                v[(i-1)*(c+1)+j].push_back((i-1)*(c+1)+j+c+2);e[(i-1)*(c+1)+j].push_back(0);
                v[(i-1)*(c+1)+j+c+2].push_back((i-1)*(c+1)+j);e[(i-1)*(c+1)+j+c+2].push_back(0);
                v[(i-1)*(c+1)+j+1].push_back((i-1)*(c+1)+j+c+1);e[(i-1)*(c+1)+j+1].push_back(1);
                v[(i-1)*(c+1)+j+c+1].push_back((i-1)*(c+1)+j+1);e[(i-1)*(c+1)+j+c+1].push_back(1);
            }
            if(ff=='/')
            {
                v[(i-1)*(c+1)+j].push_back((i-1)*(c+1)+j+c+2);e[(i-1)*(c+1)+j].push_back(1);
                v[(i-1)*(c+1)+j+c+2].push_back((i-1)*(c+1)+j);e[(i-1)*(c+1)+j+c+2].push_back(1);
                v[(i-1)*(c+1)+j+1].push_back((i-1)*(c+1)+j+c+1);e[(i-1)*(c+1)+j+1].push_back(0);
                v[(i-1)*(c+1)+j+c+1].push_back((i-1)*(c+1)+j+1);e[(i-1)*(c+1)+j+c+1].push_back(0);
            }
        }
        dij();
        if(vis[(r+1)*(c+1)]==0) cout<<"NO SOLUTION"<<endl;
    }
}
#include<bits/stdc++.h>
using namespace std;
#define re register
#define il inline
il int read()
{
    re int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*f;
}
struct Edge
{
    int u,v,w;
}edge[200005];
int fa[5005],n,m,ans,eu,ev,cnt;
il bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
//���ŵ����ݣ�����Ȩ����
il int find(int x)
{
    while(x!=fa[x]) x=fa[x]=fa[fa[x]];
    return x;
}
//���鼯ѭ��ʵ��ģ�壬��·��ѹ�����������鼯��ͬѧ���Դ�һ�������Ϸ��ġ����鼯��⡱
il void kruskal()
{
    sort(edge,edge+m,cmp);
    //���ߵ�Ȩֵ����
    for(re int i=0;i<m;i++)
    {
        eu=find(edge[i].u), ev=find(edge[i].v);
        if(eu==ev)
        {
            continue;
        }
        //�������������Ѿ���ͨ�ˣ���˵����һ���߲���Ҫ��
        ans+=edge[i].w;
        //���˱�Ȩ�����
        fa[ev]=eu;
        //��eu��ev�ϲ�
        if(++cnt==n-1)
        {
            break;
        }
        //ѭ������������������Ϊ������һʱ
    }
}
int main()
{
    n=read(),m=read();
    for(re int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    //��ʼ�����鼯
    for(re int i=0;i<m;i++)
    {
        edge[i].u=read(),edge[i].v=read(),edge[i].w=read();
    }
    kruskal();
    printf("%d",ans);
    return 0;
}

#include <bits/stdc++.h>

int a,i,j,k,m,n,l,r,xx,yy;
int p[1000][7000];
bool b[150000],e[200000], bb[150000];
int x[200000], y[200000], f[200000], g[200000];

void sc(int xx,int yy)
{
	int i;
	for (int i = 1; i <= p[xx][0]; i++)
	{ 
		if (p[xx][i] == yy)
		{ 
			p[xx][i] = 0;
			break;
		}
	}
}

void dfs(int x);
{
	int ii;
	bb[x] = true;
	for (int ii = 1; ii <= p[x][0]; ii++) 
	{ 
		if (p[x][ii]=yy)
		{ 
			b[i] = true;
			break;
		}
		if ((p[x][ii]!=0) && (bb[p[x][ii]]=false))
			dfs(p[x][ii]);
		if (b[i])
			break;
	}
}

int find(int x)
{ 
	if (f[x]!=x)
		f[x] = find(f[x]);
	return f[x];
}

void union(int x, int y);
{ 
	x = find(x);
	y = find(y);
	if (x != y)
		f[x] = y;
}

int main()
{
	cin >> n >> m;
	memset(b, false, sizeof(b));
	for (int i = 1; i <= n; i++)
		p[i][0]	=0;
	for (int i = 1; i <= m; i++)
	{ 
		cin >> x[i] >> y[i];
		p[x[i]][0]++;
		p[x[i],p[x[i]][0]]=y[i];
		p[y[i]][0]++;
		p[y[i],p[y[i]][0]]=x[i];
	}
	cin >> k >> a;	
	xx=x[a];
	yy=y[a];
	sc(xx,yy);
	sc(yy,xx);
	memset(bb, false, sizeof(bb));
	dfs(xx);
	if (b[i])
		cout << ":(" << endl;
	else
		cout << ":)" << endl;	
	for (int i = 2; i <= k; i++)
	{ 
		cin >> l >> r;
		if (b[i-1])
		{ 
		xx=x[r]; yy=y[r];
		}
		else
		{
		}
	}
}

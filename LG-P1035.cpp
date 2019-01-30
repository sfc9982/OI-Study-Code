#include <iostream>
#include <cstring>

using namespace std;

char top;

struct Node
{
    char p, l, r;
} node[300];

bool e[300];
char fa[300];

void Top(char x)
{
    if (e[fa[x]])
    {
        top = node[fa[x]].p;
        Top(node[fa[x]].p);
    }
    else
        top = x;
}

void It(char x)
{
	if (x ^ '*')
    	cout << x;
    if (node[x].l)
        It(node[x].l);
    if (node[x].r)
        It(node[x].r);
    return;
}

int main()
{
    memset(node, 0, sizeof(node));
    memset(e, 0, sizeof(e));
    char f, le, ri;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> f;
        if (i == 1)
            top = f;
        node[f].p = f;
        e[f] = 1;
        cin >> node[f].l;
        cin >> node[f].r;
        fa[le] = fa[ri] = f;
    }
    Top(top);
    It(top);
    //system("pause");
    return 0;
}

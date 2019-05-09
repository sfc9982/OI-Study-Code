#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char ss[10010],s[10001000];
int main()
{
    int n,tot;
    cin>>n;
    for(int i=1;i<=n;i+=72)
    {
        scanf("%s",ss+1);
        for(int j=1;j<=72;j++)
        s[++tot]=ss[j];
    }
    for(int i=1;i<=n;i++)
    s[i+n]=s[i];
    int i=1,j=2,k=0;
    while((i<=n&&j<=n)&&k<=n)
    {
        if(s[i+k]==s[j+k]) k++;
        else
        {
            if(s[i+k]<s[j+k]) j+=k+1;
            else i+=k+1;
            k=0;
            if(i==j) j++;
        }
    }
    cout<<i-1<<endl;
}
#include<cstdio>
#include <iostream>
#include<algorithm>
#define maxn 20010
#define r register
using namespace std;
int n = maxn,m,k[maxn],num,a,b,first[maxn],next0[maxn<<1],to[maxn<<1];
int tmp,head,tail,cnt,size,q[maxn],deg[maxn],ans[maxn],now[maxn];
bool vis[maxn];
int read()
{
	r char ch=getchar();r int in=0;
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch<='9'&&ch>='0') in=(in<<1)+(in<<3)+ch-'0',ch=getchar();
	return in;
}
void dfs(r int x)
{
	vis[x]=1,now[++size]=x;
	for(r int i=first[x];i;i=next0[i])
		if(!vis[to[i]]) dfs(to[i]);
}
int main()
{
    char ch0;
    int n0, m0;
    cin >> n0;
    while (n0--) {
	cin >> m >> m0;
	for (int i = 0; i < maxn; ++i) {
	    k[i] = 1;
    }
	for(r int i=1;i<=m;i++)
	{
	    cin >> ch0;
	    cin >> a;
	    cin >> ch0;
	    cin >> ch0;
	    cin >> b;
		deg[a]++,deg[b]++;
		to[++num]=b,next0[num]=first[a],first[a]=num;
		to[++num]=a,next0[num]=first[b],first[b]=num;
	}
	for (int i = 0; i < m0; ++i) {
	    
	    int k0;
	    cin >> ch0;
	    cin >> k0;
	    k[k0] = 2;
    }
	for(r int i=1;i<=n;i++)
		if(deg[i]<k[i]) vis[i]=1,q[++tail]=i;
	while(head<tail)
	{
		tmp=q[++head];
		for(r int i=first[tmp];i;i=next0[i])
			if(!vis[to[i]])
			{
				deg[to[i]]--;
				if(deg[to[i]]<k[i])
					vis[to[i]]=1,q[++tail]=to[i];
			}
	}
	for(r int i=1;i<=n;i++)
		if(!vis[i])
		{
			size=0,dfs(i);
			if(size<=cnt) continue;
			cnt=size;
			for(r int j=1;j<=cnt;j++) ans[j]=now[j];
		}
	if(!cnt) puts("None");
	else printf("%d\n",cnt);
    }
	return 0;
}

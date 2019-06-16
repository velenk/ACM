#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#define md 1000000007
using namespace std;
typedef long long int ll;
int n,m;
ll w[100005];
vector<int>g[100005];
ll gcd(ll u,ll v)
{
    if(v==0)return u;
    return gcd(v,u%v);
}
int tot,dfn[100005],low[100005],cut[100005],vis[100005];
ll ans[100005],dwn[100005],dwn2[100005];
ll am=1;
ll rev(ll x){
	if(x==0||x==1)return 1;
	return(md-md/x)*rev(md%x)%md;
}
void tarjan(int now,int fa)
{
 //   pre[now]=pre[now-1]*w[now]%md;
    am=am*w[now]%md;
    dwn[now]=dwn2[now]=w[now];
    vis[now]=fa;
    int rc=0;
    dfn[now]=low[now]=++tot;
    cut[now]=ans[now]=0;
    for(int i=0;i<g[now].size();i++)
    {
        int v=g[now][i];
        if(!dfn[v])
        {
            tarjan(v,fa);
            dwn[now]=dwn[now]*dwn[v]%md;
            low[now]=min(low[now],low[v]);
            if(low[v]>=dfn[now])
            {
                if(now!=fa)cut[now]=1;
                ans[now]=(ans[now]+dwn[v])%md;
                dwn2[now]=dwn2[now]*dwn[v]%md;
          //      printf("dwn[%d]=%lld ans[%d]=%lld\n",v,dwn[v],now,ans[now]);
            }
            if(now==fa)rc++;
        }
        low[now]=min(low[now],dfn[v]);
    }
    if(now==fa&&rc>=2)cut[fa]=1;
    
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        tot=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)g[i].clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&w[i]);
        }
        for(int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            g[x].push_back(y);g[y].push_back(x);
        }
     //   pre[0]=1
        ll allans=0;
        for(int j=1;j<=n;j++)
        {
            if(!dfn[j])
            {
                tot=0;am=1;
                tarjan(j,j);
                for(int i=1;i<=n;i++)
                {
                    if(vis[i]!=j)continue;
                    if(!cut[i])ans[i]=am*rev(w[i])%md;
                    else if(i!=j)ans[i]=(ans[i]+am*rev(dwn2[i])%md)%md;
                   printf("%lld\n",ans[i]);
                }
            }
        }
        for(int i=1;i<=n;i++)allans=(allans+(ll)i*ans[i])%md;
        printf("%lld\n",allans);
        
    }
}

#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdio>
#include <queue>
#include <stack>
using namespace std;
#define maxx 1005
#define inf 0x3f3f3f3f
#define ll long long
int head[maxx],n,m,s,t,dep[maxx];
int cnt;
struct Edge
{
    int v,next;
    ll cap;
}edge[maxx<<1];
void init()
{
    cnt=0;
    memset(head,-1,sizeof(head));
    memset(dep,0,sizeof(dep));
    memset(edge,0,sizeof(edge));
}
void add_edge(int u,int v,ll cap)
{
    edge[cnt].v=v;
    edge[cnt].cap=cap;
    edge[cnt].next=head[u];
    head[u]=cnt++;
 
    edge[cnt].v=u;
    edge[cnt].cap=0;
    edge[cnt].next=head[v];
    head[v]=cnt++;
}
//bfs
int bfs(int s,int t)
{
    memset(dep,0,sizeof(dep));
    queue<int >q;
    q.push(s);
    dep[s]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].v;
            if(dep[v]==0&&edge[i].cap>0)
            {
                dep[v]=dep[u]+1;
                q.push(v);
            }
        }
    }return dep[t]!=0;
}
ll dfs(int u,int t,ll low)
{
    if(u==t||low==0) return low;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        ll v=edge[i].v;
        if(dep[v]==dep[u]+1 && edge[i].cap>0)
        {
            ll f=dfs(v,t,min(edge[i].cap,low));
            if(f>0)
            {
                edge[i].cap-=f;
                edge[i^1].cap+=f;
                return f;
            }
        }
    }
    return 0;
}
ll Dinic(int s,int t)
{
    ll ans=0;
    while(bfs(s,t))
    {
        ll f;
        while((f=dfs(s,t,inf))>0)
        {
            ans+=f;
        }
    }
    return ans;
}
int main()
{
    int n0;
    scanf("%d", &n0);
    while (n0--){
    double sum0 = 0;
    init();
    scanf("%d%d%d%d",&n,&m,&s,&t);
    
    while(m--)
    {
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        add_edge(u,v,c*2000+1);
        sum0 += c;
    }
    ll ans=Dinic(s,t);
    if (ans == 0) {
        printf("Inf\n");
    } else {
        printf("%.2lf\n",(sum0-ans/2000)/(ans%2000));
    }
    }
    return 0;
}

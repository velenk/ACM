#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <stack>
using namespace std;
#define maxn 400005
#define maxm maxn*2
#define mod 1000000007

int n, m;
int pre[maxn],dfs_clock,iscut[maxn],low[maxn],bcc_cnt,bccno[maxn];  
vector<int>G[maxn],bcc[maxn];  
struct Edge  
{  
    int u,v;  
    Edge(int from,int to)  
    {  
        u=from;  
        v=to;  
    }  
};  
stack<Edge> S;  
int tarjan (int u,int fa)  
{  
    int lowu=pre[u]=++dfs_clock;  
    int child=0;  
    int Max = G[u].size ();
    for(int i=0;i<Max;i++)  
    {  
        int v=G[u][i];  
        Edge e = Edge(u,v);  
        if(!pre[v])  
        {  
            S.push(e);  
            child++;  
            int lowv= tarjan (v,u);  
            lowu=min(lowv,lowu);  
            if(lowv>=pre[u])  
            {  
                iscut[u]=true;  
                bcc_cnt++;bcc[bcc_cnt].clear();  
                for(;;)  
                {  
                    Edge x = S.top();S.pop();  
                    if(bccno[x.u]!=bcc_cnt)  
                    {  
                        bcc[bcc_cnt].push_back(x.u);  
                        bccno[x.u]=bcc_cnt;  
                    }  
                    if(bccno[x.v]!=bcc_cnt)  
                    {  
                        bcc[bcc_cnt].push_back(x.v);  
                        bccno[x.v]=bcc_cnt;  
                    }  
                    if(x.u==u&&x.v==v) break;  
                }  
            }  
        }  
        else if(pre[v]<pre[u]&&v!=fa)  
        {  
            S.push(e);  
            lowu=min(lowu,pre[v]);  
        }  
    }  
    if(fa<0&&child==1) iscut[u]=0;  
    return lowu;  
}  
void find_bcc ()  
{  
    memset (pre,0,sizeof(pre));  
    memset (iscut,0,sizeof(iscut));  
    memset (bccno,0,sizeof(bccno));  
    dfs_clock=bcc_cnt=0;  
    for(int i=1; i <=n; i++)  
        if(!pre[i]) tarjan(i,-1);  
}  

long long a[maxn];
struct node {
    int v, next;
}edge[maxm];
int head[maxn], cnt;
int degree[maxn];//用来判断孤立点
int root[maxn];
bool vis[maxn];
long long sum[maxn], mul[maxn];

void add_edge (int u, int v) { 
    edge[cnt].v = v, edge[cnt].next = head[u], head[u] = cnt++;
}

void dfs (int u, int fa, int rt) {
    vis[u] = 1;
    root[u] = rt;
    sum[u] = 0;
    mul[u] = a[u];
    for (int i = head[u]; i != - 1; i = edge[i].next) {
        int v = edge[i].v;
        if (v == fa) continue;
        dfs (v, u, rt);
        sum[u] = (sum[u] + mul[v]) % mod;
        mul[u] = mul[u] * mul[v] % mod;
    }
}

long long extend_gcd(long long a,long long b,long long &x,long long &y)  
{  
    if(a==0&&b==0) return -1;  
    if(b==0){x=1;y=0;return a;}  
    long long d=extend_gcd(b,a%b,y,x);  
    y-=a/b*x;  
    return d;  
}  
long long mod_rev(long long a,long long n)  
{  
    long long x,y;  
    long long d=extend_gcd(a,n,x,y);  
    if(d==1) return (x%n+n)%n;  
    else return -1;  
}  

void solve () {
    memset (head, -1, sizeof head);
    cnt = 0;
    for (int i = 1; i <= bcc_cnt; i++) {
        int u = i+n, Max = bcc[i].size ();
        a[u] = 1;
        for (int j = 0; j < Max; j++) { 
            int v = bcc[i][j]; 
            add_edge (u, v);
            add_edge (v, u);
        }
    }
    memset (vis, 0, sizeof vis);
    long long tot = 0;
    for (int i = 1; i <= n+bcc_cnt; i++) {
        if (!vis[i]) {
            dfs (i, -1, i);
            tot = (tot+mul[i]) % mod;
        }
    } 
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        long long tmp = 0, niyuan;
        if (!degree[i]) {
            tmp = ((tot-a[i])%mod + mod) % mod;
        }
        else if (!iscut[i]) {
            niyuan = mod_rev (a[i], mod);
            long long cur = mul[root[i]] * niyuan % mod;
            tmp = (tot - mul[root[i]] + cur);
            tmp = (tmp % mod + mod) % mod;
        }
        else {
            niyuan = mod_rev (mul[i], mod);
            long long cur; 
            if (root[i] != i) {
                cur = mul[root[i]] * niyuan % mod;
            }
            else 
                cur = 0;
            cur = (cur + sum[i]) % mod;
            tmp = (tot - mul[root[i]] + cur);
            tmp = (tmp % mod + mod) % mod;
        }
        ans = ans+1LL*i*tmp%mod; 
        ans %= mod;
    }
    printf ("%lld\n", ans);
}

int main () {
    int t;
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf ("%lld", &a[i]);
            G[i].clear ();
            degree[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf ("%d%d", &u, &v);
            degree[u]++, degree[v]++;
            G[u].push_back (v);
            G[v].push_back (u);
        }
        find_bcc ();
        solve ();
    }
    return 0;
}

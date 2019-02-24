#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge{
    int next;
    int to;
    int flow;
    int v;
};
struct fa{
    int x;
    int e;
};
edge a[200005];
fa father[10005];
int h[10005],r,w,k,n,m,s,e,u,v,d;
int remain[10005];
int b[10005];
bool f[10005];
void read(int x,int y,int z){
    a[k].next=h[x];
    a[k].to=y;
    a[k].v=z;
    h[x]=k;
    k++;
    a[k].next=h[y];
    a[k].to=x;
    a[k].v=0;
    h[y]=k;
    k++;
}
int bfs(){
    memset(f,false,sizeof(f));
    r=0; w=1;
    b[w]=s;
    f[s]=true;
    remain[s]=0x7fffffff;
    while (r<w){
        int x=b[++r];
        for (int i=h[x];~i;i=a[i].next){
            if (!f[a[i].to]&&a[i].v-a[i].flow>0){
                w++;
                b[w]=a[i].to;
                f[a[i].to]=true;
                father[a[i].to].x=x;
                father[a[i].to].e=i;
                remain[a[i].to]=min(remain[x],a[i].v-a[i].flow);
                if (a[i].to==e) return remain[e];
            }
        }
    }
    return 0;
}
void change(int x){
    int now=e;
    while (now!=s){
        int ed=father[now].e;
        a[ed].flow+=x;
        a[ed^1].flow-=x;
        now=father[now].x;
    }    
}
int maxflow(){
    int ans=0;
    while (1){
        int sum;
        sum=bfs();
        if (!sum)
            break;
        ans+=sum;
        change(sum);
    }
    return ans;
}
int main(){
    int n0;
    scanf("%d", &n0);
    while (n0--){
    double sum0 = 0;
    scanf("%d%d%d%d",&n,&m,&s,&e);
    memset(h,-1,sizeof(h));
    for (int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&d);
        read(u,v,d);
    }
    int ans = maxflow();
    if (ans == 0) {
        printf("Inf\n");
    } else {
        printf("%.2lf\n",(sum0-ans)/ans);
    }
    }
    return 0;
}

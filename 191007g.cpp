#include <cstdio>
#include <unordered_map>
#include <algorithm>
using namespace std;
typedef long long LL;
LL f[200005];
LL x, y, a, b;
LL cal(LL n, LL k){
    return max(f[k-1]+b,f[n-k]+a);
}
int main()
{
    LL T;
    scanf("%lld", &T);
    while(T--)
    {
        f[0] = 0;
        scanf("%lld%lld%lld%lld", &x, &y, &a, &b);
        for(int i=1;i<=y-x;i++){
            int l=1,r=i,m1,m2;
            while(l<r){
                m1=l+(r-l)/3;
                m2=r-(r-l)/3;
                LL aa=cal(i,m1),bb=cal(i,m2);
                if(aa>bb)l=m1+1;else
                if(aa<bb)r=m2-1;else{
                    if(l==m1&&r==m2)l=m1+1,r=m2-1;else
                    l=m1,r=m2;
                }
            }
            f[i]=min(cal(i,l),cal(i,r));
        }
        printf("%lld\n", f[y-x]);
    }
    return 0;
}

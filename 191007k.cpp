#include <cstdio>
typedef long long LL;
const LL MOD = 1e9+7;
const LL maxn = 6e5+5;
LL qpow(LL base, LL expo)
{
    LL ans = 1;
    while(expo)
    {
        if(expo & 1LL)
            ans = ans * base % MOD;
        expo >>= 1LL;
        base = base * base % MOD;
    }
    return ans;
}
LL E_sum[maxn], E;
LL inv(LL num){return qpow(num, MOD-2);}
LL calc(LL son, LL mom){return mom*inv(son)%MOD;}
int main()
{
    LL T;
    scanf("%lld", &T);
    while(T--)
    {
        E_sum[0] = E_sum[1] = 0;
        LL n, q;
        scanf("%lld%lld", &n, &q);
        for(LL i = 1;i <= n;i++)
        {
            LL ri, si, xi, ai;
            scanf("%lld%lld%lld%lld", &ri, &si, &xi, &ai);
            E = calc(ri, si)*ai%MOD + (calc(ri, si)+MOD-1)%MOD * (E_sum[i]-E_sum[xi] + MOD) % MOD;
//            printf("[DEBUG]%lld->%lld: %lld\n", i,i+1,E);
            E_sum[i+1] = (E_sum[i] + E)%MOD;
        }
        while(q--)
        {
            LL li, ri;
            scanf("%lld%lld", &li, &ri);
            printf("%lld\n", (E_sum[ri]-E_sum[li]+MOD)%MOD);
        }
    }
    return 0;
}
/*
1
3 2
1 1 1 2
1 2 1 3
1 3 3 4
1 4
3 4

1
3 3
1 1 1 2
1 2 1 3
1 3 3 4
1 4
3 4
3 3
*/

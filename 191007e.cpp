#include <cstdio>
typedef long long LL;
const LL MOD = 1e9+7;
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
int main()
{
    LL n = 4;
//    for(LL m = 3;m <= 101;m += 2)
//    {
//        LL cnt = 0, x0, x1, x2;
//        for(LL i = 0;i < m*m*m;i++)
//        {
//            LL i0 = i;
//            x0 = i0 % m;
//            i0 /= m;
//            x1 = i0 % m;
//            i0 /= m;
//            x2 = i0 % m;
//            i0 /= m;
//            if((x0*x0+x1*x1)%m == (x2*x2)%m)
//                {cnt++;if(m==1)printf("%lld %lld %lld\n", x0, x1, x2);}
//        }
////        if(cnt != m*m)
//            printf("%lld %lld: %lld\n", n, m, cnt);
//    }
    for(LL m = 3;m <= 30;m += 2)
    {
        LL cnt = 0, x0, x1, x2,x3;
        for(LL i = 0;i < m*m*m*m;i++)
        {
            LL i0 = i;
            x0 = i0 % m;
            i0 /= m;
            x1 = i0 % m;
            i0 /= m;
            x2 = i0 % m;
            i0 /= m;
            x3 = i0 % m;
            i0 /= m;
            if((x0*x0+x1*x1+x2*x2)%m == (x3*x3)%m)
                cnt++;
        }
        if(cnt != m*m*m)
            printf("%lld %lld: %lld\n", n, m, cnt);
    }
//    LL T;
//    scanf("%lld", &T);
//    while(T--)
//    {
//        LL n, m;
//        scanf("%lld%lld", &n, &m);
//        printf("%lld\n", qpow(m, n-1));
//    }
    return 0;
}

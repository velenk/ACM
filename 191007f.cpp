#include <stdio.h>
typedef long long LL;
int main()
{
    LL T;
    scanf("%lld", &T);
    while(T--)
    {
        LL n, m, k;
        scanf("%lld%lld%lld", &n, &m, &k);
        printf("%lld\n", ((m+1-1)/(n-k+1)+1)*(k-1)+m+1);
    }
    return 0;
}

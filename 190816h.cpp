#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 1e5 + 5;
struct Node{LL a, b;}nodes[maxn];
bool cmp(const Node &lhs, const Node &rhs){return (lhs.a * rhs.b < rhs.a * lhs.b) || (lhs.a * rhs.b == rhs.a * lhs.b && lhs.b > rhs.b);}
int main()
{
    LL T;
    scanf("%lld", &T);
    for(LL kase = 1;kase <= T;kase++)
    {
        LL n, round = 0, ATK = 0;
        scanf("%lld", &n);
        for(LL i = 1;i <= n;i++)
        {
            LL HP, hp, atk;
            scanf("%lld%lld", &HP, &atk);
            hp = sqrt(2*HP);
            if(hp*(hp+1)/2 < HP) hp++;
            nodes[i].a = hp, nodes[i].b = atk;
            round += hp;
            ATK += atk;
        }
//        printf("%lld %lld\n", round, ATK);
        sort(nodes+1, nodes+n+1, cmp);
//        for(LL i = 1;i <= n;i++)
//            printf("%lld %lld\n", nodes[i].a, nodes[i].b);
        LL ans = round * ATK, sum = 0;
        for(LL i = 1;i <= n;i++)
        {
            sum += nodes[i].a;
            ans -= ((round - sum) * nodes[i].b);
        }
        printf("Case #%lld: %lld\n", kase, ans);
    }
    return 0;
}
/*
2
3
1 1
2 2
3 3
3
3 1
2 2
1 3
*/

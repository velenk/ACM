#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

ll T, n, k;
ll t[100010];
ll temp;
ll cnt;
ll sum;

ll cmp(ll a, ll b) {
    return a>b;
}

int main() {
    scanf("%lld", &T);
    while(T--) {
        scanf("%lld%lld", &n, &k);
        cnt = 0;
        for (ll i=0; i<n; i++) {
            scanf("%lld", &temp);
            cnt += temp/k;
            t[i] = temp;
        }
        
        if (cnt >= n-1) {
            sum = k;
            for (ll i=0; i<n; i++) {
                sum += t[i];
            }
            printf("%lld\n", sum);
        } else {
            for (ll i=0; i<n; i++) {
                t[i] = t[i] % k;
            }
            
            sort(t, t+n, cmp);
            
            sum = n*k;
            for (ll i=n-1-cnt; i<n; i++) {
                sum += t[i];
            }
            printf("%d", sum);
            if (T != 0) printf("\n");
        }
    }
    return 0;
}

/*
2
3 5
5 5 8
2 4
3 3
*/

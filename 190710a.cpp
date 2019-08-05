#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

typedef long long LL;

#define p 97
#define mod 1000000007
#define MAXN 1000500

LL n,m,a[MAXN], b[MAXN], nex[MAXN], tem[MAXN], difa[MAXN], difb[MAXN], F[MAXN], x,y;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%lld", &b[i]);
    }
    
    for (int i = n; i >= 1; i--) {
        nex[i] = tem[a[i]];
        tem[a[i]] = i;
    }
    
    memset(tem, 0, sizeof(tem));
    for (int i = 1; i <= n; i++) {
        if (!tem[a[i]]) {
            difa[i] = 0;
        } else {
            difa[i] = i - tem[a[i]];
        }
        tem[a[i]] = i;
    }
    
    memset(tem, 0, sizeof(tem));
    for (int i = 1; i <= m; i++) {
        if (!tem[b[i]]) {
            difb[i] = 0;
        } else {
            difb[i] = i - tem[b[i]];
        }
        tem[b[i]] = i;
    }
    
    F[0] = 1LL;
    for (int i = 1; i <= n+1; i++) {
        F[i] = F[i-1] * p % mod;
    }
    
    x = y = 0;
    for (int i = 1; i <= m; i++) {
        x = (x * p + difb[i]) % mod;
        y = (y * p + difa[i]) % mod;
    }
    
    LL ans = 0;
    
    /*for (int i = 1; i <= m; i++) {
        cout << difb[i] << ends;
    }*/
    
    for (int i = 0; i+m<=n; i++) {
        if (x == y) ans++;
        
        if (nex[i+1] && nex[i+1] <= i+m) {
            LL d = i + m - nex[i+1];
            y = (y - difa[nex[i+1]] * F[d]) % mod;
            if (y < 0) y += mod;
        }
        difa[ nex[i+1] ] = 0;
        y = (y - difa[i+1] * F[m-1]) % mod;
        if (y < 0) y += mod;
        y = (y * p + difa[i+m+1]) % mod;
    }
    
    cout << ans << endl;
    
    return 0;
}

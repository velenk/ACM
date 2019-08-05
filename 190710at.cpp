#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define p 97
#define mod 1000000007
#define N 1000500

inline int rd() {int r;scanf("%d",&r);return r;	}
int n, m, a[N], b[N], nex[N], tmp[N];
LL difa[N], difb[N], F[N], M, x;

int main() {
	n = rd(), m = rd();
	for (int i=1;i<=n;i++) a[i] = rd();
	for (int i=1;i<=m;i++) b[i] = rd();
	for (int i=n;i>=1;i--) {
		nex[i] = tmp[a[i]];
		tmp[a[i]] = i;
	}
	
	memset(tmp, 0, sizeof(tmp));
	for (int i=1;i<=n;i++) {
		if (!tmp[a[i]])
			difa[i] = 0;
		else
			difa[i] = i - tmp[a[i]];
		tmp[a[i]] = i;
	}
	
	memset(tmp, 0, sizeof(tmp));
	for (int i=1;i<=m;i++) {
		if (!tmp[b[i]])
			difb[i] = 0;
		else
			difb[i] = i-tmp[b[i]];
		tmp[b[i]] = i;	
	}
	
	for (int i=1;i<=m;i++)
		M = (97LL * M + difb[i]) % mod;	
	
	for (int i=1;i<=m;i++) {
		x = (97LL * x + difa[i]) % mod;	
	}
	
	F[0] = 1LL;
	for (int i=1;i<=n+1;i++) F[i] = F[i-1] * 97LL % mod;
	
	int ans = 0;
	for (int i=0;i+m<=n;i++) {
		if (M == x) ans++;
		if (nex[i+1] && nex[i+1] <= i+m) {
			int d = i+m - nex[i+1];
			x = (x - 1LL * difa[ nex[i+1] ] * F[d]) % mod;
			x < 0 ? x += mod : 0;
		}
		difa[ nex[i+1] ] = 0;
		x = (x - 1LL * difa[i+1] * F[m-1]) % mod;
		x < 0 ? x += mod : 0;
		x = (97LL * x + 1LL * difa[i+m+1]) % mod;
	}
	
	cout << ans << endl;
	
	return 0;	
}


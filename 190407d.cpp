#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<vector>
#include<map>
#define fi first
#define se second
#define pii pair<int,int>
#define inf 1000000005
#define pb push_back
#define maxn 500005
#define md 1000000007
using namespace std;
typedef long long int ll;
ll T, k;
ll ax, ay, bx, by, dx, dy, cx, cy, cx0, cy0;

ll gcd(ll a, ll b) {
	while (b) {
		a+=b;
		b=a-b;
		a=a-b;
		b%=a;
	}
	return a;
}

void ext_gcd(int a, int b, int &d, int &x, int &y)
{
    if(!b)
    {
        d = a;
        x = 1;
        y = 0;
    }
    else
    {
        ext_gcd(b, a%b, d, y, x);
        y -= x*(a/b);
    }
}

int mod_inverse(int a, int m)
{
    int x, y,d;
    ext_gcd(a, m, d, x, y);
    return (m + x % m) % m;
}

int main(){
	//printf("%lld", gcd(4,6));
	scanf("%lld", &T);
	while (T--) {
	scanf("%lld%lld%lld%lld%lld", &ax, &ay, &bx, &by, &k);
	if (ax > bx) {
		ll tempx = ax;
		ll tempy = ay;
		ax = bx;
		ay = by;
		bx = tempx;
		by = tempy;
	}
	dx = bx - ax;
	dy = by - ay;
	if (dx == 0) {
		while (k--) {
			printf("%lld %lld\n", ax+1, k);
		}
		continue;
	}
	if (dy == 0) {
		while (k--) {
			printf("%lld %lld\n", k, ay+1);
		}
		continue;
	}
	if (dx % dy == 0) {
		ll d1 = dx/ dy;
		while (k--) {
			printf("%lld %lld\n", ax+k*d1+1, ay+k);
		}
		continue;
	}
	if (dy % dx == 0) {
		ll d1 = dy/dx;
		while (k--) {
			printf("%lld %lld\n", ax+k+1, ay+k*d1);
		}
		continue;
	}
	
	ll d = gcd(dx, dy);
	dx /= d;
	dy /= d;
	ll now = 1;
	if (dx > dy) {
	    now = mod_inverse(dy, dx);
    	cx = ax + now;
    	cy = ay + now * dy / dx;
    } else {
        now = mod_inverse(dx, dy);
    	cy = ay + now;
    	cx = ax + now * dx / dy;
    }
	
	cx0 = cx;
	cy0 = cy;
	while(k> 0 && cx <= 1e14 && cy <= 1e14) {
		printf("%lld %lld\n", cx, cy);
		cx += dx;
		cy += dy;
		k--;
	}
	cx = cx0-dx;
	cy = cy0-dy;
	ll cx1 = cx;
	ll cy1 = cy;
	if (k % 2 == 1) {
	    printf("%lld %lld\n", cx, cy);
		cx -= dx;
		cy -= dy;
		k--;
    }
    cx1 += dx;
	cy1 += dy;
	while(k> 0 && cx >= -1e14 && cy >= -1e14) {
		printf("%lld %lld\n", cx, cy);
		cx -= dx;
		cy -= dy;
        printf("%lld %lld\n", cx1, cy1);
		cx1 += dx;
		cy1 += dy;
		k-= 2;
	}
	}
	return 0;
}

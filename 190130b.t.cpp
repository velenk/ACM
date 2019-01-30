#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath> 
#define rep(i,s,t) for(int i = (s); i <= (t); i ++)
#define rep0(i,s,t) for(int i = (s); i < (t); i ++)
#define red(i,s,t) for(int i = (s); i >= (t); i --)
#define repE(i,x) for (int i = first[x];i;i = nxt[i])
#define LL long long
#define N 30005
#define M 1000000007
#define INF 1000000000
#define eps 1e-7
#define D double
using namespace std;

class point {
public:
	D x, y;
	point(D xx=0, D yy=0) {x = xx, y = yy;}
	point(const point& p) {x=p.x, y=p.y;} 
	friend istream& operator>>(istream& is, point &t) {
		is >> t.x >> t.y; 
	}
	friend D dis(point& a, point& b) {
		return sqrt((a.x-b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y));	
	}
	friend point operator+(point& a, point& b) {
		return point(a.x+b.x, a.y+b.y);
	}
	friend point operator-(point& a, point& b) {
		return point(a.x-b.x, a.y-b.y);
	}
	friend point operator*(point& a, D t) {
		return point(a.x*t, a.y*t);
	}
}p[4], A, B;
D v[4], R0, R_sav;

D calc(D d2) {
	D ret = (R_sav - d2) / v[1];
	B = p[3] - p[2]; B = B * (d2/R_sav); B = B + p[2];
//	B = p[2] + (p[3]-p[2]); * (d2 / R_sav);
	return ret + dis(A, B) / v[2];
}

D check(D d1) {
	D ret = d1 / v[0];
	A = p[1]-p[0]; A = A * (d1/R0); A = A + p[0];
//	A = p[0] + (p[1]-p[0]); * (d1 / R0);
	D l = 0, r= R_sav;
	while (fabs(l-r) > eps) 
	{
		D mid = (l+r) / 2., mmd = (mid+r)/2.;
		if (calc(mid) > calc(mmd)) l = mid;
			else r = mmd;
	}
	return ret + calc(l);
}

int main()
{
	//return 0;
	int T; cin >> T;
	while (T --) {
		rep0(i,0,4) cin >> p[i];
		rep0(i,0,3) cin >> v[i];
		D l = 0, r = dis(p[0], p[1]) + eps; R0 = r; R_sav = dis(p[2], p[3]) + eps;
		while (fabs(l-r) > eps) 
		{
			D mid=(l+r)/2., mmd = (mid+r)/2.;
			if (check(mid) > check(mmd)) l = mid;
			else r = mmd;
		}
		printf("%.6f\n", check(l));
	}
}


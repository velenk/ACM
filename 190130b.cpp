#include <iostream>
#include <cstdio>
#include <cmath>
#define rep(i,s,t) for(int i = (s); i < (t); i ++)
#define eps 1e-7

using namespace std;

class Point{
public:
    double x;
    double y;
    Point(double xx=0, double yy=0) {x = xx, y = yy;}
	Point(const Point& p) {x=p.x, y=p.y;} 
    friend double Dis(const Point &a, const Point &b) {
        return sqrt((a.x-b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y));
    }
    friend Point operator+(const Point& a, const Point& b) {
		return Point(a.x+b.x, a.y+b.y);
	}
	friend Point operator-(const Point& a, const Point& b) {
		return Point(a.x-b.x, a.y-b.y);
	}
	friend Point operator*(const Point& a, double t) {
		return Point(a.x*t, a.y*t);
	}
};

Point p[6];
double v[3];
double R0, R1;

double Cal(double y) {
    double ret = y / v[1];
    p[5] = Point(p[3]+(p[2]-p[3])*(y/R1));
    return ret + Dis(p[4], p[5]) / v[2];
}

double Check(double x) {
    double r = R1, l = 0;
    double ret = x / v[0];
    while (fabs(r-l) > eps) {
        double mid1 = (r+l)/2., mid2 = (r+mid1)/2.;
        p[4] = Point(p[0]+(p[1]-p[0])*(x/R0));
        if (Cal(mid1) < Cal(mid2)) {
            r = mid2;
        } else {
            l = mid1;
        }
    }
    return ret + Cal(r);
}

int main(){
    int n0;
    cin >> n0;
    while (n0--) {
        rep(i, 0, 4) {
            cin >> p[i].x >> p[i].y;
        }
        rep(i, 0, 3) {
            cin >> v[i];
        }
        R0 = Dis(p[1], p[0]);
        R1 = Dis(p[3], p[2]);
        double r = R0, l = 0;
        while (fabs(r-l) > eps) {
            double mid1 = (r+l)/2., mid2 = (r+mid1)/2.;
            if (Check(mid1) < Check(mid2)) {
                r = mid2;
            } else {
                l = mid1;
            }
        }
        printf("%.6lf\n", Check(r));
    }
    return 0;
}

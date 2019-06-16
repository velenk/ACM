#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#define eps 1e-8

using namespace std;

struct Point {
    double xx;
    double yy;
    double zz;
};
double Len(Point a);
int Sig(double k);

Point Cross(Point a, Point b) {
    Point s;
    s.xx = a.yy*b.zz - b.yy*a.zz;
    s.yy = a.xx*b.zz - b.xx*a.zz;
    s.zz = a.xx*b.yy - b.xx*a.yy;
    return s;
}

Point Sub(Point a, Point b) {
    Point k;
    k.xx = a.xx - b.xx;
    k.yy = a.yy - b.yy;
    k.zz = a.zz - b.zz;
    return k;
}

double Dis(Point a, Point b) {
    double l = Len(Sub(a, b));
    return sqrt(l);
}

int Check(Point a, Point b, Point c) {
    double d[4];
    d[0] = Dis(a, b);
    d[1] = Dis(a,c);
    d[2] = Dis(b,c);
    sort(d, d+3);
    return fabs(d[0]+d[1]-d[2]) < eps;
}

double Len(Point a) {
    double l;
    l = a.xx*a.xx + a.yy*a.yy + a.zz*a.zz;
    return l;
}

int Sig(double k) {
    if (fabs(k) < eps) return 0;
    if (k < 0) return -1;
    return 1;
}

double Product(Point a, Point b) {
    double x = a.xx*b.xx+a.yy*b.yy+a.zz*b.zz;
    return x;
}

int Check2(Point a, Point b, Point c, Point d) {
    Point n = Cross(Sub(a,b), Sub(a,c));
    Point up = Sub(a,d);
    double x = Product(n, up);
    return fabs(x/sqrt(Len(n))) < eps;
}

double Area(Point a, Point b, Point c) {
    double a0 = Dis(b,c);
    double b0 = Dis(a,c);
    double c0 = Dis(a,b);
    double p = (a0+b0+c0)/2.0;
    return sqrt(p*(p-a0)*(p-b0)*(p-c0));
}

int main() {
    Point a, b, c, d, o;
    while (scanf("%lf", &a.xx) != EOF) 
    {
        
        cin >> a.yy >> a.zz >> b.xx >> b.yy >> b.zz >> c.xx >> c.yy >> c.zz >> d.xx >> d.yy >> d.zz;
        double s1, s2, s3, s4;
        s1 = sqrt(Len(Cross(Sub(a,b), Sub(a,c))))/2.0;
        s2 = sqrt(Len(Cross(Sub(a,d), Sub(a,c))))/2.0;
        s3 = sqrt(Len(Cross(Sub(a,b), Sub(a,d))))/2.0;
        s4 = sqrt(Len(Cross(Sub(d,b), Sub(d,c))))/2.0;
        //s1 = Area(a,b,c);
        //s2 = Area(a,c,d);
        //s3 = Area(a,b,d);
        //s4 = Area(b,c,d);
        //cout << s1 << endl << s2 << endl << s3 << endl << s4 << endl;
        if (Check(a,b,c) ||Check(a,b,d) || Check(a, c ,d)||Check(b,c,d)) {
            printf("O O O O\n");
        } else {
            
        double l1 = Len(Sub(a,b));
        double l2 = Len(Sub(a,c));
        double l3 = Len(Sub(a,d));
        double l4 = Len(Sub(c,d));
        double l5 = Len(Sub(b,d));
        double l6 = Len(Sub(b,c));
            double v = sqrt(l1*l4*(l2+l3+l5+l6-l1-l4) + l2*l5*(l1+l3-l5+l6-l2+l4) + l3*l6*(l2-l3+l5-l6+l1+l4)
                    - l1*l2*l6 - l1*l3*l5 - l2*l4*l3 - l4*l5*l6)/4.0;
            
            double sum = s1+s2+s3+s4;
            o.xx = (s4*a.xx + s2*b.xx + s3*c.xx + s1*d.xx)/sum;
            o.yy = (s4*a.yy + s2*b.yy + s3*c.yy + s1*d.yy)/sum;
            o.zz = (s4*a.zz + s2*b.zz + s3*c.zz + s1*d.zz)/sum;
        
        double r = v/(s1+s2+s3+s4);
        //cout << r << endl;
        if (Check2(a, b, c, d)) {
                printf("O O O O\n");
        } else {
        printf("%.4lf %.4lf %.4lf %.4lf\n", o.xx, o.yy, o.zz, r);
        }
    }
    }
    return 0;
}

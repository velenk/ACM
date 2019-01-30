#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

double x01, x02, x03, x04, y01, y02, y03, y04;
double v1, v2, v3;

double Time(double x001, double y001, double x002, double y002) {
    double t1 = sqrt((x001-x01)*(x001-x01) + (y001-y01)*(y001-y01)) / v1;
    double t2 = sqrt((x001-x002)*(x001-x002) + (y001-y002)*(y001-y002)) / v3;
    double t3 = sqrt((x002-x04)*(x002-x04) + (y002-y04)*(y002-y04)) / v2;
    return t1 + t2 + t3;
}

double mini(double a, double b) {
    return a<b?a:b;
}

int main(){
    int n0;
    cin >> n0;
    while (n0--) {
        cin >> x01 >> y01 >> x02 >> y02 >> x03 >> y03 >> x04 >> y04;
        cin >> v1 >> v2 >> v3;
        double s01 = 0, s02 = 1, s03 = 0, s04 = 1;
        double r = 1, l = 0;
        double dx1 = x02 - x01;
        double dy1 = y02 - y01;
        double dx2 = x03 - x04;
        double dy2 = y03 - y04;
        double temp1, temp2;
        double min0 = 1e8;
        while (r-l>1e-9) {
            r = (s02-s01) * 0.7 + s01;
            l = (s02-s01) * 0.3 + s01;
            temp1 = Time(x01+l*dx1, y01+l*dy1, x04+l*dx2, y04+l*dy2);
            temp2 = Time(x01+r*dx1, y01+r*dy1, x04+l*dx2, y04+l*dy2);
            if (temp1 < temp2) {
                s02 = r;
                min0 = mini(min0, temp1);
            } else {
                s01 = l;
                min0 = mini(min0, temp2);
            }
        }
        r = 1, l = 0;
        while (r-l>1e-9) {
            r = (s04-s03) * 0.7 + s03;
            l = (s04-s03) * 0.3 + s03;
            temp1 = Time(x01+l*dx1, y01+l*dy1, x04+l*dx2, y04+l*dy2);
            temp2 = Time(x01+l*dx1, y01+l*dy1, x04+r*dx2, y04+r*dy2);
            if (temp1 < temp2) {
                s04 = r;
                min0 = mini(min0, temp1);
            } else {
                s03 = l;
                min0 = mini(min0, temp2);
            }
        }
        printf("%.6lf\n", min0);
    }
    return 0;
}

#include <cstdio>
#include <iostream>
#include <cmath>
#define eps 1e-8
#define pi 3.1415926535897932384626

using namespace std;

double r[1000010];
double d[1000010];
int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &r[i]);
    }
    d[1] = 0;
    for (int i = 2; i <= n; i++) {
        scanf("%lf", &d[i]);
    }
    
    double ans = 1;
    double sum = 0;
    for (int i = 1; i < n; i++) {
        //printf("ans %lf\n", ans);
        if (ans < eps) {
            break;
        }
        double r1 = r[i];
        double r2 = r[i+1];
        double d0 = d[i+1]-d[i];
        double x, x1, theta;
        if (r1 <= r2) {
            x = d0*d0 - (r1-r2)*(r1-r2);
            x1 = (sqrt(x) - sqrt(x - 4.0*r1*r2)) /2.0;
            theta = atan(x1/r1);
            ans *= theta/pi;
            sum += ans;
        } else {
            x = d0*d0 - (r1-r2)*(r1-r2);
            x1 = (sqrt(x) - sqrt(x - 4.0*r1*r2)) /2.0;
            theta = atan(x1/r1);
            ans *= theta/pi;
            sum += ans;
        }
        //printf("x %lf\nx1 %lf\ntheta %lf\n", x, x1, theta);
    }
    printf("%.8lf", sum);
    return 0;
}

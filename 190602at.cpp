#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double  dp[2010][20];

double Min(double a, double b) {
    double m = a;
    if (a > b) {
        m = b;
    }
    return m;
}

int main() {
    int  k, w;
    
    for (int j = 0; j <=18; j++) {
        dp[0][j] = 0;
        for (int i = 1; i<=2000; i++) {
            dp[i][j] = 1e8;
        }
    }
    for (int i = 1; i<=2000; i++) {
        for (int j = 1; j <=18; j++) {
            for (int x = 1; x<=i; x++) {
                dp[i][j] = Min(dp[i][j], 1.+dp[x-1][j-1]*x/(i+1.)+dp[i-x][j]*(i-x+1.)/(i+1.));
            }
        }
    }
    while (cin >> k >> w) {
        if (w > 15) w = 15;
        printf("%.6lf\n", dp[k][w]);
    }
    return 0;
}

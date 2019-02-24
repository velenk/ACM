#include <iostream>
#include <cmath>

using namespace std;

double sum1, sum2;

double Maxi(double a, double b, double c) {
    if (a > b) {
        double temp = a;
        a = b;
        b = temp;
    }
    if (b > c) {
        double temp = c;
        c = b;
        b = temp;
    }
    if (a > b) {
        double temp = a;
        a = b;
        b = temp;
    }
    return c;
}

double Mini(double a, double b, double c) {
    if (a > b) {
        double temp = a;
        a = b;
        b = temp;
    }
    if (b > c) {
        double temp = c;
        c = b;
        b = temp;
    }
    if (a > b) {
        double temp = a;
        a = b;
        b = temp;
    }
    return a;
}

double Mid(double a, double b, double c) {
    if (a > b) {
        double temp = a;
        a = b;
        b = temp;
    }
    if (b > c) {
        double temp = c;
        c = b;
        b = temp;
    }
    if (a > b) {
        double temp = a;
        a = b;
        b = temp;
    }
    return b;
}

double Smid(double a, double b, double c) {
    if (a > b) {
        double temp = a;
        a = b;
        b = temp;
    }
    if (b > c) {
        double temp = c;
        c = b;
        b = temp;
    }
    if (a > b) {
        double temp = a;
        a = b;
        b = temp;
    }
    if (c-b == 0) return 0;
    return (c-b)/(c-a)/4.;
}

void Cal(double a, double b, double c, double h) {
    double smid = Smid(a, b, c);
    double maxi = Maxi(a, b, c);
    double mid = Mid(a,b,c);
    double mini = Mini(a,b,c);
    if (h >= maxi) {
        sum1 += .25 * (h-mid) - smid * (maxi-mid) /3. + (.25-smid) * (mid-mini) / 3.;
    } else if (h <= mini) {
        sum1 += .25 * (mid-h) + smid * (maxi-mid) /3. - (.25-smid) * (mid-mini) / 3.;
    } else {
        if (h >= mid) {
            
        } else {
            
        }
    }
    return;
}

int main(){
    int n, m;
    double h;
    while (cin >> n) {
        cin >> m;
        cin >> h;
        sum1 = sum2 = 0;
        double corner[n+1][m+1];
        double center[n][m];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                cin >> corner[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> center[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                Cal(center[i][j], corner[i][j], corner[i+1][j], h);
                Cal(center[i][j], corner[i][j+1], corner[i+1][j], h);
                Cal(center[i][j], corner[i+1][j], corner[i+1][j+1], h);
                Cal(center[i][j], corner[i][j+1], corner[i+1][j+1], h);
            }
        }
        printf("%.3lf %.3lf\n", sum1, sum2);
    }
    return 0;
}

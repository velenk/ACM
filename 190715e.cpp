#include <cstdio>
#include <iostream>
#include <cmath>


#define eps 1e-10
#define MAXN 20
#define LL long long

using namespace std;

double a[100][100];
double b[100];
double x[5], y[5], u[5], v[5];

bool gaussTpivot(int n) {
    int i, j, k, row, col, index[MAXN];
    double maxp, t;
    for (i = 0; i < n; i++) {
        index[i] = i;
    }
    for (k = 0; k < n; k++) {
        for (maxp = 0, i = k; i < n; i++) {
            for (j = k; j < n; j ++) {
                if (fabs(a[i][j]) > fabs(maxp)) {
                    maxp = a[row = i][col = j];
                }
            }
        }
        if (fabs(maxp) < eps) {
            return false;
        }
        if (col != k) {
            for (i = 0; i < n; i++) {
                swap(a[i][col], a[i][k]);
            }
            swap(index[col], index[k]);
        }
        if (row != k) {
            for (j = k; j < n; j++) {
                swap(a[k][j], a[row][j]);
            }
            swap(b[k], b[row]);
        }
        for (j = k+1; j < n; j++) {
            a[k][j] /= maxp;
            for (i = k+1; i < n; i++) {
                a[i][j] -= a[i][k] * a[k][j];
            }
        }
        b[k] /= maxp;
        for (i = k+1; i < n; i++) {
            b[i] -= b[k] * a[i][k];
        }
    }
    for (i = n-1; i >= 0; i--) {
        for (j = i+1; j < n; j++) {
            b[i] -= a[i][j] * b[j];
        }
    }
    for (k = 0; k < n; k++) {
        a[0][ index[k] ] = b[k];
    }
    for (k = 0; k < n; k++) {
        b[k] = a[0][k];
    }
    return true;
}

int pos[MAXN];
int Solve(int n, int m) {
    int r = 0;
    for (int c = 0, i, j, k; c <= m && r <n; ++c) {
        for (i = k = r; i <n; ++i) {
            if (fabs(a[i][c])>fabs(a[k][c])) k =i;
        }
        if (k!=r)for (j = c; j<=m; ++j) swap(a[k][j],a[r][j]);
        if (fabs(a[r][c]) < eps) continue;
        pos[r] = c;
        for (i = r+1;i<n;++i) {
            double t = -a[i][c]/a[r][c];
            for (int j = c; j <= m; ++j) a[i][j] += t*a[r][j];
        }
        ++r;
    }
    if (r>0 && pos[r-1] == m) return -1;
    for (int i = 0; i <m; ++i) b[i] = 0;
    for (int i = r-1; i >= 0; --i) {
        int c = pos[i];
        b[c] = a[i][m]/a[i][c];
        for (int j = 0; j<i; ++j) a[j][m] -=a[j][c]*b[c];
    }
    return r;
}

void Check() {
    for (int i = 0; i <= 19; i++) {
        for (int j = 0; j <= 19; j++) {
            printf("%.1lf ", a[i][j]);
        }
        printf("%.1lf \n", b[i]);
    }
    printf("-------------\n");
    return;
}

int main() {
    while (scanf("%lf%lf%lf%lf", &x[0], &y[0], &u[0], &v[0]) != EOF){
    for (int i = 1; i < 4; i++) {
        scanf("%lf%lf%lf%lf", &x[i], &y[i], &u[i], &v[i]);
    }
    scanf("%lf%lf", &x[4], &y[4]);
    for (int i = 0; i <= 30; i++) {
        for (int j = 0; j <= 30; j++) {
            a[i][j] = 0;
        }
        b[i] = 0;
    }
    
    for (int i = 0; i < 4; i++) {
        a[i][12] = x[i];
        a[i][13] = y[i];
        a[i][14] = 1.0;
        a[i][ 3*i ] = -1.0;
    }
    
    for (int j = 4; j < 8; j++) {
        int i = j - 4;
        a[j][15] = x[i];
        a[j][16] = y[i];
        a[j][17] = 1.0;
        a[j][ 3*i+1 ] = -1.0;
    }
    
    for (int j = 8; j < 12; j++) {
        int i = j - 8;
        a[j][18] = x[i];
        a[j][19] = y[i];
        a[j][ 3*i+2 ] = -1.0;
        a[j][20] = -1.0;
    }
    
    for (int j = 12; j < 16; j++) {
        int i = j - 12;
        a[j][ 3*i ] = -1.0;
        a[j][3*i+2] = u[i];
    }
    
    for (int j = 16; j < 20; j++) {
        int i = j - 16;
        a[j][ 3*i+1 ] = -1.0;
        a[j][3*i+2] = v[i];
    }
    
    //Check();
    
    int flag = Solve(20, 20);
    //printf("---%d\n", flag);
    
    //Check();
    
    double w0 = b[18] * x[4] + b[19] * y[4] + 1.0;
    double u0 = b[12] * x[4] + b[13] * y[4] + b[14];
    double v0 = b[15] * x[4] + b[16] * y[4] + b[17];
    
    printf("%.8lf %.8lf\n", u0/w0, v0/w0);
    }
    
    return 0;
}

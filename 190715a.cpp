#include <cstdio>
#include <iostream>
#include <cmath>

#define LL long long 

using namespace std;

LL n, flag, ran;

LL k;

int a[100][100];
int b[100][100];
int c[100][100];
int d[100][100];
int e[100][100];

void Cal(){
    for (int i = 1;i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            c[i][j] = 0;
            for (int i0 = 1; i0 <= k; i0++) {
                c[i][j] += a[i][i0] * b[i0][j];
            }
            d[i][j] = c[i][j];
        }
    }
    for (int i = 1;i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 1;i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int k0 = 1; k0 < 5; k0++){
        for (int i = 1;i <= k; i++) {
            for (int j = 1; j <= k; j++) {
                e[i][j] = 0;
                for (int i0 = 1; i0 <= k; i0++) {
                    e[i][j] += d[i][i0] * c[i0][j];
                }
            }
        }
        for (int i = 1;i <= k; i++) {
            for (int j = 1; j <= k; j++) {
                d[i][j] = e[i][j];
            }
        }
        for (int i = 1;i <= k; i++) {
            for (int j = 1; j <= k; j++) {
                printf("%d ", d[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return;
}

void Print(LL ran) {
    for (LL i = 1; i <= ran; i++) {
        for (LL j = 1; j <= ran; j++) {
            if (j == ran) {
                printf("-1");
            } else if (j == i+1) {
                printf("1 ");
            } else if (j == 1 && i == ran) {
                printf("1 ");
            }else {
                printf("0 ");
            }
        }
        printf("\n");
    }
    return ;
}

int main() {
    
    k = 4;
    a[1][1] = 0;a[1][2] = 1;a[1][3] = 0;a[1][4] = -1;
    a[2][1] = 0;a[2][2] = 0;a[2][3] = 1;a[2][4] = -1;
    a[3][1] = 0;a[3][2] = 0;a[3][3] = 0;a[3][4] = -1;
    a[4][1] = 1;a[4][2] = 0;a[4][3] = 0;a[4][4] = -1;
    
    b[1][1] = 1;b[1][2] = 0;b[1][3] = 0;b[1][4] = 0;
    b[2][1] = 0;b[2][2] = 1;b[2][3] = 0;b[2][4] = 0;
    b[3][1] = 0;b[3][2] = 0;b[3][3] = 1;b[3][4] = 0;
    b[4][1] = 0;b[4][2] = 0;b[4][3] = 0;b[4][4] = 1;
    
    //Cal();
    
    
    flag = 1;
    scanf("%lld", &n);
    for (LL i = 2; i <= sqrt(n); i++) {
        if (n%i==0) {
            flag = 0;
            ran = i-1;
            break;
        }
    }
    if (flag) {
        ran = n-1;
    }
    printf("%lld\n", ran);
    Print(ran);
    
    return 0;
}

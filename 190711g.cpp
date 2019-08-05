#include <cstdio>
#include <iostream>

#define MAXN 1000010
#define LL long long

using namespace std;

LL n, x, y, t;
LL xa[1010];
LL xb[1010];
LL ya[1010];
LL yb[1010];
int cntx, cnty;

int Max(int a, int b) {
    return a<b?b:a;
}

int main() {
    scanf("%lld", &t);
    while (t--) {
        int flag, res;
        cntx = cnty = 0;
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lld %lld", &x, &y);
            if (x>y) {
                LL temp = x;
                x = y;
                y = temp;
            }
            int j;
            for (j = 1; j <= cntx; j++) {
                if (xa[j] == x) {
                    xb[j] = (xb[j] + 1) %2;
                }
            }
            if (j > cntx) {
                xa[j] = x;
                xb[j]++;
                cntx++;
                res = Max(res, x+1);
            }
            for (j = 1; j <= cnty; j++) {
                if (ya[j] == y) {
                    yb[j] = (yb[j] + 1) %2;
                }
            }
            if (j > cnty) {
                ya[j] = y;
                yb[j]++;
                cnty++;
                res = Max(res, y+1);
            }
        }
        if (n%3==0) {
            flag = 1;
        } else {
            flag = 0;
        }
        
        if (flag) {
            printf("0\n");
        } else {
            printf("%d\n", res);
        }
    }
    return 0;
}

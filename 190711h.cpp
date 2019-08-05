#include <cstdio>
#include <iostream>

#define MAXN 1000010
#define LL long long

using namespace std;

int a[500][500];
int b[500];//student n now choose
int c[500];//course can held
int num[500];
int n, m, t;

void CheckB() {
    printf("---------check B\n");
    for (int i = 1; i <= n; i++) {
        printf("%d now:%d course:%d\n",i ,  b[i], a[i][ b[i] ]);
    }
    return;
}

int Check(int mid) {
    if (mid == n) return 1;
    int cnt = 0;
    int maxi = 0;
    int maxc = 0;
    for (int i = 1; i <= n; i++) {
        b[i] = 1;
    }
    
    for (int i = 1; i <= m; i++) {
        c[i] = 1;
    }
    
    while (cnt < m-1) {
        maxi = 0;
        for (int i = 1; i <= m; i++) {
            num[i] = 0;
        }
        //printf("check %d\n", mid);
        for (int i = 1; i <= n; i++) {
            num[ a[i][ b[i] ] ]++;
            int temp = num[ a[i][ b[i] ] ];
            if (temp > maxi) {
                maxi = temp;
                maxc = a[i][ b[i] ];
            }
        }
        if (maxi <= mid) {
            //printf("-------check %d true\n", mid);
            return 1;
        }
        //printf("delete %d\n", maxc);
        c[maxc] = 0;
        for (int i = 1; i <= n; i++) {
            while (c[ a[i][ b[i] ] ] == 0) {
                b[i]++;
            }
        }
        //CheckB();//comment
        cnt++;
    }
    //printf("-------check %d false\n", mid);
    return 0;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        
        if (n == 1) {
            printf("1\n");
            continue;
        }
        if (m == 1) {
            printf("%d\n", n);
            continue;
        }
        
        //printf("Input successfully\n");
        int l, r, mid;
        l = 1, r = n;
        while(l < r) {
            mid = (l+r)/2;
            int flag = Check(mid);
            if (!flag) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        printf("%d\n", l);
    }
    return 0;
}

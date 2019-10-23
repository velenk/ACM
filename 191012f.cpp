#include <stdio.h>

int l, cnt;
int a[50];
bool b[10000][50];

void Print() {
    for (int i=1; i<=l; i++) {
        b[cnt][i] = a[i];
    }
    cnt++;
    return;
}

int isGood(int k) {
    int sig = 1;
    for (int i=2; i<k; i++) {
        int flag = 1;
        for (int j=i+1; j*2-i <= k && flag; j++) {
            int flag0 = 0;
            for (int i0 = 0; i+i0 <= j; i0++) {
                if (a[i+i0] != a[j+i0]) {
                    flag0 = 1;
                    break;
                }
            }
            flag = flag*flag0;
        }
        if (flag == 1) {
            sig++;
        }
        if (sig*2 < i) {
            return 0;
        }
    }
    return 1;
}

void Solve(int k){
    if (k == l+1) {
        Print();
    } else if (k&1) {
        a[k] = 0;
        if (isGood(k)) {
            Solve(k+1);
        }
        a[k] = 1;
        if (isGood(k)) {
            Solve(k+1);
        }
    } else {
        a[k] = !a[k/2];
        if (isGood(k)) {
            Solve(k+1);
        }
    }
    return;
}

int main() {
    cnt = 0;
    scanf("%d", &l);
    Solve(1);
    printf("%d\n", cnt);
    for (int i=0; i<cnt; i++) {
        for (int j=1; j<=l; j++) {
            printf("%d", b[i][j]);
        }
        printf("\n");
    }
    return 0;
}

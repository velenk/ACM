#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int a[100010][5];
int n;

int main() {
    int t = 1;
    while (t--){
    
    
    
    int flag = 1;
    scanf("%d", &n);
    for (int j = 1; j <= 3; j++)
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i][j]);
    }
    
    for (int i = 1; i <= n; i++) {
        if (a[i][2] % 3 != 2) {
            flag = 0;
            //printf("--5\n");
            break;
        }
        int temp1 = a[i][1] - a[i][2];
        int temp2 = a[i][2] - a[i][3];
        
        if (temp1 ==temp2 && (temp1 == 1 || temp1 == -1) ) {
            if (temp1 == 1) {
                a[i][4] = 1;
            } else {
                a[i][4] = 0;
            }
            //printf("%d:%d\n", i, a[i][4]);
        } else {
            flag = 0;
            //printf("--6\n");
            break;
        }
        a[i][0] = (a[i][1] + 2)/3;
        
        if ( (a[i][0] - i) %2 != 0 ) {
            flag = 0;
            //printf("--7\n");
            break;
        }
    }
    
    if (!flag) {
        printf("No\n");
        continue;
    }
    
    int now = 1;
    while (now<=n-2) {
        //printf("%d\n", now);
        for (int i = now; i <= n-2; i++) {
            if (a[i][0] > a[i+2][0]) {
                int tem = a[i][0];
                a[i][0] = a[i+2][0];
                a[i+2][0] = tem;
                tem = a[i][4];
                a[i][4] = !a[i+2][4];
                a[i+1][4] = !a[i+1][4];
                a[i+2][4] = !tem;
                
            }
            while (a[now][0] == now) now++;
        }
    }
    
    //for (int i = 1; i <= n; i++) {
    //    printf("%d %d\n", a[i][0], a[i][4]);
    //}
    //printf("\n");
    
    for (int i = 1; i <= n-3; i++) {
        if (a[i][4] != 0) {
            a[i+1][4] = !a[i+1][4];
            a[i+2][4] = !a[i+2][4];
            a[i+3][4] = !a[i+3][4];
            a[i][4] = 0;
        }
    }
    
    if (a[n-2][4] != 0 || a[n-1][4] != 0 || a[n][4] != 0) {
        flag = 0;
        //printf("--1\n");
    }
    
    if (flag) {
        if (a[1][0] == 1 && a[1][4] != 0) {
            if (a[2][4] == 0 && a[2][0] == 2) {
                flag = 0;
                break;
            }
        }
        if (a[n][0] == n && a[n][4] != 0) {
            if (a[n-1][4] == 0 && a[n-1][0] == n-1) {
                flag = 0;
            }
        }
    }
    
    
    
    if (flag) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    
    
    
    }
}

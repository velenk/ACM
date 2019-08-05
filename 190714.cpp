#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int a[100010][5];
int b[100010];
int n;

int main() {
    int t = 99;
    while (t--){
    
    
    
    int flag = 1;
    int sum1 = 0;
    int sum2 = 0;
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
                sum1++;
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
        } else {
            int tem = (a[i][0] - i)/2;
            if (tem > 0) {
                sum2 += tem%4;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        int tem = (a[i][0] - i)/2;
        b[i] = a[i][4];//reverse, 0 is right
        if (tem%2 != 0) {
            b[i] = !b[i];
        }
    }
    
    for (int i = 1; i <= n-3; i++) {
        if (b[i] != 0) {
            b[i+1] = !b[i+1];
            b[i+2] = !b[i+2];
            b[i+3] = !b[i+3];
            b[i] = 0;
        }
    }
    
    if (b[n-2] != 0 || b[n-1] != 0 || b[n] != 0) {
        flag = 0;
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

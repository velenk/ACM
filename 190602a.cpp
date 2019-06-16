#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int F(int w, int x) {
    int temp = x;
    int sum = 0;
    if (w < 0) {
        return 0;
    }
    if (w == 0) {
        return 1;
    }
    for (int i = 0; i < x; i++) {
        sum += F(w-1, temp);
        temp--;
    }
    return sum;
}

int main() {
    int k, w;
    cin >> k >> w;
    int check;
    //printf("%d", F(1,3));
    if (w == 1) {
        
    } else {
        int sum0 = 0;
        for (int i = 0; i <= k; i++) {
            int cnt = 0;
            int right = k;
            int left = 0;
            while (right - left != 0) {
                if (cnt < w-1) {
                    check = (right+left+1)/2;
                } else {
                    check = left+1;
                }
                if (check <= i) {
                    left = check;
                } else {
                    right = check-1;
                }
                cnt++;
            }
            printf("%d ",cnt);
            sum0 += cnt;
        }
        printf("%.6lf\n", (double)sum0/(double)(k+1));
    } /*else {
        int x0 = 0;
        for (int i = 0; i < 1000; i++) {
            if (F(w, i) > k) {
                x0 = i;
                break;
            }
        }
        int sum0 = 0;
        for (int i = 0; i <= k; i++) {
            int nowx = x0;
            int noww = w-1;
            int cnt = 0;
            int right = k;
            int left = 0;
            check = F(noww, nowx);
            while (right - left != 0) {
                
                if (check <= i) {
                    nowx--;
                    left = check;
                    check += F(noww, nowx);
                    check = min(check, k);
                } else {
                    noww--;
                    right = check-1;
                    check = check - F(noww+1, nowx)+ F(noww, nowx);
                }
                cnt++;
            }
            printf("%d ",cnt);
            sum0 += cnt;
        }
        printf("%.6lf\n", (double)sum0/(double)(k+1));
    }*/
    return 0;
}

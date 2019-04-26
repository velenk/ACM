#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <iomanip>
#define MAXN 1e5;
#define INF 1e8;
#define eds 1e-6;

using namespace std;

char a[20000];
int i;

int main() {
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", a);
        getchar();
        if (n%4 == 1 || n%4 == 2) {
            printf("-1\n");
            continue;
        }
        if (n%4 == 0) {
            for (i = 0; i < n/2; i++) {
                if (i%2 == 1) {
                    if (a[i] == '1') {
                        printf("3");
                    } else {
                        printf("1");
                    }
                } else {
                    if (a[i] == '1') {
                        printf("4");
                    } else {
                        printf("2");
                    }
                }
            }
            for (; i < n; i++) {
                if (i%2 == 0) {
                    if (a[i] == '1') {
                        printf("3");
                    } else {
                        printf("1");
                    }
                } else {
                    if (a[i] == '1') {
                        printf("4");
                    } else {
                        printf("2");
                    }
                }
            }
        }
        if (n%4 == 3) {
            if (a[0] == '1') {
                printf("3");
            } else {
                printf("1");
            }
            if (a[1] == '1') {
                printf("3");
            } else {
                printf("1");
            }
            if (a[2] == '1') {
                printf("4");
            } else {
                printf("2");
            }
            for (i = 3; i < n/2+2; i++) {
                if (i%2 == 1) {
                    if (a[i] == '1') {
                        printf("3");
                    } else {
                        printf("1");
                    }
                } else {
                    if (a[i] == '1') {
                        printf("4");
                    } else {
                        printf("2");
                    }
                }
            }
            for (; i < n; i++) {
                if (i%2 == 0) {
                    if (a[i] == '1') {
                        printf("3");
                    } else {
                        printf("1");
                    }
                } else {
                    if (a[i] == '1') {
                        printf("4");
                    } else {
                        printf("2");
                    }
                }
            }
        }
        printf("\n");
    }
    return 0;
}

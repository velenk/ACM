#include <iostream>
#include <stdio.h>

using namespace std;

int a[200000];
int b[200000];

int main() {
    int T,n;
    scanf("%d", &T);
    
    while (T--) {
        scanf("%d", &n);
        int ans = 0;
        int c = 0, d = 0, s = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }
        for (int i = 0; i < n; i++) {
            
            if (b[i] == 2 && a[i]%2 == 1) {
                s = 1;
            }
            if (b[i] == 2 && a[i] > 0) {
                d++;
            }
            if (b[i] == 1 && a[i] > 1) {
                c++;
            }
        }
        if (s || c+d > 1)  {
            printf("Bob\n");
        } else {
            if (d == 1) {
                for (int i = 0; i < n; i++) {
                    if (b[i] != 2) {
                        ans ^= a[i];
                    }
                }
                if (ans != 0) printf("Bob\n");
                else printf("Alice\n");
            } else if (c == 1) {
                for (int i = 0; i < n; i++) {
                    if (b[i] == 1 && a[i] > 1) {
                        if (a[i] % 2 == 0) {
                            ans ^= 1;
                        }
                    } else {
                        ans^= a[i];
                    }
                }
                if (ans != 0) printf("Bob\n");
                else printf("Alice\n");
            } else {
                for (int i = 0; i < n; i++) {
                    ans ^= a[i];
                }
                if (ans != 0) printf("Alice\n");
                else printf("Bob\n");
            }
        }
    }
    return 0;
}

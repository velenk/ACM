#include <cstdio>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

class Node{
public:
    int power;
    int index;
    int choose;
};

int n;
Node p[6000];
Node f[6000];

int minp, minf, maxp;

int cmp (Node a, Node b) {
    return a.power<b.power;
}

int cmp1 (Node a, Node b) {
    return a.choose<b.choose;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i].power);
        p[i].index = i;
        p[i].choose = 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &f[i].power);
        f[i].index = i;
        f[i].choose = 0;
    }
    
    sort(p, p+n, cmp);
    sort(f, f+n, cmp);
    
    minf = 0;
    minp = 0;
    maxp = n-1;
    
    for (int i = 0; i < n; i++) {
        if (f[minf].power > p[minp].power) {
            f[minf].choose = p[minp].index;
            minp++;
        } else {
            f[minf].choose = p[maxp].index;
            maxp--;
        }
        minf++;
    }
    
    sort(f, f+n, cmp1);
    
    for (int i = 0; i < n-1; i++) {
        printf("%d ", f[i].power);
    }
    printf("%d\n", f[n-1].power);
    
    return 0;
}




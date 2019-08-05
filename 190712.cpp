#include <cstdio>
#include <algorithm>

using namespace std;

int cmp (int a, int b) {
    return a<b;
}

int n, p, k;
int a[1000000];

int main() {
    scanf("%d%d%d", &n, &p, &k);
    for (int i =1; i<=n;i++) {
        scanf("%d", &a[i]);
    }
    sort(a+1, a+n+1, cmp);
    
    return 0;
}

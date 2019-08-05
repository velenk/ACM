#include <cstdio>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <queue>

using namespace std;

int n;
int A;
queue<int> Q;

int a[20];
int maxid;
int s[1000000];
int mod = -1;

void Print(int k, int dep);

void Solve() {
    if (A==mod) {
        printf("1\n1 %d",maxid);
        return;
    }
    s[0] = -1;
    Q.push(0);
    while (!Q.empty()) {
        int h = Q.front();
        Q.pop();
        for (int i = 1; i <=n; i++) {
            if (s[ (h+a[i])%mod ] == 0) {
                s[ (h+a[i])%mod ] = i;
                Q.push((h+a[i])%mod);
            }
        }
    }
    if (s[A] == 0) {
        printf("-1");
        return;
    }
    Print(A, 0);
    return;
}

void Print(int k, int dep) {
    if (s[k]==-1) {
        printf("%d\n", dep);
        return;
    }
    if (a[ s[k] ] <= k) {
        Print(k-a[ s[k] ], dep+2);
        printf("1 %d\n3 %d %d\n",s[k],s[k],maxid);
    } else {
        Print(k-a[ s[k] ]+mod, dep+4);
        printf("1 %d\n3 %d %d\n2 %d\n3 %d %d\n",s[k],s[k],maxid,maxid,s[k],maxid);
    }
    return;
}

int main() {
    scanf("%d%d",&n,&A);
    for (int i = 1; i <=n; i++) {
        scanf("%d",&a[i]);
        if (mod<a[i]) {
            mod = a[i];
            maxid = i;
        }
    }
    
    Solve();
    
    return 0;
}



#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAX = 5000;
const int maxnum = 10010;
bool V[MAX];

int n, A[MAX], s;
int B[MAX], T[maxnum];
int solve() {
    int ans = 0;

    for (int i = 0; i < n; i++)
        T[B[i]] = i;
    for (int i = 0; i < n; i++) {
        if (V[i])
            continue;

        int cur = i;
        int S = 0, m = maxnum, an = 0;
        while (!V[cur]) {
            V[cur] = true;
            an++;
            int v = A[cur];
            m = min(m, v);
            S += v;
            cur = T[v];
        }
        ans += min(S + (an - 2) * m, m + S + (an + 1) * s);
    }
    return ans;

}
int main() {
    while (scanf("%d", &n)) {
    s = maxnum;
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        s = min(s, A[i]);
        B[i] = A[i];
        V[i] = false;
    }
    sort(B, B + n);
    printf("%d\n", solve());
    }
    return 0;
}

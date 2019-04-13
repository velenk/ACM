#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <iomanip>

using namespace std;

long long num[200000];
long long n, k, A, B;

inline long long count(int a, int l) {
    long long i = 0;
    while(i <= n && num[i] < a) {
        i++;
    }
    int j = i;
    while(j <= n && num[j] <= a+l-1) {
        j++;
    }
    return j - i;
}

long long solve(int a, int l) {
    long long cnt = upper_bound(num, num + k, a + l -1) - lower_bound(num, num + k, a);
    if (cnt == 0) return A;
    if (l == 1) {
        return B * cnt;
    }
    return min(cnt * B * l, solve(a, l/2) + solve(a+l/2, l/2));
}

int main() {
    scanf("%lld%lld%lld%lld", &n, &k, &A, &B);
    for (int i = 0; i < k; i++) {
        scanf("%lld", &num[i]);
    }
    sort(num, num + k);
    num[k] = 2<<n;
    long long ans = solve(1, 1<<n);
    printf("%lld", ans);
    return 0;
}

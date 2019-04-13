#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <iomanip>

using namespace std;

long long num[200000];

int IfDelete(char ch) {
    if (ch == 'a'|| ch == 'e'|| ch == 'i'|| ch == 'o'|| ch == 'u') {
        return 1;
    }
    return 0;
}

int main() {
    long long n, k, m;
    long long ans = 0;
    scanf("%lld%lld%lld", &n, &k, &m);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &num[i]);
        ans += num[i];
    }
    sort(num, num+n);
    int t = min(m, n-1);
    long double max = (long double)(ans + (long long)min(m, k * n))/(long double)n;
    for (int i = 0; i < t; i++) {
        ans -= num[i];
        long double now = (long double)(ans + (long long)min(m-i-1, k * (n-i-1)))/(long double)(n-i-1);
        if (now > max) {
            max = now;
        }
    }
    cout << setprecision(8) << fixed << max;
    return 0;
}

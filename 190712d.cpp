#include <cstdio>
#include <cmath>
#define LL long long

LL n, sqrtn , temp;
LL ans, i, delta;
LL now, begin, mid;

int main() {
    scanf("%lld", &n);
    ans = 0;
    sqrtn = (LL)sqrt(n);
    i = sqrtn;
    delta = (n - i*i)/2;
    if (delta%2!=0) i--;
    for (; i >= 0; i = i-2) {
        delta = (n - i*i)/2;
        now = (LL)sqrt(delta) + 1;
        //printf("now %lld i %lld\n", now, i);
        begin = now - i;
        if (begin < 0) begin = 0;
        while (begin < now) {
            mid = (begin + now) / 2;
            //printf("mid %lld\n", mid);
            temp = mid * (mid + i);
            if (temp == delta) {
                //printf("%lld %lld %lld\n",i, mid, mid+sqrtn);
                ans++;
                break;
            } else if (temp > delta) {
                now = mid;
            } else {
                begin = mid+1;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}

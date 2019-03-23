#include <iostream>
#include <cstdlib>
#include <cmath>
typedef long long int ll;
using namespace std;


short C[1<<21];
short R[1<<21];
int N;
short color[3][3] = {{0, 0, 4}, {0, 0, 4}, {4, 4, 4}};
ll sum;

void changeR(ll k) {
    ll now = (1<<N) - 1 + k;
    if (R[now] == 0) {
        R[now] = 1;
    } else {
        R[now] = 0;
    }
    now /= 2;
    while (now) {
        int k1 = R[now*2];
        int k2 = R[now*2+1];
        int k0 = R[now];
        if (k1 == k2 && k1 == 0) {
            R[now] = 0;
        } else if (k1 == k2 && k1 == 1) {
            R[now] = 1;
        } else {
            R[now] = 2;
        }
        if (R[now] != k0) {
            ll change = 1;
            while (change <= now) {
                change <<= 1;
            }
            change >>= 1;
            for (ll i = change; i < change<<1; ++i) {
                sum = sum + color[C[i]][R[now]] - color[C[i]][k0];
            }
        }
        now /= 2;
    }
}

void changeC(ll k) {
    ll now = (1<<N) - 1 + k;
    if (C[now] == 0) {
        C[now] = 1;
    } else {
        C[now] = 0;
    }
    now /= 2;
    while (now) {
        int k1 = C[now*2];
        int k2 = C[now*2+1];
        int k0 = C[now];
        if (k1 == k2 && k1 == 0) {
            C[now] = 0;
        } else if (k1 == k2 && k1 == 1) {
            C[now] = 1;
        } else {
            C[now] = 2;
        }
        if (C[now] != k0) {
            ll change = 1;
            while (change <= now) {
                change <<= 1;
            }
            change >>= 1;
            for (ll i = change; i < change<<1; ++i) {
                sum = sum + color[R[i]][C[now]] - color[R[i]][k0];
            }
        }
        now /= 2;
    }
}

int main() {
    sum = 1;
    cin >> N;
    int n0;
    cin >> n0;
    ll k;
    while (n0--) {
        cin >> k;
        if (k == 0) {
            cin >> k;
            changeR(k);
        } else {
            cin >> k;
            changeC(k);
        }
        cout << sum << endl;
    }
    return 0;
}

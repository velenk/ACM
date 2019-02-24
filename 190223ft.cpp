#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int sum = 0;
        double p[n+2] = { };
        int temp;
        double p1, p2;
        for (int i = 1; i <= n; ++i) {
            cin >> temp;
            p[temp] = i;
        }
        p[n+1] = n+1;
        for (int i = n; i > 1; --i) {
            int tempsum = 0;
            for(int j = 1; j < i; ++j) {
                if (p[j] > p[i]) {
                    tempsum += j;
                }
            }
            if (tempsum < i) {
                for(int j = i; j > 0; --j) {
                    if (p[j] > p[i]) {
                        p1 = p[j+1];
                        p2 = 0;
                        for (int k = 1; k <= j; ++k) {
                            if (p2 < p[k] && p[k] < p[j+1]) {
                                p2 = p[k];
                            }
                        }
                        p[j] = (p1 + p2) / 2.;
                        sum += j;
                    }
                }
            } else {
                p1 = p[i+1];
                p2 = 0;
                for (int j = 1; j <= i; ++j) {
                    if (p2 < p[j] && p[j] < p[i+1]) {
                        p2 = p[j];
                    }
                }
                p[i] = (p1 + p2) / 2.;
                sum += i;
            }
        }
        cout << sum << endl;
    }
    return 0;
}

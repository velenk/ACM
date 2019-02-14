#include <iostream>

using namespace std;

long long GCD(long long a, long long b) {
    long long c;
    while (b != 0) {
        a = a%b;
        c = b;
        b = a;
        a = c;
    }
    return a;
}

void Extend_GCD(long long a, long long b, long long& x, long long &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return;
    }
    Extend_GCD(b, a % b, x, y);
    long long tmp = x;
    x = y;
    y = tmp - a / b * y;
    return;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        long long a, b, c;
        long long x, y;
        cin >> a >> b >> c;
        long long x0 = GCD(a, b);
        if (c%x0 == 0) {
            Extend_GCD(a/x0, b/x0, x, y);
            cout << x*c/x0 << " " << y*c/x0 << endl;
        } else {
            cout << "impossible!\n";
        }
    }
    return 0;
}

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
    long long a, b, c;
    cin >> a >> b;
    if (a%2 == 1 && b%2 == 1) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
    }
    return 0;
}

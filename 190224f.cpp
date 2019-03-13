#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long C(int n, int k) {
    if (k > n/2) {
        k = n-k;
    }
    long long temp = 1;
    for (int i = 1; i <= k; ++i) {
        temp = temp * (n+1-i) /i;
    }
    return temp;
}

int main() {
    int n0;
    cin >> n0;
    for (int j = 1; j <= n0; ++j) {
        int n;
        cin >> n;
        vector<int> number;
        number.clear();
        long long temp;
        for (int i = 0; i < n; ++i) {
            cin >> temp;
            number.push_back(temp);
        }
        sort(number.begin(), number.end());
        int i1 = 0, i2 = n-1;
        int flag;
        long long sum = 0;
        if (n%2 == 0) {
            for (int i = n/2-1; i >= 0; --i) {
                sum += (number[i2] - number[i1]) * C(n-1, i);
                i2--;
                i1++;
            }
        } else {
            if (n/2%2 == 1) {
                flag = -1;
                sum += flag * number[i1] * C(n-1, n/2);
                i1++;
            } else {
                flag = 1;
                sum += flag * number[i2] * C(n-1, n/2);
                i2--;
            }
            
            flag *= -1;
            
            for (int i = n/2-1; i >= 0; --i) {
                if (flag == 1) {
                    sum += (number[i2] + number[i2-1]) * C(n-1, i);
                    i2 -= 2;
                } else {
                    sum += flag * (number[i1] + number[i1+1]) * C(n-1, i);
                    i1 += 2;
                }
                flag *= -1;
            }
        }
        cout << "Case #" << j << ": " << sum << endl;
    }
    return 0;
}

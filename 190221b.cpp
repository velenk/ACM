#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> S = {"Wei", "Shu", "Wu", "Qun"};

int main() {
    int n;
    while (cin >> n) {
        int a[4] = { };
        int count = 0;
        for (int i = 0; i < n; ++i) {
            string temp;
            cin >> temp;
            if (temp == S[0]) {
                a[0]++;
            } else if (temp == S[1]) {
                a[1]++;
            } else if (temp == S[2]) {
                a[2]++;
            } else if (temp == S[3]) {
                a[3]++;
            }
        }
        int n0 = n/2;
        for (int j = 0; j < 4; ++j) {
            if (a[j] > n0) {
                count += a[j] - n0 + 1;
            } else if (a[j] > 0){
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}

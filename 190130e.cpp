#include <bits/stdc++.h>

using namespace std;


int main(){
    int left, right;
    while (1) {
        cin >> left >> right;
        if (left == 0 && right == 0) {
            break;
        }
        int count = 0;
        for (int i = left; i < right+1; ++i) {
            int n[10] = { };
            int temp = i;
            int flag = 1;
            while (temp > 0) {
                int k = temp % 10;
                if (n[k] == 1) {
                    flag = 0;
                }
                n[k] = 1;
                temp /= 10;
            }
            if (flag) {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}

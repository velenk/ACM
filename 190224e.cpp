#include <iostream>

using namespace std;

int main() {
    int n0;
    cin >> n0;
    for  (int j = 1; j <= n0; ++j) {
        int n;
        cin >> n;
        int a[n] = { };
        int s[n] = { };
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            s[0]-=a[i];
        }
        s[0]+=  a[0];
        //cout << s[0] << " ";
        for (int i = 1; i < n; ++i) {
            s[i] = s[i-1] + a[i] + a[i-1];
            //cout << s[i] << " ";
        }
        int win = 0;
        int lose = 0;
        int flag = 0;
        for (int i = 1; i < n-1; ++i) {
            if (s[i] >= 0) {
                lose = 0;
            }
            if (s[i] < 0) {
                lose++;
            }
            if (lose > (n-2)/2) {
                flag = -1;
                break;
            }
        }
        for (int i = 1; i < n-1; ++i) {
            if (s[i] > 0) {
                win++;
            }
            if (s[i] <= 0) {
                win = 0;
            }
            if (win > (n-3)/2) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            cout << "Case #"<<j<<": win"<<endl;
        } else if (flag == -1) {
            cout << "Case #"<<j<<": lose"<<endl;
        } else {
            cout << "Case #"<<j<<": tie"<<endl;
        }
    }
    return 0;
}

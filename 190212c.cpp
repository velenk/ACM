#include <iostream>
#include <string>

using namespace std;

int a[103][103];//1 or 0
int b[103];//color
int c[103];//count
int d[103];//dominant
int e[103];//end color
int l[103];//lenth
int B;

int main() {
    int n;
    cin >> n;
    while (n--) {
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        string s;
        cin >> s;
        l[i] = s.length();
        
        for (int j = 0; j < l[i]; ++j) {
            if (s[j] == 'B') {
                a[i][j] = 1;
            } else {
                a[i][j] = 0;
            }
        }
        
        if (s[0] == 'B') {
            b[i] = 1;
        } else {
            b[i] = 0;
        }
        
        if (s[l[i]-1] == 'B') {
            e[i] = 1;
        } else {
            e[i] = 0;
        }
        
        int cnt = 0;
        while (s[cnt] == s[0]) {
            cnt++;
            if (cnt == l[i]) {
                break;
            }
        }
        c[i] = cnt;
        
        d[i] = 0;
        for (int j = cnt; j < l[i]; ++j) {
            if (s[j] == 'B') {
                d[i]++;
            } else {
                d[i]--;
            }
        }
    }
    
    B = 0;
    for (int i = 0; i < k; ++i) {
        if (b[i] == 1) {
            B += c[i];
            if (d[i] < 0) {
                B--;
            }
        } else {
            B -= c[i];
            if (d[i] > 0) {
                B++;
            }
        }
    }
    
    if (B>0) {
        cout << "Naive!\n";
    } else if (B==0) {
        cout << "Alice!\n";
    } else {
        cout << "T_T\n";
    }
    }
    return 0;
}

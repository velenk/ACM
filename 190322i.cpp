#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    char s[40] = { };
    char ch = 0;
    scanf("%s", s);
    int l = strlen(s);
    int x = 0, y = 0;
    for (int i = 0; i < l; ++i) {
        x <<= 1;
        y <<= 1;
        ch = s[i];
        int num = ch - '0';
        switch (num) {
            case 0: break;
            case 1: x += 1;break;
            case 2: y += 1;break;
            case 3: x += 1;y += 1;break;
        }
    }
    cout << l << " " << x << " " << y << endl;
    return 0;
}

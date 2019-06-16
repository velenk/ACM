#include <iostream>
#include <cstdio>

using namespace std;

char s[300][300];

void initial(int n, int m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            s[i][j] = '(';
        }
    }
}

void Print(int n, int m) {
    for (int i = 1; i <= n; i++) {
        int j;
        for (j = 1; j < m; j++) {
            cout << s[i][j] ;
        }
        cout << s[i][j] << endl;
    }
}

int main() {
    int T, n, m;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        initial(n, m);
        if (n%2 == 1 && m%2 ==1) {
            Print(n, m);
        } else if (n%2 ==1 && m%2 == 0) {
            for (int i = 1; i <= n; i++) {
                for (int j = m/2+1; j <= m; j++) {
                    s[i][j] = ')';
                }
            }
            Print(n, m);
        } else if (n%2 == 0 && m%2 == 1) {
            for (int i = n/2+1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    s[i][j] = ')';
                }
            }
            Print(n, m);
        } else if (n < 6 || m < 6) {
            if (n < m) {
                for (int i = 2; i < n; i++) {
                    if (i%2 == 0) {
                        for (int j = m/2+1; j <= m; j++) {
                            s[i][j] = ')';
                        }
                    } else {
                        for (int j = 1; j <= m/2; j++) {
                            s[i][j] = ')';
                        }
                    }
                }
                for (int j = 1; j <= m; j++) {
                    s[n][j] = ')';
                }
            } else {
                for (int i = 2; i < m; i++) {
                    if (i%2 == 0) {
                        for (int j = n/2+1; j <= n; j++) {
                            s[j][i] = ')';
                        }
                    } else {
                        for (int j = 1; j <= n/2; j++) {
                            s[j][i] = ')';
                        }
                    }
                }
                for (int j = 1; j <= n; j++) {
                    s[j][m] = ')';
                }
            }
            Print(n, m);
        } else {
            for (int i = 2; i < n; i++) {
                for (int j = 2; j < m; j++) {
                    if ((i+j)%2 == 0) {
                        s[i][j] = '(';
                    } else {
                        s[i][j] = ')';
                    }
                }
                for (int i = 2; i <= n; i++) {
                    s[i][m] = ')';
                }
                for (int i = 2; i <= m; i++) {
                    s[n][i] = ')';
                }
            }
            for (int j = 1; j <= m; j++) {
                s[n][j] = ')';
            }
            Print(n, m);
        }
    }
    return 0;
}

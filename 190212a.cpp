#include <map>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

map<vector<int>,int> M;
map<vector<int>,int> M1;
queue<vector<int>> Q;

void BFS(vector<int> vector0) {
    int i, j;
    vector<int> vector1(vector0);
    for (i = 0; i < 5; ++i) {
        for (j = i; j < 5; ++j) {
            int k;
            vector1.clear();
            for (k = 0; k < i; ++k) {
                vector1.push_back(vector0[k]);
            }
            for (k = j; k >= i; --k) {
                vector1.push_back(-vector0[k]);
            }
            for (k = j+1; k < 5; ++k) {
                vector1.push_back(vector0[k]);
            }
            if (i == 0 && j == 4) {
                M[vector1] = min(M[vector0], M[vector1]);
            } else {
                M[vector1] = min(M[vector0] + 1, M[vector1]);
            }
            if (M1[vector1] == 0) {
                M1[vector1] = 1;
                Q.push(vector1);
            }
        }
    }
    return;
}

void Initial() {
    for (int a = -5; a < 6; ++a)
    for (int b = -5; b < 6; ++b)
    for (int c = -5; c < 6; ++c)
    for (int d = -5; d < 6; ++d)
    for (int e = -5; e < 6; ++e) {
        M[{a,b,c,d,e}] = 1e5;
    }
    
    return;
}

int main() {
    Initial();
    vector<int> vector0 = {1,2,3,4,5};
    M[vector0] = 0;
    M1[vector0] = 1;
    Q.push(vector0);
    while (!Q.empty()) {
        BFS(Q.front());
        Q.pop();
    }
    int n;
    cin >> n;
    vector<int> vector3 = { };
    while (n--) {
        int k0;
        cin >> k0;
        vector3.clear();
        for (int i = 0; i < 5; ++i) {
            cin >> k0;
            vector3.push_back(k0);
        }
        cout << M[vector3] << endl;
    }
    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ball;
int A, B;
int k;

void Move() {
    int score = 0;
    int n1, n2;
    cin >> n1;
    int a[n1];
    int flag2 = 0;//hit target ball
    int max1 = 0;//largest number in first hit
    for (int i = 0; i < n1; i++) {
        cin >> a[i];
        if (max1 < a[i]) {
            max1 = a[i];
        }
        if (a[i] == ball[0]) {
            flag2 = 1;
        }
    }
    cin >> n2;
    int b[n2];
    int flag1 = 0;//cue ball in pocket;
    int flag4 = 0;//target ball in pocket;
    for (int i = 0; i < n2; i++) {
        cin >> b[i];
        if (b[i] == 0) {
            flag1 = 1;
        }
        if (b[i] == ball[0]) {
            flag4 = 1;
        }
    }
    int flag3 = 0;//foul
    if (n1 == 0) {
        score += ball[0];
        flag3 = 1;
    } else if (flag1) {
        score += max1;
        flag3 = 1;
    } else if (!flag2 || n1 > 1) {
        score += max1;
        flag3 = 1;
    }
    if (!flag4 || flag3) {
        k *= -1;
    }
        if (n2 > 0) {
            for (int i = 0; i < n2; ++i) {
                score += b[i];
            }
        }
    
    
    for (int i = 0; i < n2; ++i) {
        if (b[i] == 0) continue;
        ball.erase(find(ball.begin(),--(ball.end()),b[i]));
    }
    if (k == 1) {
        A += score;
    } else {
        B += score;
    }
    return;
}

int main() {
    int n, m;
    while(cin >> n) {
    A = B = 0;
    ball.clear();
    cin >> m;
    for (int i = 0; i < n; ++i) {
        int temp = 0;
        cin >> temp;
        ball.push_back(temp);
    }
    sort(ball.begin(), ball.end());
    k = 1;
    while (m--) {
        Move();
        sort(ball.begin(), ball.end());
        cout << A << " : " << B << endl;
    }
    cout << A << " : " << B << endl;
    }
    return 0;
}

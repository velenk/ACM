#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string.h>

using namespace std;

class Node {
public:
    int n;
    int x;
    int y;
};

Node p[6010];

int res[6010], con[6010], num1[6010], num2[6010], iso[6010], get[6010];

int n,m,now;

int cmp (Node a, Node b) {
    return a.x < b.x;
}

int cmpres (int a, int b) {
    return a<b;
}

int Check(int i, int j) {
    if (p[i].x == p[j].x) {
        if (p[i].y/2 == p[j].y/2) {
            return 1;
        }
    }
    if (p[i].x == p[j].x+1 || p[i].x == p[j].x-1) {
        if ((p[i].y+1)/2 == (p[j].y+1)/2) {
            return 1;
        }
    }
    return 0;
}

void Connect(int i, int j) {
    int i0 = i, j0 = j;
    if (num1[i] + num2[i] < num1[j] + num2[j]) {
        i0 = j;
        j0 = i;
    }
    num1[i0] += num1[j0];
    num2[i0] += num2[j0];
    con[j0] = i0;
    return;
}

int Find(int i) {
    int t = con[i];
    while (t != i) {
        i = t;
        t = con[i];
    }
    return t;
}

int main(){
    memset(iso, 0, sizeof iso);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &p[i].x, &p[i].y);
        p[i].n = i;
    }
    
    sort(p+1, p+n+1, cmp);
    
    for (int i = 1; i <= n; i++) {
        con[i] = i;
        num1[i] = num2[i] = 0;
        if (p[i].y % 2 == 1) {
            num1[i]++;
        } else {
            num2[i]++;
        }
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = i+1; j <= n; j++) {
            if (Check(i, j)) {
                Connect(Find(i), Find(j));
                iso[i] = iso[j] = 1;
            }
        }
    }
    
    //for (int i = 1; i <= n; i++) {
    //    printf("%d %d %d %d %d\n", p[i].n, iso[i], Find(i), num1[i], num2[i]);
    //}
    
    now = 1;
    
    for (int i = 1; i <= n; i++) {
        if (iso[i] == 0) {
            res[now] = p[i].n;
            now++;
            //printf("---%d get %d\n", i, p[i].n);
        } else {
            int t = Find(i);
            if ((num1[t] > num2[t]) ^ (p[i].y%2 == 0)) {
                res[now] = p[i].n;
                now++;
                //printf("---%d get %d\n", i, p[i].n);
            }
        }
    }
    
    if (now > m) {
        sort(res+1, res+m+1,cmpres);
        for (int i = 1; i <= m; i++) {
            printf("%d\n", res[i]);
        }
    } else {
        printf("-1\n");
    }
    
    return 0;
}

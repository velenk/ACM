#include <cstdio>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

int r, s, p;
int time[500100];

int x,y;
int temp;
int now;

int cmp (int a, int b) {
    return a<b;
}

int main() {
    scanf("%d%d%d", &r, &s, &p);
    for (int i = 0; i < p; i++) {
        scanf("%d%d", &x, &y);
        temp = 0;
        if (y <= s) {
            temp += s-y+1;
        } else {
            temp += y-s;
        }
        temp += r-x+1;
        time[i]=temp;
    }
    
    
    sort(time, time+p, cmp);
    now = 0;
    
    for (int i = 0; i < p; i++) {
        if (time[i]>now) {
            now = time[i];
        } else {
            now++;
        }
    }
    
    printf("%d\n", now);
    
    return 0;
}




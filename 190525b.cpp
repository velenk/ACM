#include <iostream>
#include <string.h>

using namespace std;

int sg[1<<20], visit[30];

void Solve(int sta) {
    memset(visit, 0, sizeof(visit));
    for (int i = 19; i >= 0; i--) {
        if (sta & 1<<i) {
            for (int j = i-1; j >= 0; j--) {
                if (sta & 1<<j) continue;
                int step = sta ^ (1<<i) ^ (1<<j);
                visit[sg[step]] = 1;
            }
        }
    }
    for (int i = 0; i < 21; i++) {
        if (visit[i] == 0) {
            sg[sta] = i;
            break;
        }
    }
}


int main() {
    for(int i = 0 ; i < (1<<20) ; i ++)
        Solve(i);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d",&n);
        int ans = 0;
        for(int i = 0 ; i < n ; i ++)
        {
            int step,sta;
            sta = 0;
            scanf("%d",&m);
            for(int j = 0 ; j < m ; j ++)
            {
                scanf("%d",&step);
                sta |= (1<<(20 - step));
            }
            ans ^= sg[sta];
        }
        if(ans == 0)printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}

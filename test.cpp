#include <cstdio>

int n, m;

int main() {
    int T=30;
    scanf("%d%d", &n, &m);
    while(T--){
        m+=2;
    //scanf("%d%d", &n, &m);
    int cnt = 0;
    //printf("  \t");
    for (int j=0; j<n; j++) {
        //printf("%d ",j^(n-1-j));
    }
    //printf("\n");
    for (int i = 0; i<m; i++) {
        //printf("%d\t",i^(m-1-i));
        for (int j=0; j<n; j++) {
            if ((i^(m-1-i)^j^(n-1-j)) == 0) {
                //printf("0 ");
                cnt++;
            } else {
                //printf("1 ");
            }
        }
        //printf("\n");
    }
    printf("%d %d\n", cnt/4, m);
    }
    return 0;
}

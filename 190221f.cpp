#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
#define Maxi 3005

int dp[Maxi*3],last[Maxi*3],save[Maxi],first[Maxi],n;

int main()
{
    while(cin >> n)
    {
        first[0]=0;
        for(int i=1;i<=n;i++)
        {
            cin >> save[i];
            if(save[i]>=1&&save[i]<=n)
                first[i]=first[i-1]+1;
            else
                first[i]=first[i-1];
        }
        memset(dp,0,sizeof(dp));
        memset(last,0,sizeof(last));
        int Max=0,ans=0;
        for(int i=n;i>=1;i--)
        {
            for(int c=1-save[i];c<=n-save[i];c++)
                Max=max(Max,++dp[c+n]);
            for(int c=1-n;c<=2*n;c++)
            {
               ans=max(ans,first[i-1]+dp[c+n]);
               ans=max(ans,first[i-1]+dp[c+n]+last[c+n]);
            }
            for(int c=1-n;c<=2*n;c++)
                last[c+n]=max(last[c+n],Max-dp[c+n]);
        }
        cout << ans << endl;
    }
    return 0;
}

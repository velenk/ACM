#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#define maxn 60
#define maxm 100005
#define inf 2000000000
#define lowbit(x) (x&-x)
using namespace std;
typedef double db;
typedef long long int ll;
ll m;
ll p[10000][55];
int main()
{
	scanf("%lld",&m);
	if(m==1)
	{
		printf("3 1\n");
		return 0;
	}
	for(int i=1;i<=10000;i++)p[i][1]=i;
	for(int a=3;a<=55;a++)
	{
		ll sum=0;
		ll n=1;
		while(1)
		{
			if(p[n][a-1]>(m-sum)/n)break;
			sum+=(p[n][a]=p[n][a-1]*n);
			if(sum>=m)
			{
				if(sum==m)
				{
					printf("%d %d\n",a+1,n);
					return 0;
				}
				else break;
			}
			n++;
		}
		cout<<sum<<endl;
		
	}
	puts("impossible");
	return 0;
}


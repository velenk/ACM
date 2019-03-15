#include <iostream>
#include <cmath>
typedef unsigned long long int  ll;

using namespace std;

int a,b,c;
ll d()
{
 	if(a!=b&&b!=c&&a!=c)return (ll)6;
 	if(a==b&&a==c&&b==c)return (ll)1;
 	return (ll)3;
}

int main() {
    ll n;
    cin >> a >> b >> c;
    cin >> n;
    ll sum = 0;
    for (int i = (n+1)/2; i < n; ++i) {
        int l = n-i;
        int mini = n-2*l;
        int maxi = l-1;
        mini = max(mini, 1);
        sum += max(0, maxi - mini + 1);
    }
    sum *= n;
    if (n%3 == 0) {
        sum += n/3;
    }
    cout << sum * d();
    return 0;
}

#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    ll k,n,m;
    while (scanf("%lld%lld%lld",&k,&n,&m)!=EOF) {
        double ans=0;
        for (ll x=1;x<=n;x++) {
            for (ll y=1;y<=m;y++) {
                ans+=pow(1-(2*x*x-(2*n+2)*x+1)*(2*y*y-(2*m+2)*y+1)/(double)(n*n*m*m),(double)k);
            }
        }
        double o=n*m-ans;
        printf("%.0f\n",o);
    }
    return 0;
}

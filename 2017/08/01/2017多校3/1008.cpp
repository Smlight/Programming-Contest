#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MO=1e9+7;

ll fpow(ll x,ll n)
{
    ll res=1;
    while (n) {
        if (n&1) {
            res=res*x%MO;
        }
        x=x*x%MO;
        n>>=1;
    }
    return res;
}

int main()
{
    ll n,k;
    int cas=0;
    while (scanf("%lld%lld",&n,&k)!=EOF) {
        printf("Case #%d: %lld\n",++cas,fpow(n%MO,k%(MO-1)));
    }
    return 0;
}

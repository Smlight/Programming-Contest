#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MO=1e9+7;

ll fpow(ll x,int n)
{
    ll res=1;
    while (n) {
        if (n&1) {
            res=res*x%MO;
        }
        n>>=1;
        x=x*x%MO;
    }
    return res;
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int t=1;t<=T;t++) {
        ll n,m,k,ans=0;
        scanf("%I64d%I64d%I64d",&n,&m,&k);
        for (int i=1;i<k;i++) {
            ans=(ans+fpow(i,n+m-2))%MO;
        }
        ans=ans*fpow(k,(n-1)*(m-1))%MO;
        ans=ans*n%MO*m%MO;
        ans=(ans+fpow(k,n*m))%MO;
        if (n==1&&m==1) {
            ans=(ans+1)%MO;
        }
        printf("Case #%d: %I64d\n",t,ans);
    }
    return 0;
}

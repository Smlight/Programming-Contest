#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MO=998244353;

ll inv(int x)
{
    if (x==1) return 1;
    return (MO-MO/x)*inv(MO%x)%MO;
}

int main()
{
    ll n,m;
    while (scanf("%lld%lld",&n,&m)!=EOF) {
        if (m>n||(n+m)&1) {
            puts("0");
            continue;
        }
        ll ans=n%MO;
        if (m==0) {
            ans=ans*inv(n)%MO;
        } else {
            for (int i=n-m+2;i<=n+m-2;i+=2) {
                ans=ans*i%MO;
            }
        }
        for (int i=m;i>0;i--) {
            ans=ans*inv(i)%MO;
        }
        if (((n-m)/2)&1) {
            ans=MO-ans;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MO=1e9+7;
ll po[64],pomo[128];

int main()
{
    po[0]=pomo[0]=1;
    for (int i=1;i<64;i++) {
        po[i]=po[i-1]*2;
    }
    for (int i=1;i<128;i++) {
        pomo[i]=pomo[i-1]*2%MO;
    }
    ll n;
    while (scanf("%lld",&n)!=EOF) {
        if (n==2) {
            puts("1");
            continue;
        }
        int bnd=lower_bound(po,po+64,n)-po-1;
        ll ans=3,cnt=0;
        for (int i=bnd;i>=1;i--) {
            ll now=(n-1)/po[i]-1-cnt;
            ans=ans+now%MO*(pomo[i*2]+1)%MO;
            cnt+=now;
        }
        ans+=(n-3-cnt)%MO*2%MO;
        ans=(ans+MO)%MO;
        printf("%lld\n",ans);
    }
    return 0;
}

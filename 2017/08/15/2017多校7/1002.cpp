#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll sz[70],po[70],xo[70];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        ll n,k,ans=0;
        scanf("%lld%lld",&n,&k);
        if (k==1) {
            ++n;
            for (ll i=2;i<=n*2;i<<=1) {
                ll r=n%i,t;
                if (r==0) {
                    t=n/2;
                } else {
                    t=(n/i)*(i/2);
                    if (r>i/2) {
                        t+=r-i/2;
                    }
                }
                if (t&1) ans^=i/2;
            }
        } else {
            int d=0;
            xo[0]=po[0]=sz[0]=1;
            while (sz[d]<=n) {
                d++;
                if ((double)po[d-1]*k>=n) break;
                po[d]=po[d-1]*k;
                sz[d]=sz[d-1]+po[d];
                if (k&1) {
                    xo[d]=xo[d-1]^sz[d];
                } else {
                    xo[d]=sz[d];
                }
            }
            while (1) {
                ans^=n;
                d--;
                ll r=n-sz[d];
                if ((r/po[d])&1) {
                    ans^=xo[d];
                }
                if (d==0) break;
                if ((k-(r-1)/po[d]-1)&1) {
                    ans^=xo[d-1];
                }
                if (r%po[d]==0) break;
                n=sz[d-1]+r%po[d];
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

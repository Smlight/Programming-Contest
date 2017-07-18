#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=100005,INF=1<<30;
struct Node {
    int a,b,c;
    bool operator <(const Node &r) const {
        return a+b-c<r.a+r.b-r.c;
    }
} p[N];
ll d[N],rd[N];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--) {
        int n,k;
        scanf("%d%d",&n,&k);
        ll sumc=0;
        for (int i=1;i<=n;i++) {
            scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);
            sumc+=p[i].c;
        }
        sort(p+1,p+1+n);
        rd[n+1]=0;
        for (int i=n;i>=1;i--) {
            d[i]=p[i].a+p[i].b-p[i].c;
            rd[i]=rd[i+1]+d[i];
        }
        ll ans=-INF;
        for (int i=1;i<=n;i++) {
            ll now=0;
            int j=upper_bound(d+1,d+1+n,p[i].b)-d;
            int cnt=min(k-1,n-j+1);
            if (n-cnt<i) {
                now+=rd[n-cnt+1];
                cnt--;
            } else {
                now+=rd[n-cnt+1];
                now+=d[i];
            }
            now+=(ll)p[i].b*(k-1-cnt);
            ans=max(ans,now);
        }
        printf("%lld\n",ans+sumc);
    }
    return 0;
}

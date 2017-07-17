#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=100010;
int p[N];
set<int> ss;

int main()
{
    int T,n;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) {
            int x;
            scanf("%d",&x);
            p[x]=i;
        }
        ll ans=0;
        ss.clear();
        for (int i=1;i<=n;i++) {
            if (i>1) {
                int y=n+1,x=0;
                if (p[i-1]<p[i]) {
                    x=p[i-1];
                } else {
                    y=p[i-1];
                }
                auto it=ss.lower_bound(p[i]);
                int l=x,r=y;
                if (it!=ss.end()) {
                    r=*it;
                }
                if (it!=ss.begin()) {
                    l=*(--it);
                }
//                printf("x:%d Y:%d l:%d r:%d\n",x,y,l,r);
                ans+=(ll)(y-p[i])*(p[i]-x)-(ll)(r-p[i])*(p[i]-l);
            }
            ss.insert(p[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

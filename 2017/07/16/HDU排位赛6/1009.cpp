#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=100010;
struct Role {
    int a,b,c,d;
    ll calc(ll x) {
        return x*b+d;
    }
    bool operator >(const Role &r) const {
        return d>r.d;
    }
} r[N];
ll s[N],sta[N];

inline double slope(int j,int k)
{
    return 1.0*(r[k].d-r[j].d)/(r[j].b-r[k].b);
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int n,k;
        ll sum=0;
        scanf("%d%d",&n,&k);
        for (int i=1;i<=n;i++) {
            scanf("%d%d%d",&r[i].a,&r[i].b,&r[i].c);
            r[i].d=r[i].a+r[i].b-r[i].c;
            sum+=r[i].c;
        }
        sort(r+1,r+1+n,greater<Role>());
        for (int i=1;i<=n;i++) {
            s[i]=s[i-1]+r[i].d;
        }
        ll ans=0,mb=-1;
        for (int i=1;i<=min(n,k);i++) {
            mb=max(mb,(ll)r[i].b);
            ans=max(ans,s[i]+(k-i)*mb);
        }
        int top=0;
        for (int i=n;i>=0;i--) {
            if (k>i&&top) {
                ll x=k-i-1;
                while (top>1&&r[sta[top-2]].calc(x)>r[sta[top-1]].calc(x)) top--;
                ans=max(ans,s[i]+r[sta[top-1]].calc(x));
            }
            while (top&&r[sta[top-1]].b<=r[i].b) top--;
            while (top>1&&slope(sta[top-2],sta[top-1])<slope(sta[top-1],i)) top--;
            sta[top++]=i;
        }
        ans+=sum;
        printf("%lld\n",ans);
    }
    return 0;
}

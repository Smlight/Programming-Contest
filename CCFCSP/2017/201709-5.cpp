#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=100010;
int a[N];
ll c[N];

void update(int x,ll d)
{
    for (int i=x;i<N;i+=i&(-i)) {
        c[i]+=d;
    }
}

ll getsum(int x)
{
    ll res=0;
    for (int i=x;i;i-=i&(-i)) {
        res+=c[i];
    }
    return res;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        update(i,a[i]);
    }
    for (int i=1;i<=m;i++) {
        int op,l,r,v;
        scanf("%d%d%d",&op,&l,&r);
        if (op==1) {
            scanf("%d",&v);
            if (v==1) continue;
            for (int i=l;i<=r;i++) {
                if (a[i]>=v&&a[i]%v==0) {
                    update(i,-a[i]+a[i]/v);
                    a[i]/=v;
                }
            }
        } else {
            printf("%lld\n",getsum(r)-getsum(l-1));
        }
    }
    return 0;
}

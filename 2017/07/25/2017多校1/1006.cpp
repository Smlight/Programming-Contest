#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MO=1e9+7;
const int N=1e5+5;
int a[N],b[N],vis[N];
ll ca[N],cb[N];

ll fpow(ll x,ll n)
{
    ll res=1;
    while (n) {
        if (n&1) {
            res*=x;
            res%=MO;
        }
        x*=x;
        x%=MO;
        n>>=1;
    }
    return res;
}

void count_circle(int a[],int n,ll ca[])
{
    memset(vis,0,sizeof(vis));
    for (int i=0;i<n;i++) {
        int x=a[i];
        if (vis[x]) continue;
        int len=0;
        while (!vis[x]) {
            vis[x]=1;
            len++;
            x=a[x];
        }
        ca[len]++;
    }
}

int main()
{
    int n,m,cas=0;
    while (scanf("%d%d",&n,&m)!=EOF) {
        for (int i=0;i<n;i++) {
            scanf("%d",&a[i]);
        }
        for (int i=0;i<m;i++) {
            scanf("%d",&b[i]);
        }
        memset(ca,0,sizeof(ca));
        count_circle(a,n,ca);
        memset(cb,0,sizeof(cb));
        count_circle(b,m,cb);
        ll ans=1;
        for (int i=1;i<=n;i++) {
            ll Y=0;
            for (int j=1;j*j<=i;j++) {
                if (i%j==0) {
                    Y=(Y+j*cb[j]%MO)%MO;
                    if (j*j!=i) {
                        Y=(Y+i/j*cb[i/j]%MO)%MO;
                    }
                }
            }
            ans*=fpow(Y,ca[i]);
            ans%=MO;
        }
        printf("Case #%d: %lld\n",++cas,ans);
    }
    return 0;
}

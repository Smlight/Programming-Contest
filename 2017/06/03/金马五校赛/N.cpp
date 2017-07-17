#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
ll n,p;
ll f[1010][1010],g[1010][1010];

void getspilit(ll n,ll m)
{
    if (m==0) {
        f[n][m]=0;
        g[n][m]=0;
        return;
    }
    if (f[n][m]!=-1) return;
    if (m>n) {
        getspilit(n,n);
        f[n][m]=f[n][n];
        g[n][m]=g[n][n];
    } else if (n==m) {
        getspilit(n,m-1);
        f[n][m]=(f[n][m-1]+1)%p;
        g[n][m]=(g[n][m-1]+m*m%p)%p;
    } else {
        getspilit(n-m,m);
        getspilit(n,m-1);
        f[n][m]=(f[n-m][m]+f[n][m-1])%p;
        g[n][m]=(g[n-m][m]+f[n-m][m]*m%p*m%p)%p;
        g[n][m]=(g[n][m]+g[n][m-1])%p;
    }
//    printf("%lld %lld\n g[n][m]: %lld\n",n,m,g[n][m]);
}

ll fpow(ll x,ll n)
{
    ll res=1;
    while (n) {
        if (n&1) {
            res=res*x%p;
        }
        x=x*x%p;
        n>>=1;
    }
    return res;
}

int main()
{
    while (scanf("%lld%lld",&n,&p)!=EOF) {
        memset(f,-1,sizeof(f));
        f[1][1]=1;g[1][1]=1;
        getspilit(n,n);
        ll ans=f[n][n]*n%p*n%p-g[n][n];
        ans=(ans+p)%p;
        ans=ans*fpow(2,p-2)%p;
        printf("%lld\n",ans);
    }
    return 0;
}

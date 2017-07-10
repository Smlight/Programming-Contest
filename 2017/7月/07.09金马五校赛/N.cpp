#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a[110];

ll extend_gcd(ll a,ll b,ll &x,ll &y)
{
    if(a==0&&b==0) return -1;
    if(b==0) {
        x=1;
        y=0;
        return a;
    }
    ll d=extend_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

ll mod_reverse(ll a,ll n)
{
    ll x,y;
    ll d=extend_gcd(a,n,x,y);
    if(d==1) return (x%n+n)%n;
    else return -1;
}

long long mod_mul(long long a,long long b,long long p) {
    long long r=0;
    long long t=a;
    while(b) {
        if(b&1) r=(r+t)%p;
        t=(t<<1)%p;
        b>>=1;
    }
    return r;
}

ll fpow(ll x,ll n,ll MO)
{
    ll res=1;
    while (n) {
        if (n&1) {
            res=mod_mul(res,x,MO);
        }
        x=mod_mul(x,x,MO);
        n>>=1;
    }
    return res;
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        ll e,p,q,n;
        scanf("%lld%lld%lld%lld",&e,&p,&q,&n);
        for (int i=1;i<=n;i++) {
            scanf("%lld",a+i);
        }
        ll m=p*q,k=(p-1)*(q-1);
        ll d=mod_reverse(e,k);
        for (int i=1;i<=n;i++) {
            a[i]=fpow(a[i]%m,d,m);
            printf("%lld%c",a[i],i==n?'\n':' ');
        }
    }
    return 0;
}

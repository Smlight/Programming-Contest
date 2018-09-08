#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod=1000000007;
const int INV6=166666668;
const int INV2=500000004;
ll a[50];
int tot;

void init(ll n)
{
    tot = 0;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while(n % i == 0) {
                a[tot++] = i;
                n /= i;
            }
        }
    }
    if (n != 1) {
        a[tot++] = n;
    }
}

ll calc(ll n,ll k)
{
    ll tmp=n*(n+1)%mod;
    return ((n+n+1)%mod*tmp%mod*INV6%mod*k%mod+tmp*INV2%mod)*k%mod;
}

ll n,m;
ll ans;

void dfs(int dep,ll lcm,int d)
{
    if (dep>=tot) return;
    ll now=lcm/__gcd(lcm,a[dep])*a[dep];
    if (d&1) {
        ans-=calc(n/now,now);
        if (ans<0) ans+=mod;
    } else {
        ans+=calc(n/now,now);
        if (ans>=mod) ans-=mod;
    }
    dfs(dep+1,lcm,d);
    dfs(dep+1,now,d+1);
}

int main()
{
    while (scanf("%lld%lld",&n,&m)!=EOF) {
        init(m);
        ans=calc(n,1);
        dfs(0,1,1);
        printf("%lld\n",ans);
    }
    return 0;
}

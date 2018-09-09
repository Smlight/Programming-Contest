#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX=10000000;
int tot=0;
int mu[MAX+5];
int prime[MAX/10];
bool check[MAX+5];

void get_mu()
{
    mu[1] = 1;
    for(int i = 2; i <= MAX; i++) {
        if( !check[i] ) {
            prime[tot++] = i;
            mu[i] = -1;
        }
        for(int j = 0; j < tot; j++) {
            if(i * prime[j] > MAX) break;
            check[i * prime[j]] = true;
            if( i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            } else {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
    for (int i=1;i<=MAX;i++) {
        mu[i]+=mu[i-1];
    }
}

unordered_map<ll,ll> mmt;
ll MT(ll n)
{
    if (n<=MAX) return mu[n];
    if (mmt.count(n)) return mmt[n];
    int ans = 0;
    for (ll i = 2, j; i <= n; i = j + 1) {
        j = n / (n / i);
        ans += (j - i + 1) * MT(n / i);
    }
    return mmt[n] = 1 - ans;
}

ll solve(ll m,ll n)
{
    if (m==0) return 0;
    if (n==1) return MT(m);
    vector<ll> ps;
    for (int i=2;1LL*i*i<=n;i++) {
        if (n%i==0) {
            int cnt=0;
            ps.push_back(i);
            while (n%i==0) {
                n/=i;
                if (++cnt>1) return 0;
            }
        }
    }
    if (n>1) ps.push_back(n);
    int sz=ps.size();
    ll ans=0;
    for (int i=0;i<(1<<sz);i++) {
        ll tmp=1;
        int cnt=0;
        for (int j=0;j<sz;j++) {
            if (i>>j&1) {
                tmp*=ps[j];
                ++cnt;
            }
        }
        if (cnt&1) ans-=solve(m/tmp,tmp);
        else ans+=solve(m/tmp,tmp);
    }
    if (sz&1) return -ans;
    return ans;
}

int main()
{
    get_mu();
    ll n,m;
    while (scanf("%lld%lld",&m,&n)!=EOF) {
        printf("%lld\n",solve(m,n));
    }
    return 0;
}

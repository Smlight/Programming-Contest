#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX=100000;
const int MO=1e9+7;
int check[MAX+5],mu[MAX+5];
int prime[40000];
int cnt[MAX*2+5];

void init()
{
    mu[1] = 1;
    int tot = 0;
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
}

ll fpow(ll x,int n)
{
    ll res=1;
    while (n) {
        if (n&1) {
            res=res*x%MO;
        }
        x=x*x%MO;
        n>>=1;
    }
    return res;
}

int main()
{
    init();
    int T,n,cas=0;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        int mn=MO;
        memset(cnt,0,sizeof(cnt));
        for (int i=1;i<=n;i++) {
            int x;
            scanf("%d",&x);
            mn=min(mn,x);
            cnt[x]++;
        }
        for (int i=1;i<=MAX*2;i++) {
            cnt[i]+=cnt[i-1];
        }
        ll ans=0;
        for (int i=2;i<=mn;i++) {
            ll tmp=1;
            for (int j=1;i*j<=MAX;j++) {
                tmp=tmp*fpow(j,cnt[i*j+i-1]-cnt[i*j-1])%MO;
            }
            ans=(ans-mu[i]*tmp+MO)%MO;
        }
        printf("Case #%d: %lld\n",++cas,ans);
    }
    return 0;
}

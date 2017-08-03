#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e6+5;
const int MO=998244353;
ll a[N];
const int MAX=1000010;
int tot=0,prime[100000];
bool isprime[MAX];
int res[N];

void init()
{
    memset(isprime,1,sizeof(isprime));
    isprime[1]=false;
    for(int i=2; i<MAX; i++) {
        if(isprime[i])prime[++tot]=i;
        for(int j=1; j<=tot&&i*prime[j]<MAX; j++) {
            isprime[i*prime[j]]=false;
            if(i%prime[j]==0)break;
        }
    }
}

int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--) {
        ll l,r,k;
        scanf("%lld%lld%lld",&l,&r,&k);
        for (ll i=l;i<=r;i++) {
            a[i-l]=i;
            res[i-l]=1;
        }
        int x=sqrt(r);
        for (int i=1;prime[i]<=x;i++) {
            int p=prime[i];
            for (ll j=((l-1)/p+1)*p;j<=r;j+=p) {
                int kk=0;
                while (a[j-l]%p==0) {
                    kk++;
                    a[j-l]/=p;
                }
                res[j-l]=res[j-l]*(k*kk%MO+1)%MO;
            }
        }
        ll ans=0;
        for (ll i=l;i<=r;i++) {
            if (a[i-l]!=1) res[i-l]=res[i-l]*(k+1)%MO;
            ans=(ans+res[i-l])%MO;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5000000,MO=1000000007;

int cnt,prime[N+10],flag[N+10];
ll phi[N+10];

void Pre(ll n)
{
    flag[1]=1;
    phi[1]=1;
    for (ll i=2;i<=n;i++) {
        if (!flag[i]) prime[++cnt]=i,phi[i]=i-1;
        for (int j=1; j<=cnt && i*prime[j]<=n; j++) {
            flag[i*prime[j]]=1;
            if (!(i%prime[j])) {
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }
            phi[i*prime[j]]=phi[i]*(prime[j]-1);
        }
    }
    for (ll i=1;i<=n;i++) phi[i]=(phi[i]+phi[i-1])%MO;
}

const int MAXN=250000,P=233333;
struct Hash {
    int next;
    ll i,x;
} mp[MAXN];
int head[MAXN],tot;

inline void Add(ll i,ll x)
{
    int pos=i%P;
    mp[++tot].next=head[pos];
    head[pos]=tot;
    mp[tot].i=i;
    mp[tot].x=x;
}

ll Sum(ll x)
{
    if (x<=N) return phi[x];
    else {
        int pos=x%P;
        for (int i=head[pos];i;i=mp[i].next) {
            if (mp[i].i==x) {
                return mp[i].x;
            }
        }
    }
    ll sum=0,s=0;
    for (ll i=2,j;i<=x;i=j+1) {
        j=x/(x/i);
        (sum+=Sum(x/i)%MO*(j-i+1)%MO)%=MO;
    }
    if (x&1) {
        s=(((x+1)/2)%MO)*(x%MO)%MO;
    } else {
        s=((x/2)%MO)*((x+1)%MO)%MO;
    }
    sum=(s-sum+MO)%MO;
    Add(x,sum);
    return sum;
}

int main()
{
    Pre(N);
    int T,n;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        ll ans=0;
        for (int i=1,j;i<=n;i=j+1) {
            j=n/(n/i);
            if (i>n-233||j<233) continue;
            (ans+=(Sum(min(j,n-233))-Sum(max(i,233)-1)+MO)%MO*(n/i)%MO)%=MO;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

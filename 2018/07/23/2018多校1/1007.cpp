#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MO=1000000007;
ll p2[64],S[64];

int solve(ll n)
{
    if (n==0) return 0;
    int k=1;
    while ((1LL<<k)-1<=n) ++k;
    --k;
    return (S[k]+(n+1-(1LL<<k))%MO*p2[k-1]%MO+solve(n+1-(1LL<<k)))%MO;
}

int main()
{
    p2[0]=1;
    for (int i=1;i<=63;i++) {
        p2[i]=p2[i-1]*2%MO;
    }
    S[0]=0;
    for (int i=1;i<=63;i++) {
        S[i]=(S[i-1]*2%MO+p2[i-2]*(p2[i-1]-1)%MO+p2[i-1]%MO)%MO;
        assert(S[i]>=0&&S[i]<MO);
    }
    int T;
    scanf("%d",&T);
    while (T--) {
        ll n;
        scanf("%lld",&n);
        printf("%d\n",(solve(n-1)+1)%MO);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N=1000005;
const int mod=1e9+7;
ll dp[N][3];
int po[N];

int main()
{
    po[0]=1;
    for (int i=1;i<N;i++) {
        po[i]=2LL*po[i-1]%mod;
    }
    int T;
    scanf("%d",&T);
    while (T--) {
        int n,k;
        scanf("%d%d",&n,&k);
        dp[1][0]=0;
        dp[1][1]=po[k];
        dp[1][2]=0;
        for (int i=2;i<=n;i++) {
            dp[i][1]=dp[i-1][1]+dp[i-1][0];
            dp[i][2]=dp[i-1][2]+dp[i-1][0];
            dp[i][0]=(po[k]-2)*dp[i-1][1]%mod+(po[k]-2)*dp[i-1][2]%mod;
            if (po[k]>=3) {
                dp[i][0]+=(po[k]-3)*dp[i-1][0]%mod;
            }
            for (int j=0;j<3;j++) dp[i][j]%=mod;
        }
        printf("%lld\n",(dp[n][0]+dp[n][1])%mod);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MO=1e9+7;
const int N=2010;
ll C[N][N],dp[N][N];

void init()
{
    for (int i=0;i<=2000;i++) {
        C[i][0]=1;
        for (int j=1;j<=i;j++) {
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%MO;
        }
    }
    dp[0][0]=0;
    dp[1][1]=1;
    for (int i=2;i<=2000;i++) {
        for (int j=1;j<=2000;j++) {
            dp[i][j]=(dp[i-1][j]*j%MO+dp[i-1][j-1]*j%MO)%MO;
        }
    }
}

int main()
{
    init();
    int T;
    scanf("%d", &T);
    while(T--) {
        int n,m;
        scanf("%d%d",&n,&m);
        ll ans=0;
        for (int i=1;i<m;i++) {
            for (int j=1;j<=m-i;j++) {
                ans+=C[m][i]*dp[n][i]%MO*C[m-i][j]%MO*dp[n][j]%MO;
                ans%=MO;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

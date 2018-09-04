#include <bits/stdc++.h>
using namespace std;

const int N=20005;
int sum[N];
int dp[N][205];

int main()
{
    int T,n;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) {
            scanf("%d",&sum[i]);
            sum[i]+=sum[i-1];
        }
        int bnd=sqrt(n<<1)+1;
        for (int i=n;i;i--) {
            for (int k=bnd;k;k--) {
                dp[i][k]=0;
                if (i+k-1<=n) dp[i][k]=sum[i+k-1]-sum[i-1]-dp[i+k][k];
                if (i+k<=n) {
                    dp[i][k]=max(dp[i][k],sum[i+k]-sum[i-1]-dp[i+k+1][k+1]);
                }
            }
        }
        printf("%d\n",dp[1][1]);
    }
    return 0;
}

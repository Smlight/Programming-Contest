#include <bits/stdc++.h>
using namespace std;

const int N=1010;
int a[N],sum[N],dp[N][N];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
        dp[i][i]=0;
    }
    for (int len=2;len<=n;len++) {
        for (int i=1;i<=n;i++) {
            int j=i+len-1;
            if (j>n) break;
            dp[i][j]=1<<29;
            for (int k=i;k<j;k++) {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
            dp[i][j]+=sum[j]-sum[i-1];
        }
    }
    if (n==1) printf("%d\n",a[1]);
    else printf("%d\n",dp[1][n]);
    return 0;
}

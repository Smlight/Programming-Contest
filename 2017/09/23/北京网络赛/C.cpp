#include <bits/stdc++.h>
using namespace std;

const int N=310,INF=1<<26;
int a[N][N],dp[N][2],sum[N][2];
int n,m,p;

int DP(int x,int y)
{
    int res=-INF,left=0;
    dp[0][1]=dp[0][0]=-INF;
	for(int i=1;i<=m;i++) {
        if (dp[i-1][0]<0) {
            left=i;
            dp[i][0]=sum[i][0];
        } else {
            dp[i][0]=dp[i-1][0]+sum[i][0];
        }
        dp[i][0]=max(dp[i-1][0]+sum[i][0],sum[i][0]);
        dp[i][1]=max(dp[i-1][1]+sum[i][0],dp[i-1][0]+sum[i][1]);
        dp[i][1]=max(dp[i][1],sum[i][1]);
        if (x==1&&y==n&&i==m&&left==1) {
            res=max(res,dp[i][1]);
        } else {
            res=max(res,max(dp[i][0],dp[i][1]));
        }
    }
    return res;
}

int main()
{
    while (scanf("%d%d%d",&n,&m,&p)!=EOF) {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                scanf("%d",&a[i][j]);
            }
        }
        int ans=-INF;
        for (int i=1;i<=n;i++) {
            for (int k=1;k<=m;k++) {
                sum[k][0]=0;
                sum[k][1]=-INF;
            }
            for (int j=i;j<=n;j++) {
                for (int k=1;k<=m;k++) {
                    sum[k][1]=max(sum[k][1]+a[j][k],sum[k][0]+p);
                    sum[k][0]+=a[j][k];
                }
                ans=max(ans,DP(i,j));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

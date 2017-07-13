#include <bits/stdc++.h>
using namespace std;

int dp[105][5];

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF) {
        memset(dp,0,sizeof(dp));
        for (int i=1;i<=n;i++) {
            int x,y;
            scanf("%d%d",&x,&y);
            dp[x][y]=-1;
        }
        dp[0][0]=1;
        for (int i=1;i<=100;i++) {
            if (dp[i][0]!=-1) {
                dp[i][0]=(dp[i-1][0]==1);
                if (!dp[i][0]) {
                    if (i>=4) {
                        if (dp[i-1][1]!=-1&&dp[i-2][2]!=-1&&dp[i-3][1]!=-1&&dp[i-4][0]==1) {
                            dp[i][0]=1;
                        }
                    }
                }
            }
        }
        printf("%d\n",(dp[100][0]==1));
    }
    return 0;
}

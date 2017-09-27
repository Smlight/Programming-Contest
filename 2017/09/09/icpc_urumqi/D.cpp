#include <bits/stdc++.h>
using namespace std;

const int N=1010,INF=1<<29;
int dp[N][N][2];
struct Classroom {
    int x,t;
    bool operator <(const Classroom &R) const {
        return x<R.x;
    }
} c[N];

inline void updm(int &x,int y)
{
    if (y<x) x=y;
}

int main()
{
    int T,cas=0;
    scanf("%d",&T);
    while (T--) {
        int n,m,b;
        scanf("%d%d%d",&n,&m,&b);
        for (int i=1;i<=n;i++) {
            scanf("%d%d",&c[i].x,&c[i].t);
        }
        sort(c+1,c+n+1);
        dp[1][n][0]=max(c[1].x,c[1].t);
        dp[1][n][1]=max(c[n].x,c[n].t);
        for (int l=n-1;l>=1;l--) {
            for (int i=1;i<=n;i++) {
                int j=i+l-1;
                if (j>n) break;
                dp[i][j][0]=dp[i][j][1]=INF;
                if (i>1) {
                    updm(dp[i][j][0],dp[i-1][j][0]+c[i].x-c[i-1].x);
                    updm(dp[i][j][1],dp[i-1][j][0]+c[j].x-c[i-1].x);
                }
                if (j<n) {
                    updm(dp[i][j][0],dp[i][j+1][1]+c[j+1].x-c[i].x);
                    updm(dp[i][j][1],dp[i][j+1][1]+c[j+1].x-c[j].x);
                }
                if (dp[i][j][0]<c[i].t) dp[i][j][0]=c[i].t;
                if (dp[i][j][1]<c[j].t) dp[i][j][1]=c[j].t;
            }
        }
        int ans=INF;
        for (int i=1;i<=n;i++) {
            updm(ans,min(dp[i][i][0],dp[i][i][1])+abs(b-c[i].x));
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}

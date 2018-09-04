#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
int d[30][30],sb[30][30];
PII pre[30][30];
double dp[30][30];
vector<PII> ans;

void print(int i,int j)
{
    if (i==1&&j==1) {
    } else {
        print(pre[i][j].first,pre[i][j].second);
    }
    ans.push_back(PII(i,j));
}

int main()
{
    double a,b;
    scanf("%lf%lf",&a,&b);
    scanf("\n");
    string s;
    int n=0,m;
    while (getline(cin,s)) {
        stringstream ss(s);
        n++;
        m=0;
        int x;
        while (ss>>x) {
            sb[n][++m]=x;
        }
    }
    swap(n,m);
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            d[i][j]=sb[j][i];
        }
    }
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=m;j++) {
            dp[i][j]=1e60;
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (i==1&&j==1) {
                dp[i][j]=d[1][1];
            } else {
                dp[i][j]=dp[i-1][j-1]+b*d[i][j];
                pre[i][j]=PII(i-1,j-1);
                if (i>1&&dp[i-2][j-1]+a*(d[i-1][j]+d[i][j])<dp[i][j]) {
                    dp[i][j]=dp[i-2][j-1]+a*(d[i-1][j]+d[i][j]);
                    pre[i][j]=PII(i-2,j-1);
                }
                if (j>1&&dp[i-1][j-2]+a*(d[i][j-1]+d[i][j])<dp[i][j]) {
                    dp[i][j]=dp[i-1][j-2]+a*(d[i][j-1]+d[i][j]);
                    pre[i][j]=PII(i-1,j-2);
                }
            }
        }
    }
    printf("%.6f\n",dp[n][m]);
    print(n,m);
    for (int i=0;i<ans.size();i++) {
        if (i>0&&ans[i].first-ans[i-1].first+ans[i].second-ans[i-1].second==3) {
            printf("(%d,%d)\n",ans[i-1].first+1,ans[i-1].second+1);
        }
        printf("(%d,%d)\n",ans[i].first,ans[i].second);
    }
    return 0;
}

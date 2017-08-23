#include <bits/stdc++.h>
using namespace std;

const int N=2510,INF=1<<30;
char a[N],b[N];
int dp[2];
bool mul[N];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%s",a+1);
        scanf("%s",b+1);
        int la=strlen(a+1);
        int lb=strlen(b+1);
        int j=0;
        memset(mul,0,sizeof(mul));
        for (int i=1;i<=lb;i++) {
            if (b[i]=='*') {
                mul[j]=1;
            } else {
                b[++j]=b[i];
            }
        }
        lb=j;
        int flag=0;
        dp[0]=dp[1]=0;
        for (int i=1;i<=lb;i++) {
            if (mul[i]) {
                int p=dp[1];
                if (p<la&&(b[i]=='.'||b[i]==a[p+1])) {
                    ++p;
                    while (p<la&&a[p+1]==a[p]) p++;
                }
                dp[1]=p;
            } else {
                int ll=INF,rr=-INF;
                for (int j=dp[0]+1;j<=dp[1]+1;j++) {
                    if (j>la) break;
                    if (b[i]=='.'||b[i]==a[j]) {
                        ll=min(ll,j);
                        rr=max(rr,j);
                    }
                }
                if (ll==INF) {
                    flag=1;
                    break;
                }
                dp[0]=ll;dp[1]=rr;
            }
        }
        if (flag||dp[1]!=la) {
            puts("no");
        } else {
            puts("yes");
        }
    }
    return 0;
}

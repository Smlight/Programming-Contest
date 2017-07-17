#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5010;
char s[N];
int a[N];
bool pl[N][N];
ll dp[N];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++) {
            scanf("%d",a+i);
        }
        scanf("%s",s+1);
        int l=strlen(s+1);
        memset(pl,0,sizeof(pl));
        for (int k=1;k<=l;k++) {
            int i=k,j=k;
            while (i>=1&&j<=l&&s[i]==s[j]) {
                pl[i--][j++]=1;
            }
            i=k,j=k+1;
            while (i>=1&&j<=l&&s[i]==s[j]) {
                pl[i--][j++]=1;
            }
        }
        memset(dp,0,sizeof(dp));
        for (int i=1;i<=l;i++) {
            for (int j=i;j>=1;j--) {
                if (i-j+1>n) break;
                if (pl[j][i]) dp[i]=max(dp[i],dp[j-1]+a[i-j+1]);
            }
        }
        printf("%lld\n",dp[l]);
    }
    return 0;
}

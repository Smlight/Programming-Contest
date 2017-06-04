#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MO=1e9+7;
ll dp[110][3];
char s[110];
int n;

void add(ll &x,ll y)
{
    x+=y;
    x%=MO;
}

ll dfs(int len,int state,int limit)
{
    if (len<0) return 1;
    if (!limit&&dp[len][state]!=-1) return dp[len][state];
    ll ret=0;
    char last=limit?s[len]:'z';
//    add(ret,dfs(len-1,0,0,1));
    for (char i='a';i<=last;i++) {
        if (i=='a'||state&&i=='c') continue;
        add(ret,dfs(len-1,i=='b',limit&&(i==last)));
    }
    if(!limit) dp[len][state]=ret;
    return ret;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    while (scanf("%s",s)!=EOF) {
        n=strlen(s);
        for (int i=0,j=n-1;i<j;i++,j--) swap(s[i],s[j]);
        ll ans=0;
        for (int i=0;i<n;i++) {
            add(ans,dfs(i,0,i==n-1));
        }
        if (!strstr(s,"a")&&!strstr(s,"cb")) {
            --ans;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

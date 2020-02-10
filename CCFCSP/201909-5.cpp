#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N=50010;
const int inf=0x3f3f3f3f;
struct Edge {
    int go,next,val;
} eg[N<<1];
int last[N],tot=0;
bool imp[N];
ll dp[N][105];
int sz[N];
int n,m,k;

void addedge(int x,int y,int z)
{
    eg[tot]={y,last[x],z};
    last[x]=tot++;
}

void solve(int u,int fa)
{
    dp[u][0]=0;
    if (imp[u]) {
        dp[u][1]=0;
        sz[u]+=1;
    }
    for (int e=last[u];e!=-1;e=eg[e].next) {
        int v=eg[e].go;
        if (v==fa) continue;
        solve(v,u);
        sz[u]+=sz[v];
        for (int i=min(sz[u],k);i;i--) {
            for (int j=1;j<=min(sz[v],i);j++) {
                dp[u][i]=min(dp[u][i],dp[u][i-j]+dp[v][j]+1LL*eg[e].val*j*(k-j));
            }
        }
    }
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    memset(last,-1,sizeof(last));
    for (int i=1;i<=m;i++) {
        int x;
        scanf("%d",&x);
        imp[x]=true;
    }
    for (int i=1;i<n;i++) {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        addedge(x,y,z);
        addedge(y,x,z);
    }
    memset(dp,inf,sizeof(dp));
    solve(1,0);
    printf("%lld\n",dp[1][k]);
    return 0;
}
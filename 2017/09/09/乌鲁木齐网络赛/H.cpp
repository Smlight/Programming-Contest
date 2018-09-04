#include <bits/stdc++.h>
using namespace std;

const int N=10010;
const int INF=1<<29;
struct Edge {
    int go,next,val;
} eg[120000];
int last[N],tot;
int dp[N];
bool mark[N];
int C,n,m;

void addedge(int x,int y,int z)
{
    eg[tot]={y,last[x],z};
    last[x]=tot++;
}

bool spfa(int S)
{
    for (int i = 1; i <= n; i++) dp[i] = -INF;
    memset(mark,0,sizeof(mark));
    queue<int> que;
    que.push(S);
    dp[S] = 0;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        mark[u] = false;
        for (int i=last[u];i!=-1;i=eg[i].next) {
            int v=eg[i].go;
            if (dp[u]+eg[i].val>dp[v]) {
                dp[v]=dp[u]+eg[i].val;
                if (!mark[v]) {
                    mark[v]=true;
                    que.push(v);
                }
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d",&C);
    while (C--) {
        int x,y,z;
        scanf("%d%d",&n,&m);
        tot=0;
        memset(last,-1,sizeof(last));
        for (int i=1;i<=m;i++) {
            scanf("%d%d%d",&x,&y,&z);
            addedge(x,y,z);
        }
        for (int i=1;i<=n;i++) {
            addedge(0,i,0);
        }
        spfa(0);
        int ans=-1;
        for (int i=1;i<=n;i++) {
            ans=max(ans,dp[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}

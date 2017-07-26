#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=200010;
int col[N],sum[N],sz[N];
vector<int> eg[N];
ll ans;

void dfs(int u,int fa)
{
    sz[u]=1;
    int pre=sum[col[u]],tot_has=0;
    for (int v:eg[u]) {
        if (v!=fa) {
            dfs(v,u);
            sz[u]+=sz[v];
            int has=sum[col[u]]-pre;
            tot_has+=has;
            ll none=sz[v]-has;
            ans+=none*(none-1)/2;
            pre=sum[col[u]];
        }
    }
    sum[col[u]]+=sz[u]-tot_has;
}

int main()
{
    int n,cas=0;
    while (scanf("%d",&n)!=EOF) {
        memset(sum,0,sizeof(sum));
        for (int i=1;i<=n;i++) {
            scanf("%d",&col[i]);
            eg[i].clear();
        }
        for (int i=1;i<n;i++) {
            int x,y;
            scanf("%d%d",&x,&y);
            eg[x].push_back(y);
            eg[y].push_back(x);
        }
        ans=0;
        dfs(1,0);
        int col_num=0;
        //i is a color
        for (int i=1;i<=n;i++) {
            if (sum[i]) {
                col_num++;
                ll none=sz[1]-sum[i];
                ans+=none*(none-1)/2;
            }
        }
        ans=1LL*n*(n-1)/2*col_num-ans;
        printf("Case #%d: %lld\n",++cas,ans);
    }
    return 0;
}

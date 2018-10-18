#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N=100005;
int dep[N],fa[N][20],group[N],q[N];
ll dis[N];
bool rd[N];
struct Edge {
    int go,next,val;
} eg[N*2];
int last[N],tot;

void dfs(int u,int pre,ll d,int g)
{
    dis[u]=d;
    group[u]=g;
    fa[u][0]=pre;
    for(int i=1;fa[fa[u][i-1]][i-1];i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    for (int i=last[u];i!=-1;i=eg[i].next) {
        int v=eg[i].go;
        if (v==pre) continue;
        dep[v]=dep[u]+1;
        if (rd[v]) dfs(v,u,0,v);
        else dfs(v,u,d+eg[i].val,g);
    }
}

void addedge(int x,int y,int z)
{
    eg[tot]={y,last[x],z};
    last[x]=tot++;
}

int lca(int x,int y)
{
    if (dep[x]<dep[y]) swap(x,y);
    int k=dep[x]-dep[y];
    for (int i=0;i<20;i++) {
        if (k>>i&1) x=fa[x][i];
    }
    if (x==y) return x;
    for (int i=19;i>=0;i--) {
        if (fa[x][i]!=fa[y][i]) {
            x=fa[x][i];
            y=fa[y][i];
        }
    }
    return fa[x][0];
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int n,m,Q;
        scanf("%d%d%d",&n,&m,&Q);
        memset(rd,0,sizeof(rd));
        memset(fa,0,sizeof(fa));
        for (int i=1;i<=m;i++) {
            int x;
            scanf("%d",&x);
            rd[x]=true;
        }
        tot=0;
        memset(last,-1,sizeof(last));
        for (int i=1;i<n;i++) {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            addedge(x,y,z);
            addedge(y,x,z);
        }
        dfs(1,0,0,1);
        while (Q--) {
            int k;
            scanf("%d",&k);
            for (int i=1;i<=k;i++) {
                scanf("%d",&q[i]);
            }
            sort(q+1,q+k+1,[&](int i,int j){ return dis[i]>dis[j]; });
            q[k+1]=0;
            int u=q[1];
            ll ans=dis[q[2]];
            for (int i=2;i<=k;i++) {
                if (group[q[i]]==group[q[1]]) {
//                    printf("lca input: %d %d\n",u,q[i]);
                    u=lca(u,q[i]);
//                    printf("lca output: %d\n",u);
                    ans=min(ans,max(dis[q[1]]-dis[u],dis[q[i+1]]));
                } else {
                    break;
                }
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}

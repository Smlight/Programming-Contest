#include <bits/stdc++.h>
using namespace std;

const int N=100010;
struct Edge {
    int go,next,val;
} eg[N<<1];
int last[N],tot;
int p[N],co[N];
int ans;

inline void addedge(int x,int y,int z)
{
    eg[tot]={y,last[x],z};
    last[x]=tot++;
}

void dfs(int u,int fa,int s)
{
    co[u]=s;
    for (int i=last[u];i!=-1;i=eg[i].next) {
        int &v=eg[i].go;
        if (v==fa) continue;
        dfs(v,u,min(co[u]+eg[i].val,p[v]));
        co[u]=min(co[u],co[v]+eg[i].val);
    }
}

void dfs2(int u,int fa,int s)
{
    co[u]=min(co[u],s);
    for (int i=last[u];i!=-1;i=eg[i].next) {
        int &v=eg[i].go;
        if (v==fa) continue;
        dfs2(v,u,min(co[u]+eg[i].val,p[v]));
    }
    ans=max(ans,p[u]-co[u]);
}

int main()
{
    int T,n;
    scanf("%d",&T);
    while (T--) {
        tot=0;
        memset(last,-1,sizeof(last));
        scanf("%d",&n);
        for (int i=1;i<=n;i++) {
            scanf("%d",&p[i]);
        }
        for (int i=1;i<n;i++) {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            addedge(x,y,z);
            addedge(y,x,z);
        }
        ans=0;
        dfs(1,-1,p[1]);
        dfs2(1,-1,p[1]);
        printf("%d\n",ans);
    }
    return 0;
}

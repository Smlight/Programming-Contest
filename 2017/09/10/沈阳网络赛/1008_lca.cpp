#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
const int N=100010;
struct Edge {
    int go,next,val;
} eg[N<<1];
int last[N],tot;
int p[N],d[N];
int ans;

inline void addedge(int x,int y,int z)
{
    eg[tot]={y,last[x],z};
    last[x]=tot++;
}

PII dfs(int u,int fa,int s)
{
    d[u]=s;
    int mx=p[u]-d[u],mn=p[u]+d[u];
    for (int i=last[u];i!=-1;i=eg[i].next) {
        int &v=eg[i].go;
        if (v==fa) continue;
        auto res=dfs(v,u,s+eg[i].val);
        mx=max(mx,res.first);
        mn=min(mn,res.second);
    }
    ans=max(ans,2*d[u]+mx-mn);
    return PII(mx,mn);
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
        auto res=dfs(1,-1,p[1]);
        ans=max(ans,2*d[1]+res.first-res.second);
        printf("%d\n",ans);
    }
    return 0;
}

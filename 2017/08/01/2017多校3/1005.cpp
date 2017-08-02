#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e6+5;
struct Edge {
    int go,val,next;
} eg[N<<1];
int last[N],tot,sz[N];
ll ans;
int n,k;

void dfs(int u,int fa)
{
    sz[u]=1;
    for (int i=last[u];i!=-1;i=eg[i].next) {
        int &v=eg[i].go;
        if (v==fa) continue;
        dfs(v,u);
        sz[u]+=sz[v];
        ans+=1LL*eg[i].val*min(sz[v],k);
    }
}

int main()
{
    while (scanf("%d%d",&n,&k)!=EOF) {
        tot=0;ans=0;
        k=min(k,n-1);
        memset(last,-1,sizeof(last));
        for (int i=1;i<n;i++) {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            eg[tot]=(Edge){b,c,last[a]};
            last[a]=tot++;
            eg[tot]=(Edge){a,c,last[b]};
            last[b]=tot++;
        }
        dfs(1,-1);
        printf("%lld\n",ans);
    }
    return 0;
}

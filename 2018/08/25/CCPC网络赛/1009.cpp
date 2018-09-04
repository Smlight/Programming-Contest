#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MO=1e9+7;
const int N=100010;
struct Edge {
    int go,next,val;
} eg[N<<1];
int last[N],tot=0;
int sz[N];
int fac[N];
int T,n;
ll ans;

void addedge(int x,int y,int z)
{
    eg[tot]={y,last[x],z};
    last[x]=tot++;
}

void dfs(int u,int pre)
{
    sz[u]=1;
    for (int i=last[u];i!=-1;i=eg[i].next) {
        int v=eg[i].go;
        if (pre==v) continue;
        dfs(v,u);
        ans+=1LL*eg[i].val*sz[v]%MO*(n-sz[v])%MO;
        if (ans>=MO) ans-=MO;
        sz[u]+=sz[v];
    }
}

int main()
{
    fac[0]=1;
    for (int i=1;i<N;i++) {
        fac[i]=1LL*fac[i-1]*i%MO;
    }
    while (scanf("%d",&n)!=EOF) {
        memset(sz,0,sizeof(sz));
        memset(last,-1,sizeof(last));
        tot=0;
        for (int i=1;i<n;i++) {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            addedge(x,y,z);
            addedge(y,x,z);
        }
        ans=0;
        dfs(1,0);
//        for (int i=1;i<=n;i++) {
//            printf("%d ",sz[i]);
//        }
        printf("%lld\n",ans*2%MO*fac[n-1]%MO);
    }
    return 0;
}
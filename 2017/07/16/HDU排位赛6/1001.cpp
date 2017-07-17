#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=100010;
struct Edge {
    int go,next;
} eg[N];
int tot,last[N];
int a[N],sz[N];
int rear;
ll que[N],ans;

void adde(int x,int y)
{
    eg[++tot].go=y;
    eg[tot].next=last[x];
    last[x]=tot;
}

void dfs(int u,ll s)
{
    sz[u]=1;
    que[rear++]=s+a[u];
    for (int i=last[u];i;i=eg[i].next) {
        int &v=eg[i].go;
        dfs(v,s+a[u]);
        sz[u]+=sz[v];
        ans-=s*sz[v]*sz[v];
    }
    ans+=s*sz[u]*sz[u];
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        tot=0;ans=0;rear=0;
        memset(last,0,sizeof(last));
        int n;
        scanf("%d",&n);
        for (int i=2;i<=n;i++) {
            int fa;
            scanf("%d",&fa);
            adde(fa,i);
        }
        for (int i=1;i<=n;i++) {
            scanf("%d",a+i);
        }
        dfs(1,0);
        ans=-ans;
        sort(que,que+rear);
        for (int i=0;i<rear;i++) {
            ans+=que[i]*(i+i+1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

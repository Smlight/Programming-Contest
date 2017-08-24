#include  <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e5+5;
int a[N],q[N];
int sz[N],sons[N][2],p[N];
ll cnt[N+5],sum[N+5];
struct Edge {
    int go,next;
} eg[N<<1];
int last[N],tot;
int idx,qt;
ll ans[N];

void addedge(int x,int y)
{
    eg[tot]={y,last[x]};
    last[x]=tot++;
}

void dfs(int u,int fa)
{
    sons[u][0]=sons[u][1]=0;
    sz[u]=1;
    int s=0;
    for (int i=last[u];i!=-1;i=eg[i].next) {
        int &v=eg[i].go;
        if (v==fa) continue;
        sons[u][s++]=v;
        dfs(v,u);
        sz[u]+=sz[v];
    }
    if (s==2&&sz[sons[u][0]]>sz[sons[u][1]]) {
        swap(sons[u][0],sons[u][1]);
    }
}

void ins(ll c[],int x,int d)
{
    for (int i=x;i<=N;i+=i&(-i)) {
        c[i]+=d;
    }
}

ll get(ll c[],int x)
{
    ll res=0;
    for (int i=x;i>0;i-=i&(-i)) {
        res+=c[i];
    }
    return res;
}

void remove(int x)
{
    ins(cnt,x,-1);
    ins(sum,x,-q[x]);
}

ll add(int x)
{
    ll res=get(sum,x)+q[x];
    int gt=get(cnt,N)-get(cnt,x);
    res+=(ll)q[x]*gt;
    ins(cnt,x,1);
    ins(sum,x,q[x]);
    return res;
}

void solve(int u)
{
    ans[u]=0;
    int l=idx+1,r;
    if (sons[u][0]) {
        solve(sons[u][0]);
        ans[u]=ans[sons[u][0]];
    }
    r=idx;
    if (sons[u][1]) {
        for (int i=l;i<=r;i++) {
            remove(a[p[i]]);
        }
        solve(sons[u][1]);
        ans[u]=ans[sons[u][1]];
        for (int i=l;i<=r;i++) {
            ans[u]+=add(a[p[i]]);
        }
    }
    ans[u]+=add(a[u]);
    p[++idx]=u;
}

int main()
{
    int T,n;
    scanf("%d",&T);
    while (T--) {
        tot=idx=qt=0;
        memset(last,-1,sizeof(last));
        memset(sons,0,sizeof(sons));
        memset(cnt,0,sizeof(cnt));
        memset(sum,0,sizeof(sum));
        scanf("%d",&n);
        for (int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            q[++qt]=a[i];
        }
        for (int i=1;i<n;i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        sort(q+1,q+qt+1);
        qt=unique(q+1,q+qt+1)-q-1;
        for (int i=1;i<=n;i++) {
            a[i]=lower_bound(q+1,q+qt+1,a[i])-q;
        }
        dfs(1,0);
        solve(1);
        for (int i=1;i<=n;i++) {
            printf("%lld ",ans[i]);
        }
        puts("");
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN=1e5+5;
struct Edge {
    int to,next;
} edge[MAXN*2];
int head[MAXN],tot;
int top[MAXN],fa[MAXN];//父亲节点
int deep[MAXN];//深度
int num[MAXN];//num[v] 表示以v为根的子树的节点数
int p[MAXN];//p[v]表示v对应的位置
int fp[MAXN];//fp和p数组相反
int son[MAXN];//重儿子
int pos;
int v[MAXN*3];

void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
    pos = 1;
    memset(son,-1,sizeof(son));
}

void addedge(int u,int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}

void dfs1(int u,int pre,int d)
{
    deep[u] = d;
    fa[u] = pre;
    num[u] = 1;
    for(int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        if(v != pre) {
            dfs1(v,u,d+1);
            num[u] += num[v];
            if(son[u] == -1 || num[v] > num[son[u]])
                son[u] = v;
        }
    }
}

void getpos(int u,int sp)
{
    top[u] = sp;
    p[u] = pos++;
    fp[p[u]] = u;
    if(son[u] == -1) return;
    getpos(son[u],sp);
    for(int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        if( v != son[u] && v != fa[u])
            getpos(v,v);
    }
}

inline int lowbit(int x)
{
    return x&(-x);
}

ll c[MAXN];
ll sum(int i)
{
    ll s = 0;
    while(i > 0) {
        s += c[i];
        i -= lowbit(i);
    }
    return s;
}

void add(int i,int val)
{
    while(i <MAXN) {
        c[i] += val;
        i += lowbit(i);
    }
}

ll query(int u,int v)
{
    int f1 = top[u], f2 = top[v];
    ll res=0;
    while(f1 != f2) {
        if(deep[f1] < deep[f2]) {
            swap(f1,f2);
            swap(u,v);
        }
        res+=sum(p[u])-sum(p[f1]-1);
        u = fa[f1];
        f1 = top[u];
    }
    if(deep[u] > deep[v]) swap(u,v);
    res+=sum(p[v])-sum(p[u]-1);
    return res;
}

struct Query {
    int u,v,val,zf,id;
    bool operator <(const Query &R) {
        return val<R.val;
    }
} q[MAXN*2];
int a[MAXN];
struct Node {
    int iv,id;
    bool operator <(const Node &R) {
        return iv<R.iv;
    }
} ia[MAXN];
ll ans[MAXN];

int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF) {
        init();
        int vtot=0;
        for (int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            v[++vtot]=a[i];
        }
        for (int i=1;i<n;i++) {
            int x,y;
            scanf("%d%d",&x,&y);
            addedge(x,y);
            addedge(y,x);
        }
        dfs1(1,0,0);
        getpos(1,1);
        for (int i=1;i<=m;i++) {
            int s,t,a,b;
            scanf("%d%d%d%d",&s,&t,&a,&b);
            q[i+i-1]={s,t,a-1,-1,i};
            q[i+i]={s,t,b,1,i};
            v[++vtot]=a-1;
            v[++vtot]=b;
        }
        m<<=1;
        sort(v+1,v+vtot+1);
        vtot=unique(v+1,v+vtot+1)-v-1;
        for (int i=1;i<=m;i++) {
            q[i].val=lower_bound(v+1,v+vtot+1,q[i].val)-v;
        }
        for (int i=1;i<=n;i++) {
            ia[i].iv=lower_bound(v+1,v+vtot+1,a[i])-v;
            ia[i].id=i;
        }
        sort(q+1,q+1+m);
        sort(ia+1,ia+n+1);
        memset(ans,0,sizeof(ans));
        int j=1;
        for (int i=1;i<=m;i++) {
            while (j<=n&&ia[j].iv<=q[i].val) {
                add(p[ia[j].id],a[ia[j].id]);
                ++j;
            }
            ans[q[i].id]+=q[i].zf*query(q[i].u,q[i].v);
        }
        m>>=1;
        for (int i=1;i<=m;i++) {
            printf("%lld%c",ans[i]," \n"[i==m]);
        }
    }
    return 0;
}

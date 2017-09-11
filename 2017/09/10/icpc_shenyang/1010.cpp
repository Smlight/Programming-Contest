#include <bits/stdc++.h>
using namespace std;

const int MAXN=10010;
const int MAXM=50010;
struct Edge {
    int to,next;
} edge[MAXN*2];
int head[MAXN],tot;
int top[MAXN],fa[MAXN],deep[MAXN],num[MAXN];
int p[MAXN],fp[MAXN],c[MAXN+10],son[MAXN];
int pos;
struct Query {
    int x,y,lca;
    bool operator <(const Query &R) const {
        return deep[lca]>deep[R.lca];
    }
} a[MAXM];

void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
    pos = 1;
    memset(son,-1,sizeof(son));
    memset(c,0,sizeof(c));
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
int sum(int i)
{
    int s = 0;
    while(i > 0) {
        s += c[i];
        i -= lowbit(i);
    }
    return s;
}
void add(int i,int val)
{
    while(i <= MAXN) {
        c[i] += val;
        i += lowbit(i);
    }
}
int query(int u,int v)
{
    int f1=top[u],f2=top[v];
    int res=0;
    while (f1 != f2) {
        if (deep[f1]<deep[f2]) {
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
int lca(int u,int v)
{
    int f1 = top[u], f2 = top[v];
    while(f1 != f2) {
        if(deep[f1] < deep[f2]) {
            swap(f1,f2);
            swap(u,v);
        }
        u = fa[f1];
        f1 = top[u];
    }
    if(deep[u] > deep[v]) swap(u,v);
    return u;
}

int main()
{
    int n,m,u,v;
    while (scanf("%d",&n)!=EOF) {
        init();
        for (int i=1;i<=n;i++) {
            scanf("%d%d",&u,&v);
            u++;v++;
            addedge(u,v);
            addedge(v,u);
        }
        dfs1(1,0,0);
        getpos(1,1);
        scanf("%d",&m);
        for (int i=1;i<=m;i++) {
            scanf("%d%d",&u,&v);
            a[i].x=++u;
            a[i].y=++v;
            a[i].lca=lca(a[i].x,a[i].y);
        }
        sort(a+1,a+m+1);
        int ans=0;
        for (int i=1;i<=m;i++) {
            if (query(a[i].x,a[i].y)>0) continue;
            add(p[a[i].lca],1);
            ++ans;
        }
        printf("%d\n",ans);
    }
    return 0;
}

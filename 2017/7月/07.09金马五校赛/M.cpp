#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
const int N=100010,INF=1<<30;
int a[N],isq[N],ans[N];
vector<PII> ga[N];
vector<int> gq[N];
int tag[N<<2],vi[N<<2],vm[N<<2];

inline void add(int x,int y)
{
    tag[x]+=y;
    vi[x]+=y;
    vm[x]+=y;
}

inline void push_down(int rt)
{
    if (tag[rt]) {
        add(rt<<1,tag[rt]);
        add(rt<<1|1,tag[rt]);
        tag[rt]=0;
    }
}

inline void push_up(int rt)
{
    vi[rt]=min(vi[rt<<1],vi[rt<<1|1]);
    vm[rt]=max(vm[rt<<1],vm[rt<<1|1]);
}

#define lson rt<<1,l,m
#define rson rt<<1|1,m+1,r

void build(int rt,int l,int r)
{
    vi[rt]=vm[rt]=tag[rt]=0;
    if (l==r) return;
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    push_up(rt);
}

void update(int rt,int l,int r,int L,int R,int d)
{
    if (L<=l&&r<=R) {
        add(rt,d);
        return;
    }
    push_down(rt);
    int m=(l+r)>>1;
    if (L<=m) update(lson,L,R,d);
    if (m<R) update(rson,L,R,d);
    push_up(rt);
}

void update(PII &p,PII q)
{
    p.first=min(p.first,q.first);
    p.second=max(p.second,q.second);
}

PII query(int rt,int l,int r,int L,int R)
{
    if (L<=l&&r<=R) {
        return PII(vi[rt],vm[rt]);
    }
    push_down(rt);
    int m=(l+r)>>1;
    PII res(INF,-INF);
    if (L<=m) update(res,query(lson,L,R));
    if (m<R) update(res,query(rson,L,R));
    return res;
}

int main()
{
    int T,n,m;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) {
            scanf("%d",a+i);
            ga[i].clear();
            gq[i].clear();
        }
        for (int i=1;i<=m;i++) {
            int op,l,r,k;
            scanf("%d%d",&op,&l);
            isq[i]=op-1;
            if (op==1) {
                scanf("%d%d",&r,&k);
                ga[l].push_back(PII(i,k));
                ga[r+1].push_back(PII(i,-k));
            } else {
                gq[l].push_back(i);
            }
        }
        build(1,0,m);
        for (int i=1;i<=n;i++) {
            for (PII &p:ga[i]) {
                update(1,0,m,p.first,m,p.second);
            }
            for (int x:gq[i]) {
                PII p=query(1,0,m,0,x);
                ans[x]=max(abs(a[i]+p.first),abs(a[i]+p.second));
            }
        }
        for (int i=1;i<=m;i++) {
            if (isq[i]) {
                printf("%d\n",ans[i]);
            }
        }
    }
    return 0;
}

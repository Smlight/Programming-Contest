#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
const int N=(1<<17)+5;
const int INF=1<<29;
int mx[N<<2],mn[N<<2];

#define lson rt<<1,l,m
#define rson rt<<1|1,m+1,r

void push_up(int rt)
{
    mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
    mn[rt]=min(mn[rt<<1],mn[rt<<1|1]);
}

void build(int rt,int l,int r)
{
    if (l==r) {
        int x;
        scanf("%d",&x);
        mx[rt]=mn[rt]=x;
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    push_up(rt);
}

void update(int rt,int l,int r,int k,int x)
{
    if (l==r) {
        mx[rt]=mn[rt]=x;
        return;
    }
    int m=(l+r)>>1;
    if (k<=m) update(lson,k,x);
    else update(rson,k,x);
    push_up(rt);
}

void update(PII &a,const PII &b)
{
    a.first=max(a.first,b.first);
    a.second=min(a.second,b.second);
}

PII query(int rt,int l,int r,int L,int R)
{
    if (L<=l&&r<=R) {
        return PII(mx[rt],mn[rt]);
    }
    int m=(l+r)>>1;
    PII res(-INF,INF);
    if (L<=m) update(res,query(lson,L,R));
    if (m<R) update(res,query(rson,L,R));
    return res;
}

int main()
{
    int T,n,q;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        n=1<<n;
        build(1,1,n);
        scanf("%d",&q);
        for (int i=0;i<q;i++) {
            int op,x,y;
            scanf("%d%d%d",&op,&x,&y);
            if (op==1) {
                x++,y++;
                PII p=query(1,1,n,x,y);
                long long a=p.first,b=p.second;
                printf("%lld\n",min(a*b,min(a*a,b*b)));
            } else {
                x++;
                update(1,1,n,x,y);
            }
        }
    }
    return 0;
}

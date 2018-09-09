#include <bits/stdc++.h>
using namespace std;

const int N=50010;
int x[N],y[N];
int q[N*2];
int mx[N*8],my[N*8];

#define lson rt<<1,l,m
#define rson rt<<1|1,m+1,r

void push_up(int key[],int rt)
{
    key[rt]=max(key[rt<<1],key[rt<<1|1]);
}

void build(int key[],int rt,int l,int r)
{
    key[rt]=0;
    if (l==r) return;
    int m=(l+r)>>1;
    build(key,lson);
    build(key,rson);
}

void update(int key[],int rt,int l,int r,int x,int y)
{
    if (l==r) {
        key[rt]=max(key[rt],y);
        return;
    }
    int m=(l+r)>>1;
    if (x<=m) update(key,lson,x,y);
    else update(key,rson,x,y);
    push_up(key,rt);
}

int query(int key[],int rt,int l,int r,int L,int R)
{
    if (L<=l&&r<=R) {
        return key[rt];
    }
    int m=(l+r)>>1;
    int res=0;
    if (L<=m) res=max(res,query(key,lson,L,R));
    if (m<R) res=max(res,query(key,rson,L,R));
    return res;
}

int main()
{
    int n;
    scanf("%d",&n);
    int t=0;
    for (int i=1;i<=n;i++) {
        scanf("%d%d",&x[i],&y[i]);
        q[++t]=x[i];
        q[++t]=y[i];
    }
    sort(q+1,q+t+1);
    t=unique(q+1,q+t+1)-q-1;
    build(mx,1,1,t);
    build(my,1,1,t);
    long long ans=0;
    for (int i=n;i>=1;i--) {
        int ix=lower_bound(q+1,q+t+1,x[i])-q;
        int iy=lower_bound(q+1,q+t+1,y[i])-q;
        int X=query(mx,1,1,t,iy,t);
        int Y=query(my,1,1,t,ix,t);
        if (X<ix) ans+=q[ix]-q[X];
        if (Y<iy) ans+=q[iy]-q[Y];
        update(mx,1,1,t,iy,ix);
        update(my,1,1,t,ix,iy);
    }
    printf("%lld\n",ans);
    return 0;
}

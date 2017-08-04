#include <bits/stdc++.h>
using namespace std;

const double eps=1e-6;
const int N=60010;
int T,n;
double minn[N<<2];
int add[N<<2];
int a[N],last[N];

void push_up(int rt)
{
    minn[rt]=min(minn[rt<<1],minn[rt<<1|1]);
}

void push_down(int rt)
{
    if (add[rt]) {
        add[rt<<1]+=add[rt];
        add[rt<<1|1]+=add[rt];
        minn[rt<<1]+=add[rt];
        minn[rt<<1|1]+=add[rt];
        add[rt]=0;
    }
}

#define lson rt<<1,l,m
#define rson rt<<1|1,m+1,r

void build(int rt,int l,int r,double k)
{
    add[rt]=0;
    if (l==r) {
        minn[rt]=l*k;
        return;
    }
    int m=(l+r)>>1;
    build(lson,k);
    build(rson,k);
    push_up(rt);
}

void update(int rt,int l,int r,int L,int R)
{
    if (L<=l&&r<=R) {
        add[rt]+=1;
        minn[rt]+=1;
        return;
    }
    push_down(rt);
    int m=(l+r)>>1;
    if (L<=m) update(lson,L,R);
    if (m<R) update(rson,L,R);
    push_up(rt);
}

double query(int rt,int l,int r,int L,int R)
{
    if (L<=l&&r<=R) {
        return minn[rt];
    }
    push_down(rt);
    int m=(l+r)>>1;
    double res=1e20;
    if (L<=m) res=min(res,query(lson,L,R));
    if (m<R) res=min(res,query(rson,L,R));
    return res;
}

bool check(double m)
{
    build(1,1,n,m);
    memset(last,0,sizeof(last));
    for (int i=1;i<=n;i++) {
        update(1,1,n,last[a[i]]+1,i);
        last[a[i]]=i;
        if (query(1,1,n,1,i)<=m*(i+1)) return true;
    }
    return false;
}

double bs(double l,double r)
{
    while (r-l>eps) {
        double m=(l+r)/2;
        if (check(m)) {
            r=m;
        } else {
            l=m;
        }
    }
    return l;
}

int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
        }
        printf("%.10f\n",bs(0,1));
    }
    return 0;
}

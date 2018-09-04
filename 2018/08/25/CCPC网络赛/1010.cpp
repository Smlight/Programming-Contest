#include <bits/stdc++.h>
using namespace std;

const int N=100010;

inline void gmax(int &a,int b) { if (b>a) a=b; }
inline void gmin(int &a,int b) { if (b<a) a=b; }

#define lson rt<<1,l,m
#define rson rt<<1|1,m+1,r
int key[N<<2];
void push_up(int rt)
{
    key[rt]=max(key[rt<<1],key[rt<<1|1]);
}

void build(int rt,int l,int r)
{
    key[rt]=0;
    if (l==r) return;
    int m=(l+r)>>1;
    build(lson);
    build(rson);
}

void update(int rt,int l,int r,int x,int y)
{
    if (l==r) {
        gmax(key[rt],y);
        return;
    }
    int m=(l+r)>>1;
    if (x<=m) update(lson,x,y);
    else update(rson,x,y);
    push_up(rt);
}

int query(int rt,int l,int r,int L,int R)
{
    if (L>R) return 0;
    if (L<=l&&r<=R) return key[rt];
    int m=(l+r)>>1;
    int res=0;
    if (L<=m) gmax(res,query(lson,L,R));
    if (m<R) gmax(res,query(rson,L,R));
    return res;
}

struct House {
    int x,y,iy,val;
} a[N];
int dp[N],q[N];

bool cmpx(const House &a,const House &b)
{
    return a.x<b.x;
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int n;
        scanf("%d",&n);
        int t=0;
        for (int i=1;i<=n;i++) {
            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].val);
            q[++t]=a[i].y;
        }
        sort(q+1,q+t+1);
        t=unique(q+1,q+t+1)-q-1;
        sort(a+1,a+n+1,cmpx);
        build(1,1,t);
        memset(dp,0,sizeof(dp));
        for (int i=1,j;i<=n;) {
            for (j=i;a[j].x==a[i].x;j++) {
                a[j].iy=lower_bound(q+1,q+t+1,a[j].y)-q;
                dp[j]=query(1,1,t,1,a[j].iy-1)+a[j].val;
            }
            for (;i<j;i++) {
                update(1,1,t,a[i].iy,dp[i]);
            }
        }
        printf("%d\n",*max_element(dp+1,dp+n+1));
    }
    return 0;
}
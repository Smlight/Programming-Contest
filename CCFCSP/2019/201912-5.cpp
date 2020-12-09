#include <bits/stdc++.h>
using namespace std;

#define lson rt<<1,l,m
#define rson rt<<1|1,m+1,r

using ll = long long;
const int mod=2019;
const int N=1000005;
const ll U3=1698479428772363217;
const ll U4=2006101093849356424;
const ll M=2009731336725594113;
ll c[32]={
    1, 2006101093849356424, 941391648911191089, 1022292690726729920, 
    1810419142002041716, 1184285083219342236, 1267651882537955420, 1816515142381353759, 
    1698479428772363217, 1582534033367424005, 1302320796828332778, 1694849185896125529, 
    510564102676783292, 1256273799740659674, 508098345173708939, 1495536991172573131, 
    742079454187638693, 193216194344240354, 2009731336725594112, 3630242876237689, 
    1068339687814403024, 987438645998864193, 199312194723552397, 825446253506251877, 
    1501632991551885174, 514194345553020982, 311251907953230896, 427197303358170108, 
    707410539897261335, 314882150829468584, 1499167234048810821, 753457536984934439,
};
int a[N<<2][32], lazy[N<<2][2];
ll x[N][32];
int L,R;
int pre_trans[32][4][8];

void pushup(int rt)
{
    for (int i=0;i<32;i++) {
        a[rt][i]=a[rt<<1][i]+a[rt<<1|1][i];
    }
}

void trans(int rt,int x,int y)
{
    int t0[32]={0};
    for (int i=0;i<32;i++) {
        t0[i]=a[rt][pre_trans[i][x][y]];
    }
    memcpy(a[rt],t0,sizeof(t0));
    lazy[rt][0]+=x;
    (lazy[rt][1]+=y)&=7;
    (lazy[rt][1]+=lazy[rt][0]&4)&=7;
    lazy[rt][0]&=3;
}

void pushdown(int rt)
{
    if (lazy[rt][0]||lazy[rt][1]) {
        trans(rt<<1,lazy[rt][0],lazy[rt][1]);
        trans(rt<<1|1,lazy[rt][0],lazy[rt][1]);
        lazy[rt][0]=lazy[rt][1]=0;
    }
}

void build(int rt,int l,int r)
{
    if (l==r) {
        for (int i=0;i<32;i++) {
            a[rt][i]=x[l][i]%mod;
        }
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}

int query(int rt,int l,int r)
{
    if (L<=l && r<=R) {
        return a[rt][0];
    }
    pushdown(rt);
    int m=(l+r)>>1;
    int res=0;
    if (L<=m) res+=query(lson);
    if (m<R) res+=query(rson);
    return res;
}

void update(int rt,int l,int r,int x,int y)
{
    if (L<=l && r<=R) {
        trans(rt,x,y);
        return;
    }
    pushdown(rt);
    int m=(l+r)>>1;
    if (L<=m) update(lson,x,y);
    if (m<R) update(rson,x,y);
    pushup(rt);
}

int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++) {
        for (int j=0;j<32;j++) {
            x[i][j]=x[i-1][j]+c[j];
            if (x[i][j]>=M) x[i][j]-=M;
        }
    }
    for (int x=0;x<4;x++) {
        for (int y=0;y<8;y++) {
            for (int i=0,ps=0;i<4;i++) {
                for (int j=0;j<8;j++) {
                    pre_trans[ps++][x][y]=(((i+x)&3)<<3)|((j+y+((i+x)&4))&7);
                }
            }
        }
    }
    build(1,1,n);
    int inc[2][5] = {
        {3,3,0,1,0},
        {5,3,3,0,1},
    };
    int ans;
    while (q--) {
        scanf("%d%d",&L,&R);
        ans=query(1,1,n);
        printf("%d\n",ans);
        ans%=5;
        update(1,1,n,inc[0][ans],inc[1][ans]);
    }
    return 0;
}
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N=10010;
struct Rent {
	int xl,yl,xr,yr;
	Rent() {}
	Rent(int a,int b,int c,int d) {
		xl=min(a,c);xr=max(a,c);
		yl=min(b,d);yr=max(b,d);
	}
	bool operator <(const Rent &rt) const {
		return xl<rt.xl||(xl==rt.xl&&xr<rt.xr);
	}
} R[N];
int lazy[N<<2],mini[N<<2],sum[N<<2];

void pushdown(int rt,int l,int r,int m)
{
	if (lazy[rt]) {
		lazy[rt<<1]+=lazy[rt];
		mini[rt<<1]+=lazy[rt];
		if (mini[rt<<1]>=1) sum[rt<<1]=m-l+1;
		else sum[rt<<1]=-1;
		lazy[rt<<1|1]+=lazy[rt];
		mini[rt<<1|1]+=lazy[rt];
		if (mini[rt<<1|1]>=1) sum[rt<<1|1]=r-m;
		else sum[rt<<1|1]=-1;
		lazy[rt]=0;
	}
}

void pushup(int rt)
{
	mini[rt]=min(mini[rt<<1],mini[rt<<1|1]);
	if (sum[rt<<1]>-1&&sum[rt<<1|1]>-1) {
		sum[rt]=sum[rt<<1]+sum[rt<<1|1];
	} else {
		sum[rt]=-1;
	}
}

#define lson rt<<1,l,m
#define rson rt<<1|1,m+1,r
void update(int rt,int l,int r,int L,int R,int d)
{
	if (L<=l&&r<=R) {
		lazy[rt]+=d;
		mini[rt]+=d;
		if (mini[rt]>=1) sum[rt]=r-l+1;
		else sum[rt]=-1;
		return;
	}
	int m=(l+r)>>1;
	pushdown(rt,l,r,m);
	if (L<=m) update(lson,L,R,d);
	if (m<R) update(rson,L,R,d);
	pushup(rt);
}

int query(int rt,int l,int r)
{
	if (l==r) return mini[rt];
	if (sum[rt]>-1) return sum[rt];
	int m=(l+r)>>1;
	pushdown(rt,l,r,m);
	return query(lson)+query(rson);
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		R[i]=Rent(a,b,c,d);
	}
	sort(R,R+n);
	int p=0,q=0,ans=0,m=10000;
	for (int i=0;i<=m;i++) {
		while (p<n&&R[p].xl<=i) {
			update(1,1,m,R[p].yl,R[p].yr-1,1);
			p++;
		}
		while (q<n&&R[q].xr-1<i) {
			update(1,1,m,R[q].yl,R[q].yr-1,-1);
			q++;
		}
		ans+=query(1,1,m);
	}
	printf("%d\n",ans);
	return 0;
}

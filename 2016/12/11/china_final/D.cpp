#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int N=3e5+5;
int T,n,k;
ll b[N],to[N][2];

bool ok(int m)
{
	int p=1;
	int pre=0,now=1;
	for (int j=1;j<=m;j++) {
		to[j][pre]=b[p++];
	}
	for (int i=1;i<k;i++) {
		for (int j=1;j<=m;j++) {
			while (p<=n&&b[p]<to[j][pre]*2) p++;
			if (p>n) return false;
			to[j][now]=b[p++];
		}
		swap(pre,now);
	}
	return true;
}

int bs(int l,int r)
{
	int res=0;
	while (l<=r) {
		int m=(l+r)>>1;
		if (ok(m)) {
			res=m;l=m+1;
		} else {
			r=m-1;
		}
	}
	return res;
}

int main()
{
	scanf("%d",&T);
	for (int t=1;t<=T;t++) {
		scanf("%d%d",&n,&k);
		for (int i=1;i<=n;i++) {
			scanf("%lld",&b[i]);
		}
		sort(b+1,b+1+n);
		int ans=bs(1,n/k);
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}

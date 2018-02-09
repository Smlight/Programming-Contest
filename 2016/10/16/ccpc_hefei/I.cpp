#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int T;
	scanf("%d",&T);
	while (T--) {
		ll l,r;
		scanf("%lld%lld",&l,&r);
		int k=0;
		while (r>>k) k++;
		if (k==0) {
			puts("0");
			continue;
		}
		ll ans=r;
		while (k>0&&((l>>k)&1)==((r>>k)&1)) k--;
		if (k) ans|=(1LL<<k)-1;
		printf("%lld\n",ans);
	}
	return 0;
}

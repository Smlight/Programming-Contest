#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10010;
const int MOD=1e8+7;
char a[N];
int c[N];
int T,n;

ll calc()
{
	ll ans=1;
	for (int i=3;i<=n;i++) {
		c[i]=a[i-1]-a[i-2]+c[i-3];
		if (c[i]<0||c[i]>2) return 0;
		if (c[i]==1) ans=ans*2%MOD;
	}
	if (n>=2&&c[n-2]!=a[n-1]-a[n]) return 0;
	return ans;
}

int main()
{
	scanf("%d",&T);
	while (T--) {
		scanf("%s",a+1);
		n=strlen(a+1);
		for (int i=1;i<=n;i++) {
			a[i]-='0';
		}
		if (n==1) {
			if (a[1]<0||a[1]>2) puts("0");
			else if (a[1]==1) puts("2");
			else puts("1");
			continue;
		}
		ll ans=0;
		for (int i=0;i<=2;i++) {
			c[0]=0;c[1]=i;c[2]=a[1]-c[1];
			if (c[2]<0||c[2]>2) continue;
			ll tmp=1;
			if (c[1]==1) tmp*=2;
			if (c[2]==1) tmp*=2;
			ans=(ans+tmp*calc())%MOD;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

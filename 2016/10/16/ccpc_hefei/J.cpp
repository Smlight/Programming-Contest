#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=670;
ll c[M][M],f[M][M];

void fun(ll x,ll y)
{
	int i=x,j=y;
	while (y>0) {
		c[i][j]++;
		int t=x%y;
		x=y;
		y=t;
	}
	f[i][j]=c[i][j]*x*x;
}

int main()
{
	for (int i=1;i<=666;i++) {
		for (int j=1;j<=666;j++) {
			fun(i,j);
		}
	}
	int T;
	scanf("%d",&T);
	while (T--) {
		ll n,m,p;
		scanf("%lld%lld%lld",&n,&m,&p);
		ll ans=0;
		for (int j=1;j<=m;j++) {
			for (int i=1;i<=j;i++) {
				ll gap=c[i][j]*j;
				for (ll k=i,t=0;k<=n&&t<c[i][j];k+=j,t++) {
					ll num=(n-k)/gap+1;
					ll last=k+gap*(num-1);
					ll sv=k*j/f[i][j];
					ll ev=last*j/f[i][j];
					ans=(ans+(sv+ev)*num/2%p)%p;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MO=1e9+7;

ll fpow(ll x,ll n)
{
	ll ret=1;
	while (n) {
		if (n&1) ret=ret*x%MO;
		x=x*x%MO;
		n>>=1;
	}
	return ret;
}

ll inv(int x)
{
    if (x==1) return 1;
    return (MO-MO/x)*inv(MO%x)%MO;
}

int main()
{
	int T,p,q,k;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d",&p,&q,&k);
		ll ans=(1+fpow((p-2*q)*inv(p)%MO,k)+MO)%MO*inv(2)%MO;
		printf("%lld\n",ans);
	}
}

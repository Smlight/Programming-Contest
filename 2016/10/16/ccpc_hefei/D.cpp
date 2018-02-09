#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=1<<30;
const int N=1e6+10;

int main()
{
	int a,b,c,d,n;
	while (scanf("%d%d%d%d%d",&a,&b,&c,&d,&n)!=EOF) {
		ll mnn=INF,mxx=-INF,x,y;
		for (int i=1;i<=n;i++) {
			scanf("%lld%lld",&x,&y);
			mnn=min(mnn,(a*x+b*y)*(c*x+d*y));
			mxx=max(mxx,(a*x+b*y)*(c*x+d*y));
		}
		printf("%.0f\n",(mxx-mnn)/fabs(a*d-b*c));
	}
}

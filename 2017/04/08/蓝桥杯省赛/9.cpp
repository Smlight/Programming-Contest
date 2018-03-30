#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

typedef long long ll;
const int N=100010;
int h[N],w[N];
int n,k;

bool check(int x)
{
	ll res=0;
	for (int i=1;i<=n;i++) {
		res+=(h[i]/x)*(w[i]/x);
	}
	return res>=k;
}

int bs(int l,int r)
{
	int res=-1;
	while (l<=r) {
		int mid=(l+r)>>1;
		if (check(mid)) {
			res=mid;l=mid+1;
		} else {
			r=mid-1;
		}
	}
	return res;
}

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) {
		scanf("%d%d",&h[i],&w[i]);
	}
	printf("%d\n",bs(1,100000));
	return 0;
}

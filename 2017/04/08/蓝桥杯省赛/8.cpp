#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int a[105];
int f[10010];

int gcd(int a,int b)
{
	if (!b) return a;
	return gcd(b,a%b);
}

int main()
{
	int n,g,m=10000;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d",a+i);
		if (i==1) g=a[1];
		else g=gcd(g,a[i]);
	}
	if (g!=1) {
		puts("INF");
		return 0;
	}
	f[0]=1;
	for (int i=1;i<=n;i++) {
		for (int j=a[i];j<=m;j++) {
			f[j]|=f[j-a[i]];
		}
	}
	int ans=0;
	for (int j=1;j<=m;j++) {
		ans+=f[j]^1;
	}
	printf("%d\n",ans);
	return 0;
}


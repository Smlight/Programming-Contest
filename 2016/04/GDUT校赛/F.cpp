#include <iostream> 
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LLint;

const LLint MAX=1e9;
LLint a[51];
bool b[51];
vector <LLint> q;

LLint gcd(LLint a,LLint b)
{
	return (b==0)?a:gcd(b,a%b);
}

LLint lcm(LLint a,LLint b)
{
	LLint g=gcd(a,b);
	if (g<0) g=-g;
	return a/g*b;
}

int main()
{
	int T,n,i,j;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		sort(a+1,a+1+n);
		for (i=1;i<=n;i++) b[i]=0;
		for (i=1;i<=n;i++)
			for (j=i+1;j<=n;j++)
				if (!b[i]&&!b[j]&&a[j]%a[i]==0) b[j]=1;
		q.clear();
		q.push_back(1);
		for (i=1;i<=n;i++)
		if (!b[i])
		{
			int t=q.size();
			for (j=0;j<t;j++)
			{
				LLint tmp=-1LL*lcm(q[j],a[i]);
				if (tmp>MAX||-tmp>MAX) continue;
				q.push_back(tmp);
			}
		}
		LLint ans=0;
		for (j=0;j<q.size();j++)
			ans+=MAX/q[j];
		printf("%lld\n",ans);
	}
}

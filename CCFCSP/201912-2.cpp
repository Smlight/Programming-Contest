#include <bits/stdc++.h>
using namespace std;

using PII = pair<int,int>;
set<PII> s;
const int N=1010;
int x[N],y[N];

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d%d",&x[i],&y[i]);
		s.insert({x[i],y[i]});
	}
	int c[5]={0};
	for (int i=1;i<=n;i++) {
		PII p(x[i],y[i]);
		if (s.count({p.first-1,p.second}) && s.count({p.first+1,p.second}) && s.count({p.first,p.second-1}) && s.count({p.first,p.second+1})) {
			c[(s.count({p.first-1,p.second-1})+s.count({p.first-1,p.second+1})+s.count({p.first+1,p.second-1})+s.count({p.first+1,p.second+1}))]++;
		}
	}
	for (int i=0;i<5;i++) {
		printf("%d\n",c[i]);
	}
	return 0;
}

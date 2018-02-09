#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=40010;
set<int> eg[N];

int main()
{
	int T,n,m;
	scanf("%d",&T);
	while (T--) {
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) {
			eg[i].clear();
		}
		for (int i=1;i<n;i++) {
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			if (z) {
				eg[x].insert(y);
				eg[y].insert(x);
			}
		}
		while (m--) {
			int op;
			scanf("%d",&op);
			if (op==0) {
				int x;
				scanf("%d",&x);
				if (eg[x].size()&1) puts("Girls win!");
				else puts("Boys win!");
			} else {
				int x,y,z;
				scanf("%d%d%d",&x,&y,&z);
				if (z) {
					if (eg[x].find(y)==eg[x].end()) {
						eg[x].insert(y);
						eg[y].insert(x);
					}
				} else {
					if (eg[x].find(y)!=eg[x].end()) {
						eg[x].erase(y);
						eg[y].erase(x);
					}
				}
			}
		}
	}
	return 0;
}

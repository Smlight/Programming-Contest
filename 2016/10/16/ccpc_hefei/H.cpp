#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=110;
int ans[N][N],a[N];

int main()
{
	int T;
	scanf("%d",&T);
	while (T--) {
		int n,m;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) {
			scanf("%d",&a[i]);
		}
		for (int j=1;j<=n;j++) {
			for (int i=1;i+j-1<=n;i++) {
				ans[i][j]=ans[i][j-1]^a[i+j-1];
			}
		}
		scanf("%d",&m);
		while (m--) {
			int x;
			scanf("%d",&x);
			int mn=1<<30,res=0;
			for (int j=n;j;j--) {
				for (int i=1;i+j-1<=n;i++) {
					if (abs(ans[i][j]-x)<mn) {
						mn=abs(ans[i][j]-x);
						res=j;
					}
				}
			}
			printf("%d\n",res);
		}
		puts("");
	}
	return 0;
}

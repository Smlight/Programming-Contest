#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2020;
int mp[N][N],in[N];
int T,n;

bool circle(int k)
{
	queue<int> Q;
	for (int i=1;i<=n;i++) {
		in[i]=0;
		for (int j=1;j<=n;j++) {
			if (mp[j][i]==1||mp[j][i]==k) {
				in[i]++;
			}
		}
		if (in[i]==0) Q.push(i);
	}
	int cnt=n;
	while (!Q.empty()) {
		int u=Q.front();
		Q.pop();
		cnt--;
		for (int i=1;i<=n;i++) {
			if (mp[u][i]==1||mp[u][i]==k) {
				if (--in[i]==0) Q.push(i);
			}
		}
	}
	if (cnt) return true;
	else return false;
}

int main()
{
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				mp[i][j]=0;
			}
		}
		for (int i=1;i<=n;i++) {
			char s[N];
			scanf("%s",s+1);
			for (int j=1;j<=n;j++) {
				if (s[j]=='P') {
					mp[i][j]=1;
				} else if (s[j]=='Q') {
					mp[i][j]=2;
					mp[j][i]=-2;
				}
			}
		}
		if (circle(2)||circle(-2)) puts("N");
		else puts("T");
	}
	return 0;
}

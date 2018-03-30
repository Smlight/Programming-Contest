#include <bits/stdc++.h>
using namespace std;

const int N=15;
const int dx[]={1,0,0,-1};
const int dy[]={0,1,-1,0};
const char P[]="DRLU";
char mp[N][N];
int vis[N][N],ans[N][N];
int n=10;

int dfs(int x,int y)
{
	if (vis[x][y]) return ans[x][y];
	vis[x][y]=1;
	for (int i=0;i<4;i++) {
		if (mp[x][y]==P[i]) {
			int xx=x+dx[i],yy=y+dy[i];
			if (xx<0||xx>=n||yy<0||yy>=n) return ans[x][y]=1;
			return ans[x][y]=dfs(xx,yy);
		}
	}
	return 0;
}

int main()
{
	for (int i=0;i<n;i++) {
		scanf("%s",mp[i]);
	}
	int sum=0;
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			if (!vis[i][j]) {
				ans[i][j]=dfs(i,j);
			}
			sum+=ans[i][j];
		}
	}
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			printf("%d",ans[i][j]);
		}
		puts("");
	}
	printf("%d\n",sum);
	return 0;
}

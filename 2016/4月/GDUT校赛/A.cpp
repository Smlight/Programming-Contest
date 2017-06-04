#include <iostream> 
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int N=1001;
bool map[N][N];
struct Monster
{
	int id,def,add;
	bool operator>(const Monster& a) const
	{
		return def>a.def;
	}
};
vector<Monster> mon[N];
priority_queue<Monster,vector<Monster>,greater<Monster> > M;
bool vis[N];
int cnt[N],father[N];
int T,n,m,atk;

void dfs(int u,int fa)
{
	father[u]=fa;
	for (int i=0;i<cnt[u];i++)
		M.push(mon[u][i]);
	if (cnt[u]) return;
	for (int i=0;i<n;i++)
		if (map[u][i]&&i!=fa) dfs(i,u);
}

bool solve()
{
	while (!M.empty()) M.pop();
	dfs(0,-1);
	while (!M.empty())
	{
		Monster tmp=M.top();
		M.pop();
		if (atk<=tmp.def) return 0;
		atk+=tmp.add;
		int &u=tmp.id;
		if (--cnt[u]==0)
		{
			for (int i=0;i<n;i++)
				if (map[u][i]&&i!=father[u]) dfs(i,u);
		}
	}
	return 1;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		int x,y,z,i;
		scanf("%d%d",&n,&m);
		memset(map,0,sizeof(map));
		memset(vis,0,sizeof(vis));
		for (i=1;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			map[x][y]=map[y][x]=1;
		}
		for (i=0;i<n;i++) mon[i].clear();
		scanf("%d",&atk);
		for (i=1;i<=m;i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			Monster tmp={x,y,z};
			mon[x].push_back(tmp);
		}
		for (i=0;i<n;i++)
			cnt[i]=mon[i].size();
		if (solve()) puts("Oh yes.");
		else puts("Good Good Study,Day Day Up.");
	}
	return 0;
}

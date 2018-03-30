#include <bits/stdc++.h>
using namespace std;

const int N=15;
int n=9;
int a[N];
int ans;
set< vector<int> > allst;

bool check()
{
	if (a[0]!=0) return false;
	for (int i=1;i<n;i++) {
		if (a[i]!=9-i) return false;
	}
	return true;
}

bool have()
{
	vector<int> v;
	for (int i=0;i<n;i++) {
		v.push_back(a[i]);
	}
	if (allst.find(v)!=allst.end()) return true;
	allst.insert(v);
	return false;
}

void dfs(int dep,int p)
{
//	printf("%d %d\n",dep,p);
	if (dep>=ans) return;
	if (have()) return;
	if (check()) {
		puts("SUCCESSFUL!");
		ans=dep;
		return;
	}
	swap(a[p],a[(p+1)%9]);
	dfs(dep+1,(p+1)%9);
	swap(a[p],a[(p+1)%9]);
	
	swap(a[p],a[(p+2)%9]);
	dfs(dep+1,(p+2)%9);
	swap(a[p],a[(p+2)%9]);
	
	swap(a[p],a[(p+7)%9]);
	dfs(dep+1,(p+7)%9);
	swap(a[p],a[(p+7)%9]);
	
	swap(a[p],a[(p+8)%9]);
	dfs(dep+1,(p+8)%9);
	swap(a[p],a[(p+8)%9]);
	
}

int main()
{
	for (int i=0;i<n;i++) {
		a[i]=i;
	}
	ans=50;
	dfs(0,0);
	printf("%d\n",ans);
	return 0;
}

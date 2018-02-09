#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
int match[][2]={{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}};
struct Result {
	int a,b,c,d;
	Result() {
	}
	Result(int w,int x,int y,int z) {
		a=w;b=x;c=y;d=z;
	}
} r[1000];
int top,s[5];

void dfs(int dep)
{
	if (dep>=6) {
		r[top++]=Result(s[1],s[2],s[3],s[4]);
		return;
	}
	s[match[dep][0]]+=3;
	dfs(dep+1);
	s[match[dep][0]]-=3;
	s[match[dep][1]]+=3;
	dfs(dep+1);
	s[match[dep][1]]-=3;
	s[match[dep][0]]+=1;
	s[match[dep][1]]+=1;
	dfs(dep+1);
	s[match[dep][0]]-=1;
	s[match[dep][1]]-=1;
}

int count(int a,int b,int c,int d)
{
	int res=0;
	for (int i=0;i<top;i++) {
		if (r[i].a==a&&r[i].b==b&&r[i].c==c&&r[i].d==d) res++;
	}
	return res;
}

int main()
{
	top=0;
	memset(s,0,sizeof(s));
	dfs(0);
	int T;
	scanf("%d",&T);
	for (int t=1;t<=T;t++) {
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		printf("Case #%d: ",t);
		int cnt=count(a,b,c,d);
		if (cnt==0) puts("Wrong Scoreboard");
		else if (cnt==1) puts("Yes");
		else puts("No");
	}
	return 0;
}

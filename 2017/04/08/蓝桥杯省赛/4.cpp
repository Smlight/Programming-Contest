#include <bits/stdc++.h>
using namespace std;

struct Node {
	int x,y,s;
	bool vis[6][6];
	Node() {
		x=0;y=0;s=1;
		memset(vis,0,sizeof(vis));
	}
	
};
const int dx[]={1,0,0,-1};
const int dy[]={0,1,-1,0};
int tot=0;
set< vector<int> > allst;

void print(bool a[][6])
{
	for (int i=0;i<6;i++) {
		for (int j=0;j<6;j++) {
			printf("%d ",a[i][j]);
		}
		puts("");
	}
	puts("");
}

void ins(bool a[][6])
{
	vector<int> v;
	for (int i=0;i<6;i++) {
		for (int j=0;j<6;j++) {
			v.push_back(a[i][j]);
		}
	}
	allst.insert(v);
}

int main()
{
	queue<Node> Q;
	Node now;
	now.vis[0][0]=1;
	Q.push(now);
	while (!Q.empty()) {
		Node tmp=Q.front();
		Q.pop();
		for (int i=0;i<4;i++) {
			int xx=tmp.x+dx[i],yy=tmp.y+dy[i];
			if (xx<0||xx>=6||yy<0||yy>=6||tmp.vis[xx][yy]||tmp.vis[5-xx][5-yy]) continue;
			Node now(tmp);
			now.x+=dx[i];now.y+=dy[i];now.s++;now.vis[xx][yy]=1;
			if (now.s==18) {
				print(now.vis);
				ins(now.vis);
				continue;
			}
			Q.push(now);
		}
	}
	printf("%d\n",allst.size());
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int dx[]={1,0,0,-1};
const int dy[]={0,1,-1,0};
int vis[9][9];
int ans;

void dfs(int x,int y)
{
    if (x==0||x==6||y==0||y==6) {
        ++ans;
        return;
    }
    for (int i=0;i<4;i++) {
        int xx=x+dx[i],yy=y+dy[i];
        if (xx<0||xx>6||yy<0||yy>6) continue;
        if (vis[xx][yy]||vis[6-xx][6-yy]) continue;
        vis[xx][yy]=vis[6-xx][6-yy]=true;
        dfs(xx,yy);
        vis[xx][yy]=vis[6-xx][6-yy]=false;
    }
}

int main()
{
    ans=0;
    vis[3][3]=1;
    dfs(3,3);
    printf("%d\n",ans/4);
	return 0;
}

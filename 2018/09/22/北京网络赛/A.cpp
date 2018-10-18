#include<bits/stdc++.h>
using namespace std;

const int N=110;
const int inf=0x3f3f3f3f;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
char mp[N][N];
int dis[N][N][6];
int n,m;
int sx,sy,ex,ey;
struct Node {
    int x,y,t,o;
    bool operator<(const Node &R) const {
        return t<R.t;
    }
    bool operator>(const Node &R) const {
        return t>R.t;
    }
};

int bfs()
{
    memset(dis,inf,sizeof(dis));
    priority_queue<Node,vector<Node>,greater<Node>> Q;
    Q.push({sx,sy,0,0});
    dis[sx][sy][0]=0;
    while (!Q.empty()) {
        auto p=Q.top();
        Q.pop();
        for (int i=0;i<4;i++) {
            int xx=p.x+dx[i];
            int yy=p.y+dy[i];
            if (xx<0||xx>=n||yy<0||yy>=m) continue;
            if (mp[xx][yy]=='#') {
                if (p.o<1) continue;
                if (p.t+2<dis[xx][yy][p.o-1]) {
                    dis[xx][yy][p.o-1]=p.t+2;
                    Q.push({xx,yy,p.t+2,p.o-1});
                }
            } else {
                int oo=(mp[xx][yy]=='B')+p.o;
                int tt=p.t+1-(mp[xx][yy]=='P');
                if (tt<dis[xx][yy][oo]) {
                    dis[xx][yy][oo]=tt;
                    Q.push({xx,yy,tt,oo});
                }
            }
        }
    }
    int res=*min_element(dis[ex][ey],dis[ex][ey]+6);
    return res==inf?-1:res;
}

int main()
{
    while (scanf("%d%d",&n,&m)!=EOF) {
        if (!n) break;
        for (int i=0;i<n;i++) {
            scanf("%s",mp[i]);
            for (int j=0;j<m;j++) {
                if (mp[i][j]=='S') {
                    sx=i;
                    sy=j;
                } else if (mp[i][j]=='T') {
                    ex=i;
                    ey=j;
                }
            }
        }
        printf("%d\n",bfs());
    }
    return 0;
}

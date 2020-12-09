#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
const int N=110,INF=0x3f3f3f3f;
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};
PII bad[N][N];
int dis[N][N];
bool vis[N][N];
struct Node {
    int t,x,y;
    Node(int a=0,int b=0,int c=0):t(a),x(b),y(c) {}
    bool operator<(const Node &R) const {
        if (t!=R.t) return t<R.t;
        if (x!=R.x) return x<R.x;
        return y<R.y;
    }
    bool operator>(const Node &R) const {
        return R<*this;
    }
};

int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    while (k--) {
        int x,y,s,t;
        scanf("%d%d%d%d",&x,&y,&s,&t);
        bad[x][y]=PII(s,t);
    }
    memset(dis,INF,sizeof(dis));
    priority_queue< Node,vector<Node>,greater<Node> > Q;
    Q.push(Node(0,1,1));
    dis[1][1]=0;
    vis[1][1]=true;
    while (!Q.empty()) {
        Node p=Q.top();
        Q.pop();
        int x=p.x,y=p.y,t=dis[x][y];
        vis[x][y]=false;
        for (int i=0;i<4;i++) {
            int xx=x+dx[i],yy=y+dy[i];
            if (xx<1||xx>n||yy<1||yy>m) continue;
            int nt=t+1;
            if (nt>=bad[xx][yy].first&&nt<=bad[xx][yy].second) continue;
            if (nt<dis[xx][yy]) {
                dis[xx][yy]=nt;
                if (!vis[xx][yy]) {
                    Q.push(Node(nt,xx,yy));
                    vis[xx][yy]=true;
                }
            }
        }
    }
    printf("%d\n",dis[n][m]);
    return 0;
}

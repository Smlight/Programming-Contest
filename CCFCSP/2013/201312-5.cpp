#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
const int N=55;
bool vis[N][N],rvis[N][N];
char mp[N][N];
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};
int n,m;

void bfs(PII u,bool vis[][N])
{
    queue<PII> Q;
    Q.push(u);
    while (!Q.empty()) {
        PII u=Q.front();
        Q.pop();
        int x=u.first,y=u.second;
        vis[x][y]=true;
        int l=1,r=2;
        if (mp[x][y]=='+') {
            l=0;r=4;
        } else if (mp[x][y]=='|') {
            l=0;r=2;
        } else if (mp[x][y]=='-') {
            l=2;r=4;
        }
        for (int i=l;i<r;i++) {
            int xx=x+dx[i],yy=y+dy[i];
            if (xx<0||xx>=n||yy<0||yy>=m||mp[xx][yy]=='#'||vis[xx][yy]) continue;
            Q.push(PII(xx,yy));
        }
    }
}

void rbfs(PII u,bool vis[][N])
{
    queue<PII> Q;
    Q.push(u);
    while (!Q.empty()) {
        PII u=Q.front();
        Q.pop();
        int x=u.first,y=u.second;
        vis[x][y]=true;
        for (int i=0;i<4;i++) {
            int xx=x+dx[i],yy=y+dy[i];
            if (xx<0||xx>=n||yy<0||yy>=m||mp[xx][yy]=='#'||vis[xx][yy]) continue;
            if (mp[xx][yy]=='.'&&i==0||mp[xx][yy]=='|'&&i<2||mp[xx][yy]=='-'&&i>=2||mp[xx][yy]=='+') Q.push(PII(xx,yy));
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    PII s,t;
    for (int i=0;i<n;i++) {
        scanf("%s",mp[i]);
        for (int j=0;j<m;j++) {
            if (mp[i][j]=='S') {
                s=PII(i,j);
                mp[i][j]='+';
            } else if (mp[i][j]=='T') {
                t=PII(i,j);
                mp[i][j]='+';
            }
        }
    }
    bfs(s,vis);
    if (!vis[t.first][t.second]) {
        puts("I'm stuck!");
    } else {
        rbfs(t,rvis);
        int ans=0;
        for (int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if (vis[i][j]&&!rvis[i][j]) ++ans;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

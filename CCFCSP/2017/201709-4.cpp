#include <bits/stdc++.h>
using namespace std;

const int N=1010;
const int M=10010;
struct Edge {
    int go,next;
} eg[2][M];
int last[2][N],tot,vis[2][N];
int n,m;

void addedge(int x,int y)
{
    eg[0][tot].go=y;
    eg[0][tot].next=last[0][x];
    last[0][x]=tot;
    eg[1][tot].go=x;
    eg[1][tot].next=last[1][y];
    last[1][y]=tot++;
}

int bfs(int u,Edge eg[M],int last[N],int vis[N])
{
    int res=0;
    queue<int> Q;
    Q.push(u);
    for (int i=1;i<=n;i++) vis[i]=false;
    vis[u]=true;
    while (!Q.empty()) {
        int u=Q.front();
        Q.pop();
        ++res;
        for (int i=last[u];i!=-1;i=eg[i].next) {
            int v=eg[i].go;
            if (!vis[v]) {
                vis[v]=true;
                Q.push(v);
            }
        }
    }
    return res;
}

int main()
{
    scanf("%d%d",&n,&m);
    tot=0;
    memset(last,-1,sizeof(last));
    for (int i=1;i<=m;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        addedge(x,y);
    }
    int ans=0;
    for (int i=1;i<=n;i++) {
        bfs(i,eg[0],last[0],vis[0]);
        bfs(i,eg[1],last[1],vis[1]);
        int cnt=0;
        for (int j=1;j<=n;j++) {
            cnt+=(vis[0][j]|vis[1][j]);
        }
        ans+=(cnt==n);
    }
    printf("%d\n",ans);
    return 0;
}

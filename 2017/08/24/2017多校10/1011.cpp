#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN=110000;
const ll INF=1LL<<60;
struct Edge {
    int go,next;
    ll w;
} eg[MAXN<<1];
int last[MAXN],tot;
struct Node {
    ll dis;
    int v,mark;
    bool operator <(const Node &p) const {
        return p.dis<dis;
    }
};
ll dis[MAXN][2];
bool vis[MAXN][2];
int T,n,m;

void addedge(int x,int y,ll z)
{
    eg[tot]={y,last[x],z};
    last[x]=tot++;
}

void dij(int S)
{
    for (int i=1;i<=n;i++) {
        dis[i][0]=dis[i][1]=INF;
    }
    memset(vis,0,sizeof(vis));
    priority_queue<Node>Q;
    dis[S][0]=0;
    Q.push({0,S,0});
    while(!Q.empty()) {
        Node p=Q.top();
        Q.pop();
        int u=p.v;
        if (vis[u][p.mark])continue;
        //if (dis[u][p.mark]!=p.dis)continue;
        vis[u][p.mark]=true;
        for (int i=last[u];i!=-1;i=eg[i].next) {
            int v=eg[i].go;
            ll w=eg[i].w;
            if (!vis[v][0]&&p.dis+w<=dis[v][0]) {
                if (dis[v][0]!=INF){
                    dis[v][1]=dis[v][0];
                    Q.push({dis[v][1],v,1});
                }
                dis[v][0]=p.dis+w;
                Q.push({dis[v][0],v,0});
            } else if (!vis[v][1]&&p.dis+w<dis[v][1]) {
                dis[v][1]=p.dis+w;
                Q.push({dis[v][1],v,1});
            }
        }
    }
}

int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        tot=0;
        memset(last,-1,sizeof(last));
        for(int i=1;i<=m;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
            addedge(v,u,w);
        }
        dij(1);
        printf("%lld\n",dis[n][1]);
    }
    return 0;
}

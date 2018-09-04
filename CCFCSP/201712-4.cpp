#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;

const int N=510;
const int INF=0x3f3f3f3f;
const int M=100010;
struct Edge {
    int go,next,co;
} eg[2][7*M];
int last[2][N],tot[2];

void addedge(int x,int y,int z,int w)
{
    eg[w][tot[w]].go=y;
    eg[w][tot[w]].next=last[w][x];
    eg[w][tot[w]].co=z;
    last[w][x]=tot[w]++;
}

struct Node {
    int u,d;
    Node(int a,int b):u(a),d(b) {}
    bool operator<(const Node &R) const {
        return d<R.d;
    }
    bool operator>(const Node &R) const {
        return d>R.d;
    }
};
int dis[N];
bool vis[N];

void dij(int S,Edge eg[],int last[],bool pr=false)
{
    priority_queue< Node,vector<Node>,greater<Node> > Q;
    memset(vis,0,sizeof(vis));
    memset(dis,INF,sizeof(dis));
    dis[S]=0;
    Q.push(Node(S,0));
    while (!Q.empty()) {
        Node p=Q.top();
        Q.pop();
        int u=p.u;
        if (vis[u]) continue;
        vis[u]=true;
        for (int i=last[u];i!=-1;i=eg[i].next) {
            int v=eg[i].go,co=eg[i].co;
            if (!vis[v]&&dis[u]+co<dis[v]) {
                dis[v]=dis[u]+co;
                if (pr) printf("dis[%d] = %d via %d\n",v,dis[v],u);
                Q.push(Node(v,dis[v]));
            }
        }
    }
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    tot[0]=tot[1]=0;
    memset(last,-1,sizeof(last));
    for (int i=1;i<=m;i++) {
        int t,a,b,c;
        scanf("%d%d%d%d",&t,&a,&b,&c);
        addedge(a,b,c,t);
        addedge(b,a,c,t);
    }
    for (int i=1;i<=n;i++) {
        dij(i,eg[1],last[1]);
//        printf("=======WITHIN NODE %d=======\n",i);
        for (int j=1;j<=n;j++) {
//            printf("%d ",dis[j]);
            if (i==j) continue;
            if (dis[j]!=INF) {
//                printf("%d %d %d\n",i,j,dis[j]*dis[j]);
                addedge(i,j,dis[j]*dis[j],0);
            }
        }
//        puts("");
    }
    dij(1,eg[0],last[0]);
    printf("%d\n",dis[n]);
    return 0;
}

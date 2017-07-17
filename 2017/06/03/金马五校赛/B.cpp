#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

char mp[60][60];

const int INF=0x3f3f3f3f;
const int MAXN=3000;

struct qnode {
    int v;
    int c;
    qnode(int _v=0,int _c=0):v(_v),c(_c) {}
    bool operator <(const qnode &r)const
    {
        return c>r.c;
    }
};

struct Edge {
    int v,cost;
    Edge(int _v=0,int _cost=0):v(_v),cost(_cost) {}
};

vector<Edge>E[MAXN];
bool vis[MAXN];
int dist[MAXN];

void Dijkstra(int n,int start)//点的编号从1开始
{
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++) dist[i]=INF;
    priority_queue<qnode>que;
    while(!que.empty())que.pop();
    dist[start]=0;
    que.push(qnode(start,0));
    qnode tmp;
    while(!que.empty()) {
        tmp=que.top();
        que.pop();
        int u=tmp.v;
        if(vis[u])continue;
        vis[u]=true;
        for(int i=0; i<E[u].size(); i++) {
            int v=E[tmp.v][i].v;
            int cost=E[u][i].cost;
            if(!vis[v]&&dist[v]>dist[u]+cost) {
                dist[v]=dist[u]+cost;
                que.push(qnode(v,dist[v]));
            }
        }
    }
}

void addedge(int u,int v,int w)
{
    u++;v++;
    E[u].push_back(Edge(v,w));
}

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF) {
        for (int i=0;i<n;i++) {
            scanf("%s",mp[i]);
        }
        for (int i=0;i<n*n;i++) {
            E[i+1].clear();
        }
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (i>0) addedge(i*n+j,(i-1)*n+j,mp[i][j]=='#'||mp[i][j]!=mp[i-1][j]);
                if (i<n-1) addedge(i*n+j,(i+1)*n+j,mp[i][j]=='#'||mp[i][j]!=mp[i+1][j]);
                if (j>0) addedge(i*n+j,i*n+j-1,mp[i][j]=='#'||mp[i][j]!=mp[i][j-1]);
                if (j<n-1) addedge(i*n+j,i*n+j+1,mp[i][j]=='#'||mp[i][j]!=mp[i][j+1]);
            }
        }
        Dijkstra(n*n,1);
        printf("%d\n",dist[n*n]);
    }
    return 0;
}

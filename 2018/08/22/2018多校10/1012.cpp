#include <bits/stdc++.h>
using namespace std;

const int MAXN = 600;
const int MAXM = 100000;
const int INF = 0x3f3f3f3f;
struct Edge {
    int to,next,cap,flow,cost;
} edge[MAXM];
int head[MAXN],tol;
int pre[MAXN],dis[MAXN];
bool vis[MAXN];
int N;//节点总个数，节点编号从0~N-1

void init(int n)
{
    N = n;
    tol = 0;
    memset(head,-1,sizeof(head));
}

void addedge(int u,int v,int cap,int cost)
{
    edge[tol].to = v;
    edge[tol].cap = cap;
    edge[tol].cost = cost;
    edge[tol].flow = 0;
    edge[tol].next = head[u];
    head[u] = tol++;
    edge[tol].to = u;
    edge[tol].cap = 0;
    edge[tol].cost = -cost;
    edge[tol].flow = 0;
    edge[tol].next = head[v];
    head[v] = tol++;
}

bool spfa(int s,int t)
{
    queue<int>q;
    for(int i = 0; i < N; i++) {
        dis[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    dis[s] = 0;
    vis[s] = true;
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for(int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].to;
            if(edge[i].cap > edge[i].flow &&
                    dis[v] > dis[u] + edge[i].cost ) {
                dis[v] = dis[u] + edge[i].cost;
                pre[v] = i;
                if(!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    if(pre[t] == -1)return false;
    else return true;
}
//返回的是最大流，cost存的是最小费用
int minCostMaxflow(int s,int t,int &cost)
{
    int flow = 0;
    cost = 0;
    while(spfa(s,t)) {
        int Min = INF;
        for(int i = pre[t]; i != -1; i = pre[edge[i^1].to]) {
            if(Min > edge[i].cap - edge[i].flow)
                Min = edge[i].cap - edge[i].flow;
        }
        for(int i = pre[t]; i != -1; i = pre[edge[i^1].to]) {
            edge[i].flow += Min;
            edge[i^1].flow -= Min;
            cost += edge[i].cost * Min;
        }
        flow += Min;
    }
    return flow;
}

int s[MAXN],t[MAXN],w[MAXN],op[MAXN];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int n,m,K,W;
        scanf("%d%d%d%d",&n,&m,&K,&W);
        for (int i=1;i<=m;i++) {
            scanf("%d%d%d%d",&s[i],&t[i],&w[i],&op[i]);
        }
        init(m+m+3);
        for (int i=1;i<=m;i++) {
            for (int j=1;j<=m;j++) if (i!=j) {
                if (t[i]<=s[j]) {
                    if (op[i]!=op[j]) {
                        addedge(m+i,j,1,0);
                    } else {
                        addedge(m+i,j,1,W);
                    }
                }
            }
        }
        int SS=0,S=m+m+1,TT=m+m+2;
        for (int i=1;i<=m;i++) {
            addedge(S,i,1,0);
            addedge(i,m+i,1,-w[i]);
            addedge(m+i,TT,1,0);
        }
        addedge(SS,S,K,0);
        int ans;
        minCostMaxflow(SS,TT,ans);
        printf("%d\n",-ans);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20010;
const int MAXM = 100000;
const int INF = 0x3f3f3f3f;
struct Edge {
    int to,next,cap,flow,cost;
} eg[MAXM];
int head[MAXN],tol;
int pre[MAXN],dis[MAXN];
bool vis[MAXN];
int N;//节点总个数，节点编号从0~N-1

void addedge(int u,int v,int cap,int cost)
{
    eg[tol].to = v;
    eg[tol].cap = cap;
    eg[tol].cost = cost;
    eg[tol].flow = 0;
    eg[tol].next = head[u];
    head[u] = tol++;
    eg[tol].to = u;
    eg[tol].cap = 0;
    eg[tol].cost = -cost;
    eg[tol].flow = 0;
    eg[tol].next = head[v];
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
        for(int i = head[u]; i != -1; i = eg[i].next) {
            int v = eg[i].to;
            if(eg[i].cap > eg[i].flow &&
                    dis[v] > dis[u] + eg[i].cost ) {
                dis[v] = dis[u] + eg[i].cost;
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
        for(int i = pre[t]; i != -1; i = pre[eg[i^1].to]) {
            if(Min > eg[i].cap - eg[i].flow)
                Min = eg[i].cap - eg[i].flow;
        }
        for(int i = pre[t]; i != -1; i = pre[eg[i^1].to]) {
            eg[i].flow += Min;
            eg[i^1].flow -= Min;
            cost += eg[i].cost * Min;
        }
        flow += Min;
    }
    return flow;
}

char s[10010][1000],t[10010][1000];
int c[10010];
map<string,int> mp;
int main()
{
    int C;
    scanf("%d",&C);
    while (C--) {
        int m,n=0;
        scanf("%d",&m);
        mp.clear();
        tol = 0;
        memset(head,-1,sizeof(head));
        for (int i=0;i<m;i++) {
            scanf("%s%s%d",s[i],t[i],&c[i]);
            if (mp.find(s[i])==mp.end()) {
                mp[s[i]]=n++;
            }
            if (mp.find(t[i])==mp.end()) {
                mp[t[i]]=n++;
            }
        }
        int S=mp["Shanghai"];
        for (int i=0;i<m;i++) {
            int u=mp[s[i]],v=mp[t[i]];
            addedge(u,n+v,1,c[i]);
            addedge(v,n+u,1,c[i]);
        }
        for (int i=0;i<n;i++) {
            addedge(n+i,i,1,0);
        }
        int T=n+n;N=T+1;
        addedge(n+mp["Dalian"],T,1,0);
        addedge(n+mp["Xian"],T,1,0);
        int ans=0;
        if (minCostMaxflow(S,T,ans)<2) {
            puts("-1");
            continue;
        }
        printf("%d\n",ans);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
const int MAXM = 1001010;
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

namespace fastIO {
	#define BUF_SIZE 10000000
	//fread -> read
	bool IOerror = 0;
	inline char nc() {
		static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
		if(p1 == pend) {
			p1 = buf;
			pend = buf + fread(buf, 1, BUF_SIZE, stdin);
			if(pend == p1) {
				IOerror = 1;
				return -1;
			}
		}
		return *p1++;
	}
	inline bool blank(char ch) {
		return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
	}
	inline void read(int &x) {
		char ch;
		while(blank(ch = nc()));
		if(IOerror)
			return;
		for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
	}
	#undef BUF_SIZE
};

int main()
{
    int T,n;
    fastIO::read(T);
    while (T--) {
        fastIO::read(n);
        init(n+n+3);
        int S=0,s=n+n+1,t=n+n+2;
        int x,y,z;
        for (int i=1;i<=n;i++) {
            fastIO::read(x);
            addedge(s,i,1,x);
            addedge(n+i,t,1,-x);
            addedge(n+i,i,1,0);
        }
        for (int i=1;i<n;i++) {
            fastIO::read(x);
            fastIO::read(y);
            fastIO::read(z);
            addedge(x,n+y,1,z);
            addedge(y,n+x,1,z);
        }
        int ans;addedge(S,s,1,0);
        minCostMaxflow(S,t,ans);
        ans=max(0,-ans);
        printf("%d\n",ans);
    }
    return 0;
}

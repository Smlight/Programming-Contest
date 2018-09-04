#include <bits/stdc++.h>
using namespace std;

const int MAXN=210,MAXM=2020,MO=1024;
const int INF = 0x3f3f3f3f;
struct Edge {
	int to,next,cap,flow;
} edge[MAXM]; //×¢ÒâÊÇMAXM
int tol;
int head[MAXN];
int gap[MAXN],dep[MAXN],pre[MAXN],cur[MAXN];
void init()
{
	tol = 0;
	memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int w,int rw=0)
{
	edge[tol].to = v;
	edge[tol].cap = w;
	edge[tol].next = head[u];
	edge[tol].flow = 0;
	head[u] = tol++;
	edge[tol].to = u;
	edge[tol].cap = rw;
	edge[tol].next = head[v];
	edge[tol].flow = 0;
	head[v]=tol++;
}
int sap(int start,int end,int N)
{
	memset(gap,0,sizeof(gap));
	memset(dep,0,sizeof(dep));
	memcpy(cur,head,sizeof(head));
	int u = start;
	pre[u] = -1;
	gap[0] = N;
	int ans = 0;
	while(dep[start] < N) {
		if(u == end) {
			int Min = INF;
			for(int i = pre[u]; i != -1; i = pre[edge[i^1].to])
				if(Min > edge[i].cap - edge[i].flow)
					Min = edge[i].cap - edge[i].flow;
			for(int i = pre[u]; i != -1; i = pre[edge[i^1].to]) {
				edge[i].flow += Min;
				edge[i^1].flow -= Min;
			}
			u = start;
			ans += Min;
			continue;
		}
		bool flag = false;
		int v;
		for(int i = cur[u]; i != -1; i = edge[i].next) {
			v = edge[i].to;
			if(edge[i].cap - edge[i].flow && dep[v]+1 == dep[u]) {
				flag = true;
				cur[u] = pre[v] = i;
				break;
			}
		}
		if(flag) {
			u = v;
			continue;
		}
		int Min = N;
		for(int i = head[u]; i != -1; i = edge[i].next)
			if(edge[i].cap - edge[i].flow && dep[edge[i].to] < Min) {
				Min = dep[edge[i].to];
				cur[u] = i;
			}
		gap[dep[u]]--;
		if(!gap[dep[u]])return ans;
		dep[u] = Min+1;
		gap[dep[u]]++;
		if(u != start) u = edge[pre[u]^1].to;
	}
	return ans;
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int n,m,s,t;
        scanf("%d%d",&n,&m);
        scanf("%d%d",&s,&t);
        init();
        for (int i=1;i<=m;i++) {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            addedge(x,y,z*MO+1);
        }
        int ans=sap(s,t,n);
        printf("%d\n",ans%MO);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N=100010;
const int inf=0x3f3f3f3f;
struct Edge {
    int to,next,val;
} eg[N<<1];
int last[N],tot=0;
int T,n,m,k;
struct Node {
    ll len;
    int x,y;
    bool operator <(const Node &r) const {
        return len<r.len;
    }
    bool operator >(const Node &r) const {
        return r<*this;
    }
};
ll dp[N][12];
bool vis[N][12];

void addedge(int x,int y,int z)
{
    eg[tot]={y,last[x],z};
    last[x]=tot++;
}

void dij(int S)
{
	priority_queue< Node,vector<Node>,greater<Node> > q;
	memset(dp,inf,sizeof(dp));
	memset(vis,0,sizeof(vis));
	dp[S][0]=0;
//	vis[S][0]=true;
	q.push({dp[S][0],S,0});
	while (!q.empty()){
		Node cur=q.top();
		q.pop();
		int u=cur.x,y=cur.y;
		if (y>k) continue;
		vis[u][y]=true;
		for (int i=last[u];i!=-1;i=eg[i].next) {
            int v=eg[i].to;
            if (!vis[v][y]) {
                if (cur.len+eg[i].val<dp[v][y]) {
                    dp[v][y]=cur.len+eg[i].val;
                    q.push({dp[v][y],v,y});
                }
            }
            if (!vis[v][y+1]) {
                if (cur.len<dp[v][y+1]) {
                    dp[v][y+1]=cur.len;
                    q.push({dp[v][y+1],v,y+1});
                }
            }
		}
	}
}

int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d%d",&n,&m,&k);
        tot=0;
        memset(last,-1,sizeof(last));
        for (int i=1;i<=m;i++) {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            addedge(a,b,c);
        }
        dij(1);
        printf("%lld\n",*min_element(dp[n],dp[n]+k+1));
    }
    return 0;
}

#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

typedef pair<int,int> PII;
const int N=100010;
struct Edge {
    int go,next,val;
} eg[N*4];
int last[N],vis[N],tot=0;
int d[N];

void adde(int x,int y,int z)
{
    eg[++tot].go=y;
    eg[tot].next=last[x];
    eg[tot].val=z;
    last[x]=tot;
}

void dij(int S)
{
	priority_queue< PII,vector<PII>,greater<PII> > q;
	memset(d,0x3f,sizeof(d));
	memset(vis,0,sizeof(vis));
	d[S]=0; q.push(PII(d[S],S));
	while (!q.empty()){
		PII tmp=q.top();
		q.pop();
		int u=tmp.second;
		if (vis[u]) continue;
		vis[u]=1;
		for (int i=last[u];i;i=eg[i].next) {
            int &v=eg[i].go;
			if (d[v]>d[u]+eg[i].val){
				d[v]=d[u]+eg[i].val;
				q.push(PII(d[v],v));
			}
        }
	}
}

int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF) {
        tot=0;
        memset(last,0,sizeof(last));
        for (int i=1;i<=m;i++) {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            adde(x,y,z);
        }
        int x,k,S=n+1,T=n+2;
        scanf("%d",&k);
        for (int i=1;i<=k;i++) {
            scanf("%d",&x);
            adde(S,x,0);
        }
        scanf("%d",&k);
        for (int i=1;i<=k;i++) {
            scanf("%d",&x);
            adde(x,T,0);
        }
        dij(S);
        printf("%d\n",d[T]);
    }
    return 0;
}

#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

const int N=100010;
const int INF=1<<30;
struct Edge {
    int go,next,val;
} eg[N*4];
int last[N],tot=0;
int n;
int d[N];
int ans[N];

void adde(int x,int y,int z)
{
    eg[++tot].go=y;
    eg[tot].next=last[x];
    eg[tot].val=z;
    last[x]=tot;
}

void dfs(int u,int s,int port)
{
    ans[u]=min(s,port);
    for (int i=last[u];i;i=eg[i].next) {
        int &v=eg[i].go;
        dfs(v,s+eg[i].val,min(s+d[u],port));
    }
}

int main()
{
    while (scanf("%d",&n)!=EOF) {
        tot=0;
        memset(last,0,sizeof(last));
        for (int i=1;i<=n;i++) {
            scanf("%d",d+i);
        }
        for (int i=2;i<=n;i++) {
            int f,w;
            scanf("%d%d",&f,&w);
            adde(f,i,w);
        }
        dfs(1,0,INF);
        for (int i=1;i<=n;i++) {
            printf("%d ",ans[i]);
        }
        puts("");
    }
    return 0;
}

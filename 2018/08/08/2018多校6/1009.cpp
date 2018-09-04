#include <bits/stdc++.h>
using namespace std;
using PII = pair<int,int>;

const int N=100010;
struct Edge {
    int go,next;
} eg[2][N];
int last[2][N],tot;
int label[N],LB;
int in[N],sz[N];

void addedge(int x,int y)
{
    ++in[x];
    eg[0][tot]={y,last[0][x]};
    last[0][x]=tot;
    eg[1][tot]={x,last[1][y]};
    last[1][y]=tot++;
}

void topo(int n)
{
    queue<int> q;
    LB=0;
    memset(label,0,sizeof(label));
    for (int i=1;i<=n;i++) {
        if (in[i]==0) {
            label[i]=++LB;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u=q.front();
        q.pop();
        for (int i=last[1][u];i!=-1;i=eg[1][i].next) {
            int v=eg[1][i].go;
            if (--in[v]==0) {
                label[v]=label[u];
                q.push(v);
            }
        }
    }
}

int dfs(int u)
{
    sz[u]=1;
    for (int i=last[1][u];i!=-1;i=eg[1][i].next) {
        sz[u]+=dfs(eg[1][i].go);
    }
    return sz[u];
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int n;
        scanf("%d",&n);
        vector<PII> ve;
        tot=0;
        char s[11];
        memset(last,-1,sizeof(last));
        memset(in,0,sizeof(in));
        for (int u=1;u<=n;u++) {
            int v;
            scanf("%d%s",&v,s);
            if (s[0]=='w') {
                ve.push_back({u,v});
            } else {
                addedge(u,v);
            }
        }
        topo(n);
        int ans=0;
        for (auto p:ve) {
            int u=p.first,v=p.second;
            if (label[u]==label[v]) {
                ans+=dfs(v);
            }
        }
        printf("0 %d\n",ans);
    }
    return 0;
}
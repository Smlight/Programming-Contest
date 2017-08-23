#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;//点数
const int MAXM = 50010;//边数
struct Edge {
    int fr,to,next;
} eg[MAXM];
int head[MAXN],tot;
int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN];//Belong数组的值是1~scc
int Index,top;
int scc;//强连通分量的个数
bool Instack[MAXN];
int T,n,m;
bool g[MAXN][MAXN];
int in[MAXN];
vector<int> G[MAXN];

void Tarjan(int u)
{
    int v;
    Low[u] = DFN[u] = ++Index;
    Stack[top++] = u;
    Instack[u] = true;
    for(int i = head[u]; i != -1; i = eg[i].next) {
        v = eg[i].to;
        if( !DFN[v] ) {
            Tarjan(v);
            if( Low[u] > Low[v] )Low[u] = Low[v];
        } else if(Instack[v] && Low[u] > DFN[v])
            Low[u] = DFN[v];
    }
    if(Low[u] == DFN[u]) {
        scc++;
        do {
            v = Stack[--top];
            Instack[v] = false;
            Belong[v] = scc;
        } while( v != u);
    }
}

void solve(int N)
{
    memset(DFN,0,sizeof(DFN));
    memset(Instack,false,sizeof(Instack));
    Index = scc = top = 0;
    for(int i = 1; i <= N; i++)
        if(!DFN[i])
            Tarjan(i);
}

void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
}

bool bad()
{
    queue<int> Q;
    for (int i=1;i<=scc;i++) {
        if (!in[i]) {
            Q.push(i);
        }
    }
    while (!Q.empty()) {
        if (Q.size()>1) {
            return true;
        }
        int u=Q.front();
        Q.pop();
        for (int v:G[u]) {
            if (--in[v]==0) {
                Q.push(v);
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        init();
        for (int i=1;i<=m;i++) {
            int x,y;
            scanf("%d%d",&x,&y);
            eg[tot]={x,y,head[x]};
            head[x]=tot++;
        }
        solve(n);
        memset(g,0,sizeof(g));
        memset(in,0,sizeof(in));
        for (int i=1;i<=scc;i++) {
            G[i].clear();
        }
        for (int i=0;i<m;i++) {
            int x=Belong[eg[i].fr];
            int y=Belong[eg[i].to];
            if (x!=y) {
                if (!g[x][y]) {
                    g[x][y]=1;
                    G[x].push_back(y);
                    in[y]++;
                }
            }
        }
        if (bad()) {
            puts("Light my fire!");
        } else {
            puts("I love you my love and our love save us!");
        }
    }
    return 0;
}

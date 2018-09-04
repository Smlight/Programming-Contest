#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10010;//点数
const int MAXM = 100010;//边数
struct Edge {
    int fr,to,next;
} eg[MAXM];
int head[MAXN],tot;
int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN];//Belong数组的值是1~scc
int Index,top;
int scc;//强连通分量的个数
bool Instack[MAXN];
int num[MAXN];//各个强连通分量包含点的个数，数组编号1~scc
//num数组不一定需要，结合实际情况
void addedge(int u,int v)
{
    eg[tot].fr = u;
    eg[tot].to = v;
    eg[tot].next = head[u];
    head[u] = tot++;
}
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
            num[scc]++;
        } while( v != u);
    }
}
void solve(int N)
{
    memset(DFN,0,sizeof(DFN));
    memset(Instack,false,sizeof(Instack));
    memset(num,0,sizeof(num));
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

int in[MAXN],out[MAXN];
int main()
{
    int T,n,m,x,y;
    scanf("%d",&T);
    while (T--) {
        init();
        scanf("%d%d",&n,&m);
        for (int i=1;i<=m;i++) {
            scanf("%d%d",&x,&y);
            addedge(x,y);
        }
        solve(n);
        if (scc==1) {
            puts("0");
        } else {
            for (int i=1;i<=scc;i++) {
                in[i]=out[i]=0;
            }
            for (int i=0;i<tot;i++) {
                int u=Belong[eg[i].fr];
                int v=Belong[eg[i].to];
                if (u!=v) {
                    out[u]++;
                    in[v]++;
                }
            }
            int t1=0,t2=0;
            for (int i=1;i<=scc;i++) {
                if (in[i]==0) t1++;
                if (out[i]==0) t2++;
            }
            printf("%d\n",max(t1,t2));
        }
    }
    return 0;
}

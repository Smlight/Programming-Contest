#include <bits/stdc++.h>
using namespace std;

const int N=1005;
const int K=1e5+5;
int dfn[N], low[N], ncnt;
int S[N],top,cc;
int egws[N];
struct Edge {
    int v,val,next;
} eg[N<<2];
int last[N],tot;
int res[K],tmp[K];
int k;
int len;

void init()
{
    tot=0;top=0;len=0;ncnt=0;
    res[len++]=0;
    memset(last,-1,sizeof(last));
    memset(dfn,0,sizeof(dfn));
}

inline void addedge(int x,int y,int z = 0)
{
    eg[tot].v=y;
    eg[tot].val=z;
    eg[tot].next=last[x];
    last[x]=tot++;
}

struct Node {
    int w,x,y;
    bool operator <(const Node &r) {
        return w<r.w;
    }
} Q[K];

inline void merge(int res[],int a[],int n)
{
    for (int i=0;i<n;i++) {
        Q[i]=(Node){res[0]+a[i],0,i};
    }
    int tail=n,nlen=0;
    make_heap(Q,Q+tail);
    while (nlen<k&&tail) {
        Node p=Q[0];
        pop_heap(Q,Q+tail);
        tail--;
        tmp[nlen++]=p.w;
        if (p.x+1<len) {
            ++p.x;
            p.w=res[p.x]+a[p.y];
            Q[tail++]=p;
            push_heap(Q,Q+tail);
        }
    }
    len=nlen;
    memcpy(res,tmp,sizeof(int)*len);
}

void dfs(int x, int fa)
{
    dfn[x] = low[x] = ++ ncnt;
    for (int i = last[x] ; i != -1 ; i = eg[i].next) {
        int y = eg[i].v;
        if (!dfn[y]) {
            S[top++] = i;
            dfs(y, i ^ 1);
            low[x] = min(low[x], low[y]);
            if (low[y] >= dfn[x]) {
                cc = 0;
                int j;
                do {
                    j = S[--top];
                    egws[cc++] = eg[j].val;
                } while (j != i);
                if (cc>1) merge(res,egws,cc);
            }
        } else if (i != fa && dfn[y] < dfn[x]) {
            low[x] = min(low[x], dfn[y]);
            S[top++] = i;
        }
    }
}

int main()
{
    int n,m,cas=0;
    while (scanf("%d%d",&n,&m)!=EOF) {
        init();
        int sum=0;
        for (int i=1;i<=m;i++) {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            addedge(x,y,z);
            addedge(y,x,z);
            sum+=z;
        }
        scanf("%d",&k);
        dfs(1,-1);
        int ans=0;
        for (int i=0;i<len;i++) {
            ans+=(sum-res[i])*(i+1);
        }
        printf("Case #%d: %u\n",++cas,ans);
    }
    return 0;
}

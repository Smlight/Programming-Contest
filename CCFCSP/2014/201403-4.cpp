#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
const int N=210;
const int INF=1<<29;
struct Circle {
    int x,y,vir;
} c[N];
struct Edge {
    int go,next;
} eg[N*N];
struct Node {
    int u,dis,vnum;
    Node(int a,int b,int c):u(a),dis(b),vnum(c) {}
};
int last[N],tot;
bool vis[N];
PII dis[N];

void addedge(int x,int y)
{
    eg[tot].go=y;
    eg[tot].next=last[x];
    last[x]=tot++;
}

int spfa(int n,int k)
{
    for (int i=1;i<=n;i++) dis[i]=PII(INF,INF);
    dis[1]=PII(0,0);
    queue<int> Q;
    Q.push(1);
    vis[1]=true;
    while (!Q.empty()) {
        int u=Q.front();
        Q.pop();
        vis[u]=false;
        for (int i=last[u];i!=-1;i=eg[i].next) {
            int v=eg[i].go;
            PII p=dis[u];
            p.first+=1;
            if ((p.second+=c[v].vir)>k) continue;
            if (p<dis[v]) {
                dis[v]=p;
                if (!vis[v]) {
                    vis[v]=true;
                    Q.push(v);
                }
            }
        }
    }
    return dis[2].first-1;
}

ll sqr(ll x)
{
    return x*x;
}

int main()
{
    int n,m,k,r;
    scanf("%d%d%d%d",&n,&m,&k,&r);
    for (int i=1;i<=n;i++) {
        scanf("%d%d",&c[i].x,&c[i].y);
        c[i].vir=0;
    }
    for (int i=n+1;i<=n+m;i++) {
        scanf("%d%d",&c[i].x,&c[i].y);
        c[i].vir=1;
    }
    n+=m;
    tot=0;
    memset(last,-1,sizeof(last));
    for (int i=1;i<=n;i++) {
        for (int j=i+1;j<=n;j++) {
            if (sqr(c[i].x-c[j].x)+sqr(c[i].y-c[j].y)<=1LL*r*r) {
                addedge(i,j);
                addedge(j,i);
            }
        }
    }
    printf("%d\n",spfa(n,k));
    return 0;
}

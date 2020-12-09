#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
const int N=100110;
int p[N],ra[N];
const int M=1000005;
struct Edge {
    int u,v,w;
} eg[M];
vector<PII> g[N];

int cmp(const Edge &p1,const Edge &p2)
{
    return p1.w<p2.w;
}

int find(int x)
{
    return p[x]==x?x:p[x]=find(p[x]);
}

int Union(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return 0;
    if(ra[x]>ra[y]) {
        p[y]=x;
    } else {
        if(ra[x]==ra[y]) ra[y]++;
        p[x]=y;
    }
    return 1;
}

ll Kruskal(int kn,int km)
{
    ll rnt=0;
    for(int i=1;i<=kn;i++) {
         p[i]=i;
         ra[i]=0;
         g[i].clear();
    }
    sort(eg+1,eg+km+1,cmp);
    for(int i=1;i<=km;i++) {
        if(Union(eg[i].u,eg[i].v)) {
            rnt+=eg[i].w;
            g[eg[i].u].push_back(PII(eg[i].v,eg[i].w));
            g[eg[i].v].push_back(PII(eg[i].u,eg[i].w));
        }
    }
    return rnt;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++) {
        scanf("%d%d%d",&eg[i].u,&eg[i].v,&eg[i].w);
    }
    printf("%lld\n",Kruskal(n,m));
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=510;
const ll INF=1e18;
ll g0[N][N],g1[N][N];
ll dis0[N],dis1[N];
bool vis[N];
int que[N];
int n,m;

ll spfa(int S)
{
    int front=0,rear=0;
    for (int i=1;i<=n;i++) {
        vis[i]=0;
        dis0[i]=dis1[i]=INF;
    }
    vis[S]=true;
    dis0[S]=dis1[S]=0;
    que[rear++]=S;
    while (front!=rear) {
        int u=que[front++];
        if (front>=N) front=0;
        vis[u]=false;
        for (int v=1;v<=n;v++) {
            ll tmp=min(dis0[u],dis1[u]);
            if (g0[u][v]<INF&&dis0[v]>tmp+g0[u][v]) {
                dis0[v]=tmp+g0[u][v];
                if (!vis[v]) {
                    vis[v]=true;
                    que[rear++]=v;
                    if (rear>=N) rear=0;
                }
            }
            if (g1[u][v]<INF&&dis1[v]>dis0[u]+g1[u][v]) {
                dis1[v]=dis0[u]+g1[u][v];
                if (!vis[v]) {
                    vis[v]=true;
                    que[rear++]=v;
                    if (rear>=N) rear=0;
                }
            }
        }
    }
    return min(dis0[n],dis1[n]);
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            g0[i][j]=g1[i][j]=INF;
        }
    }
    for (int i=1;i<=m;i++) {
        int t,a,b,c;
        scanf("%d%d%d%d",&t,&a,&b,&c);
        if (t&&g1[a][b]>c) g1[a][b]=g1[b][a]=c;
        if (!t&&g0[a][b]>c) g0[a][b]=g0[b][a]=c;
    }
    for (int k=1;k<=n;k++) {
        for (int i=1;i<=n;i++) {
            if (g1[i][k]==INF) continue;
            for (int j=i+1;j<=n;j++) {
                if (g1[i][j]>g1[i][k]+g1[k][j]) {
                    g1[i][j]=g1[j][i]=g1[i][k]+g1[k][j];
                }
            }
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (g1[i][j]<INF) g1[i][j]*=g1[i][j];
        }
    }
    printf("%lld\n",spfa(1));
    return 0;
}

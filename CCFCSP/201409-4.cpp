#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
const int INF=0x3f3f3f3f;
const int N=1010;
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};
int dis[N][N],cnt[N][N];

int main()
{
    int n,m,k,d;
    scanf("%d%d%d%d",&n,&m,&k,&d);
    memset(dis,INF,sizeof(dis));
    queue<PII> Q;
    for (int i=1;i<=m;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        dis[x][y]=0;
        Q.push(PII(x,y));
    }
    for (int i=1;i<=k;i++) {
        int x,y,c;
        scanf("%d%d%d",&x,&y,&c);
        cnt[x][y]+=c;
    }
    for (int i=1;i<=d;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        dis[x][y]=-1;
    }
    long long ans=0;
    while (!Q.empty()) {
        PII p=Q.front();
        Q.pop();
        int x=p.first,y=p.second;
        ans+=1LL*cnt[x][y]*dis[x][y];
        for (int i=0;i<4;i++) {
            int xx=x+dx[i],yy=y+dy[i];
            if (xx<1||xx>n||yy<1||yy>n||dis[xx][yy]!=INF) continue;
            dis[xx][yy]=dis[x][y]+1;
            Q.push(PII(xx,yy));
        }
    }
    printf("%lld\n",ans);
    return 0;
}

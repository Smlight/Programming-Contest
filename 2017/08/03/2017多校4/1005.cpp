#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF=1LL<<60;
struct Node {
    int x,r;
    ll s;
    bool operator >(const Node &R) const {
        return s>R.s;
    }
};
ll dis[4][60005];
priority_queue<Node,vector<Node>,greater<Node>> q;

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        ll k;
        int g[4];
        scanf("%lld%d%d%d%d",&k,&g[0],&g[1],&g[2],&g[3]);
        int m=min(g[0],g[1])*2;
        for (int i=0;i<4;i++) {
            for (int j=0;j<m;j++) {
                dis[i][j]=INF;
            }
        }
        q.push({1,0,0});
        while (!q.empty()) {
            Node p=q.top();
            q.pop();
            if (dis[p.x][p.r]<p.s) continue;
            int xx=(p.x+1)%4,rr=(p.r+g[p.x])%m,ss=p.s+g[p.x];
            if (ss<dis[xx][rr]) {
                dis[xx][rr]=ss;
                q.push({xx,rr,ss});
            }
            xx=(p.x+3)%4;rr=(p.r+g[xx])%m;ss=p.s+g[xx];
            if (ss<dis[xx][rr]) {
                dis[xx][rr]=ss;
                q.push({xx,rr,ss});
            }
        }
        ll ans=INF;
        for (int i=0;i<m;i++) {
            if (dis[1][i]>=k) {
                ans=min(ans,dis[1][i]);
            } else {
                ll t=(k-dis[1][i])/m*m+dis[1][i];
                if (t<k) t+=m;
                ans=min(ans,t);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

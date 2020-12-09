#include <bits/stdc++.h>
using namespace std;

const int N=20010;
const int INF=0x3f3f3f3f;
vector<int> E[N];
int dis[N];

void bfs(int S)
{
    queue<int> Q;
    memset(dis,INF,sizeof(dis));
    Q.push(S);
    dis[S]=0;
    while (!Q.empty()) {
        int u=Q.front();
        Q.pop();
        for (int i=0;i<(int)E[u].size();i++) {
            int v=E[u][i];
            if (dis[v]!=INF) continue;
            dis[v]=dis[u]+1;
            Q.push(v);
        }
    }
}

int main()
{
    int n,m,f;
    scanf("%d%d",&n,&m);
    n+=m;
    for (int i=2;i<=n;i++) {
        scanf("%d",&f);
        E[f].push_back(i);
        E[i].push_back(f);
    }
    bfs(1);
    int u=max_element(dis+1,dis+n+1)-dis;
    bfs(u);
    printf("%d\n",*max_element(dis+1,dis+n+1));
    return 0;
}

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

const int N=105,INF=0x3f3f3f3f;
int mp[N][N],cost[N][N];

int main()
{
    int T,cas=0;
    scanf("%d",&T);
    while (T--) {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                mp[i][j]=INF;
            }
        }
        int ans=0;
        for (int i=1;i<=m;i++) {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            if (mp[x][y]!=INF) {
                ans++;
            }
            mp[x][y]=mp[y][x]=min(mp[x][y],z);
        }
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                cost[i][j]=mp[i][j];
            }
        }
        for (int k=1;k<=n;k++) {
            for (int i=1;i<=n;i++) {
                for (int j=1;j<=n;j++) {
                    if (cost[i][k]+cost[k][j]<=cost[i][j]) {
                        cost[i][j]=cost[i][k]+cost[k][j];
                        if (mp[i][j]!=INF&&mp[i][j]!=-1) {
                            mp[i][j]=mp[j][i]=-1;
                            ans++;
                        }
                    }
                }
            }
        }
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}

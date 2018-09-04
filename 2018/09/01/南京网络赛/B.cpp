#include <bits/stdc++.h>
using namespace std;

const int N=100010;
const int M=110;
int bad[M];
vector<int> pos[N];

int main()
{
    int T,cas=0;
    scanf("%d",&T);
    while (T--) {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        memset(bad,0,sizeof(bad));
        for (int i=1;i<=k;i++) {
            int x,y;
            scanf("%d%d",&x,&y);
            pos[x].push_back(y);
        }
        long long ans=0;
        for (int i=1;i<=n;i++) {
            for (auto p:pos[i]) {
                bad[p]=i;
            }
            for (int j=1;j<=m;j++) {
                int mx=0;
                for (int k=j;k<=m;k++) {
                    mx=max(mx,bad[k]);
                    if (mx==i) break;
                    ans+=(i-mx);
                }
            }
        }
        printf("Case #%d: %lld\n",++cas,ans);
        for (int i=1;i<=n;i++) {
            pos[i].clear();
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
set<PII> ss;
vector<int> le[55],ri[55];

int main()
{
    int T,n,m,x,y;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=50;i++) {
            le[i].clear();
            ri[i].clear();
        }
        for (int i=1;i<=n;i++) {
            scanf("%d%d",&x,&y);
            le[y].push_back(x);
        }
        for (int i=1;i<=m;i++) {
            scanf("%d%d",&x,&y);
            ri[x].push_back(y);
        }
        ss.clear();
        for (int i=1;i<=50;i++) {
            for (int x:le[i]) {
                for (int y:ri[i]) {
                    ss.insert(PII(x,y));
                }
            }
        }
        for (auto &p:ss) {
            printf("%d %d\n",p.first,p.second);
        }
        puts("");
    }
    return 0;
}

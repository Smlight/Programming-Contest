#include <bits/stdc++.h>
using namespace std;

int co[550];

int main()
{
    int n,m,q;
    while (scanf("%d%d",&n,&m)!=EOF) {
        memset(co,0,sizeof(co));
        for (int i=1;i<=n;i++) {
            int r,b,p;
            scanf("%d",&r);
            int pmx1=r,pmx2=r,b1=m+1,b2=m+1;
            while (true) {
                scanf("%d",&b);
                if (b==-1) break;
                scanf("%d",&p);
                if (p>pmx1||(p==pmx1&&b<b1)) {
                    pmx2=pmx1;
                    b2=b1;
                    pmx1=p;
                    b1=b;
                } else if (p>pmx2||(p==pmx2&&b<b2)) {
                    pmx2=p;
                    b2=b;
                }
            }
            if (b1<=m) {
                int tmp=min(pmx1,(int)(pmx2*1.1));
                co[b1]+=tmp;
            }
        }
        scanf("%d",&q);
        for (int i=1;i<=q;i++) {
            int k;
            scanf("%d",&k);
            printf("%d\n",co[k]);
        }
    }
    return 0;
}

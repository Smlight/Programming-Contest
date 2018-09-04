#include <bits/stdc++.h>
using namespace std;

const int N=110,INF=1<<29;
int p[N],ctr[N];

int main()
{
    int n,m,q;
    while (scanf("%d%d",&n,&m)!=EOF) {
        for (int i=0;i<n;i++) {
            scanf("%d",&p[i]);
        }
        scanf("%d",&q);
        memset(ctr,0,sizeof(ctr));
        for (int i=0;i<q;i++) {
            int x;
            scanf("%d",&x);
            ctr[x]++;
        }
        int ans=INF,x,y;
        for (int i=0;i<n;i++) {
            if (ctr[i]) continue;
            int ny=-1,cnt=1;
            for (int j=i+1;j<n;j++) {
                if (!ctr[j]) {
                    ++cnt;
                    if (ny==-1||p[ny]>p[j]) {
                        ny=j;
                    }
                    if (cnt==m) {
                        if (p[i]+p[ny]<ans) {
                            ans=p[i]+p[ny];
                            x=i;y=ny;
                        }
                        break;
                    }
                }
            }
        }
        printf("%d %d\n",x,y);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int M=1e4+5;
ll b[M];
int ans[60];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=0;i<=m;i++) {
            scanf("%lld",&b[i]);
        }
        int p=1,tot=0;
        for (int i=1;i<=n;i++) {
            while (!b[p]) p++;
            for (int j=p;j<=m;j++) {
                b[j]-=b[j-p];
            }
            ans[++tot]=p;
        }
        for (int i=1;i<=tot;i++) {
            printf("%d%c",ans[i],(i==tot)?'\n':' ');
        }
    }
    return 0;
}

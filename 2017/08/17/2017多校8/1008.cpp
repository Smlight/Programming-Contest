#include <bits/stdc++.h>
using namespace std;

int a[1010];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int n,k;
        scanf("%d%d",&n,&k);
        for (int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
        }
        int nn=0,mm=0;
        char s[10];
        for (int i=1;i<=n;i++) {
            scanf("%s",s);
            if (s[0]!='D') {
                mm+=a[i];
            }
            if (s[0]!='L') {
                nn-=a[i];
            }
        }
        if (nn<=k&&k<=mm) {
            puts("yes");
        } else {
            puts("no");
        }
    }
    return 0;
}

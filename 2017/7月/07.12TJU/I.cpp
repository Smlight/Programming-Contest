#include <bits/stdc++.h>
using namespace std;

const double INF=1<<30;

int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        int mm=INF,ans=0;
        for (int i=0;i<n;i++) {
            int x;
            scanf("%d",&x);
            mm=min(mm,x);
            ans=max(ans,x-mm);
        }
        printf("%d\n",ans);
    }
    return 0;
}

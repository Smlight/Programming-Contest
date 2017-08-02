#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF) {
        int ans=0;
        for (int i=1;i<=n;i++) {
            int t;
            scanf("%d",&t);
            if (t<=35) ++ans;
        }
        printf("%d\n",ans);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N=110;
int a[N];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i]=1+y;
        }
        sort(a+1,a+n+1);
        long long now=1;
        int ans=0;
        for (int i=1;i<=n;i++) {
            now*=a[i];
            if (now<=m) {
                ans=i;
            } else {
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int a[N];

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
        sort(a+1,a+n+1);
        int ans=1;
        int i=n-1;
        while (i>=1&&a[i+1]-a[i]<=k) i--,ans++;
        printf("%d\n",ans);
    }
    return 0;
}

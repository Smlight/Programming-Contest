#include <bits/stdc++.h>
using namespace std;

int a[1005];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%d",a+i);
    }
    int ans=0;
    for (int i=1;i<=n;i++) {
        for (int j=i+1;j<=n;j++) {
            if (abs(a[i]-a[j])==1) ++ans;
        }
    }
    printf("%d\n",ans);
    return 0;
}

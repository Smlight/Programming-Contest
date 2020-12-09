#include <bits/stdc++.h>
using namespace std;

const int N=1010;
int n;
int a[N];

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    int ans=1000000;
    for (int i=1;i<=n;i++) {
        for (int j=i+1;j<=n;j++) {
            ans=min(ans,abs(a[i]-a[j]));
        }
    }
    printf("%d\n",ans);
    return 0;
}

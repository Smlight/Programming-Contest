#include <bits/stdc++.h>
using namespace std;

const int N=1010;
int a[N];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    int ans=0;
    for (int i=2;i<=n-1;i++) {
        if (a[i-1]>a[i]&&a[i+1]>a[i]) ++ans;
        if (a[i-1]<a[i]&&a[i+1]<a[i]) ++ans;
    }
    printf("%d\n",ans);
    return 0;
}

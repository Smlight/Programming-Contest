#include <bits/stdc++.h>
using namespace std;

const int M=1111;
int a[1111];

int main()
{
    int n,x,ans=0;
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf("%d",&x);
        x=abs(x);
        a[x]++;
    }
    for (int i=0;i<M;i++) {
        if (a[i]==2) ++ans;
    }
    printf("%d\n",ans);
    return 0;
}

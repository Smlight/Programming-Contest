#include <bits/stdc++.h>
using namespace std;

const int N=1010,INF=1<<30;
int a[N];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf("%d",a+i);
    }
    int ans=-1;
    for (int i=0;i<n;i++) {
        int mn=INF;
        for (int j=i;j<n;j++) {
            mn=min(mn,a[j]);
            ans=max((j-i+1)*mn,ans);
        }
    }
    printf("%d\n",ans);
    return 0;
}

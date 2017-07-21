#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

const int N=10010;
int a[N],b[N];

int main()
{
    int T,cas=0;
    scanf("%d",&T);
    while (T--) {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++) {
            scanf("%d",a+i);
        }
        for (int i=1;i<=n;i++) {
            scanf("%d",b+i);
        }
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        double ans=0;
        for (int i=1;i<=n;i++) {
            int p=upper_bound(b+1,b+n+1,a[i])-b-1;
            ans+=1.0*p/n;
        }
        printf("Case %d: %.2f\n",++cas,ans);
    }
    return 0;
}

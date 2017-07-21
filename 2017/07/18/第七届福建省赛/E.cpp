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
        int ans=0;
        for (int i=1;i<=n;i++) {
            scanf("%d",a+i);
        }
        for (int i=1;i<=n;i++) {
            scanf("%d",b+i);
            ans+=(a[i]+b[i]>10);
        }
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}

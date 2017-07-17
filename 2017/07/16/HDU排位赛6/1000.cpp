#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int n,x,y,z,a,b;
        scanf("%d%d%d%d%d%d",&n,&x,&y,&z,&a,&b);
        int ans=min(x+y+a*(z-1),n+n+(n-x)+(n-y)+b*(z-1));
        printf("%d\n",ans);
    }
    return 0;
}

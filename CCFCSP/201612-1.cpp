#include <bits/stdc++.h>
using namespace std;

int c[1010];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        int x;
        scanf("%d",&x);
        ++c[x];
    }
    int pre=0;
    bool good=false;
    for (int i=1;i<=1000;i++) if (c[i]) {
        if (pre==n-pre-c[i]) {
            good=true;
            printf("%d\n",i);
            break;
        }
        pre+=c[i];
    }
    if (!good) puts("-1");
    return 0;
}

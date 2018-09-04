#include <bits/stdc++.h>
using namespace std;

const double PI=acos(-1);

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int a,b;
        scanf("%d%d",&a,&b);
        double ans=PI*a+2.0*b;
        ans=floor(ans*1000000)/1000000;
        printf("%.6f\n",ans);
    }
    return 0;
}

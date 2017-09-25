#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
int a[100];
double p[9][9];

int main()
{
    for (int i=1;i<=4;i++) {
        for (int j=1;j<=4;j++) {
            scanf("%lf",&p[i][j]);
        }
    }
    scanf("\n");
    for (int i=1;i<=2;i++) {
        double ans=1;
        for (int j=1;;j++) {
            char c;
            scanf("%d%c",&a[j],&c);
            if (j>1) ans*=p[a[j-1]][a[j]];
            if (c!=' ') break;
        }
        printf("%.8f\n",ans);
    }
    for (int i=1;i<=2;i++) {
        int x;
        scanf("%d",&x);
        printf("%.8f\n",1.0/(1.0-p[x][x]));
    }
    return 0;
}

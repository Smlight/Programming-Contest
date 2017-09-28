#include <bits/stdc++.h>
using namespace std;

int g[666][666];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int V;
        scanf("%d",&V);
        int n=V/2,ans=0;
        for (int i=1;i<=n;i++) {
            for (int j=i+1;j<=n;j++) {
                g[i][j]=g[j][i]=1;
            }
        }
        for (int i=n+1;i<=V;i++) {
            for (int j=i+1;j<=V;j++) {
                g[i][j]=g[j][i]=1;
            }
        }
        for (int i=1;i<=n;i++) {
            for (int j=n+1;j<=V;j++) {
                g[i][j]=g[j][i]=2;
            }
        }
        if (V&1) {
            ans=n*(n-1)*(n-2)/6+(n+1)*n*(n-1)/6-n/2;
            if (n&1) {
                for (int i=1;i<=n-1;i++) {
                    g[i][i+n]=g[i+n][i]=1;
                }
                for (int i=n+1;i<=n+n-2;i+=2) {
                    g[i][i+1]=g[i+1][i]=2;
                }
            } else {
                for (int i=1;i<=n;i++) {
                    g[i][i+n]=g[i+n][i]=1;
                }
                for (int i=n+1;i<=n+n-1;i+=2) {
                    g[i][i+1]=g[i+1][i]=2;
                }
            }
        } else {
            ans=n*(n-1)*(n-2)/3;
        }
        printf("%d\n",ans);
        for (int i=1;i<=V;i++) {
            for (int j=1;j<=V;j++) {
                printf("%d%c",g[i][j]," \n"[j==V]);
            }
        }
    }
    return 0;
}

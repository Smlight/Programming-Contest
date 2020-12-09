#include <bits/stdc++.h>
using namespace std;

int a[1111][1111];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            scanf("%d",&a[i][j]);
        }
    }
    for (int j=m;j>=1;j--) {
        for (int i=1;i<=n;i++) {
            printf("%d%c",a[i][j]," \n"[i==n]);
        }
    }
    return 0;
}

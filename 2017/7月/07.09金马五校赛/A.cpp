#include <bits/stdc++.h>
using namespace std;

int mp[120][120],c[120];

int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF) {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                scanf("%d",&mp[i][j]);
            }
        }
        for (int j=1;j<=m;j++) {
            c[j]=0;
            for (int i=1;i<=n;i++) {
                c[j]+=mp[i][j];
            }
        }
        for (int j=1;j<=m;j++) {
            printf("%d%c",c[j],j==m?'\n':' ');
        }
    }
    return 0;
}

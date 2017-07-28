#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll f[15][250];

int main()
{
    f[1][1]=f[1][2]=1;
    for (int i=3;i<250;i++) {
        f[1][i]=f[1][i-1]+2*f[1][i-2];
    }
    int n;
    while (scanf("%d",&n)!=EOF) {
        for (int i=2;i<=10;i++) {
            for (int j=1;j<=250-n;j++) {
                f[i][j]=0;
                for (int k=j;k<=j+n-1;k++) {
                    f[i][j]+=f[i-1][k];
                }
            }
        }
        for (int i=1;i<=10;i++) {
            for (int j=1;j<=5;j++) {
                printf("%20lld",f[i][j]);
            }
            puts("");
        }
    }
    return 0;
}

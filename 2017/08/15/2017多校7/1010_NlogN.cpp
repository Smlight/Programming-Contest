#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int a[N];

int main()
{
    int T,n,m;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) {
            scanf("%d",a+i);
        }
        int k=1;m--;
        while (k<n) {
            if ((m&1)==0) {
                for (int i=n;i>k;i--) {
                    a[i]^=a[i-k];
                }
            }
            m>>=1;k<<=1;
        }
        for (int i=1;i<=n;i++) {
            printf("%d%c",a[i]," \n"[i==n]);
        }
    }
    return 0;
}

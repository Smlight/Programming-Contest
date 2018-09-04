#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int T;
int n,m,MO;

int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d%d",&n,&m,&MO);
        ll ans=1;
        for (int i=n*m;i>(n+m-1);i--) {
            ans=ans*i%MO;
        }
        for (int i=1;i<=n;i++) {
            ans=ans*i%MO;
        }
        for (int i=1;i<=m;i++) {
            ans=ans*i%MO;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
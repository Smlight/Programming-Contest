#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        ll n,m;
        scanf("%lld%lld",&n,&m);
        if (m>=n*(n-1)/2) {
            printf("%lld\n",n*(n-1));
        } else if (m>=n-1) {
            ll rm=m-(n-1);
            printf("%lld\n",((n-1)*(n-1)-rm)*2);
        } else {
            ll lar=n*(n-1)/2-m*(m+1)/2;
            printf("%lld\n",(m*m+lar*n)*2);
        }
    }
    return 0;
}

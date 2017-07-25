#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n,k;
    int cas=0;
    while (scanf("%lld%lld",&n,&k)!=EOF) {
        int ans=-1;
        if (k<=n) {
            ans=k;
        } else {
            k-=n;
            int x=(k-1)/(n-1)+1;
            if (x&1) {
                if (k%(n-1)==0) {
                    ans=n-1;
                } else {
                    ans=k%(n-1);
                }
            } else {
                if (k%(n-1)==0) {
                    ans=n;
                } else {
                    ans=k%(n-1);
                }
            }
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}

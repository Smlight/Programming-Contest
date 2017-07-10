#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MO=1e9+7;

int fpow(ll x,int n)
{
    ll res=1;
    while (n) {
        if (n&1) {
            res=res*x%MO;
        }
        x=x*x%MO;
        n>>=1;
    }
    return res;
}

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF) {
        int ans=(fpow(2,n)+MO-1)%MO;
        printf("%d\n",ans);
    }
    return 0;
}

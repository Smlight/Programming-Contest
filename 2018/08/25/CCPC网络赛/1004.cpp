#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        ll n, a;
        scanf("%lld%lld",&n,&a);
        if(n > 2 || n == 0) puts("-1 -1");
        if(n == 2) {
            if(a & 1) {
                ll t = a * a;
                ll x = (t - 1) / 2;
                printf("%lld %lld\n",x,x+1);
            } else {
                ll t = (a / 2) * (a / 2);
                printf("%lld %lld\n",t-1,t+1);
            }
        } else if(n == 1) {
            printf("1 %lld\n",a+1);
        }
    }
    return 0;
}
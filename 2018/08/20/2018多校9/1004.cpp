#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll a, b, c, d, e, f;
    int T;
    cin >> T;
    while(T--) {
        cin >> a >> b >> c >> d >> e >> f;
        ll base = d + e + f;
        ll u = a * e - a * f + b * f - b * d + c * d - c * e;
        ll g = __gcd(base, abs(u));
        base/=g;u/=g;
        if (u==0) {
            puts("0");
        } else if (base==1) {
            printf("%lld\n",u);
        } else {
            printf("%lld/%lld\n",u,base);
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MO = 998244353;

ll fast_pow(ll x, ll e) {
    if(e == 0) return 1;
    if(e == 1) return x % MO;
    ll tmp = fast_pow(x, e / 2);
    if(e & 1) return tmp * tmp % MO * x % MO;
    else return tmp * tmp % MO;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        ll a, b, c, d;
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        ll c1 = fast_pow(2, c) * fast_pow(2, a) % MO * (b + d + 1) % MO;
        ll c2 = fast_pow(2, a) * fast_pow(2, b) % MO;
        ll dd = fast_pow(2, a) * (b + 1) % MO;
        ll ans = c1 + c2 - dd;
        ans %= MO;
        if(ans < 0) ans += MO;
        printf("%lld\n", ans);
    }
    return 0;
}
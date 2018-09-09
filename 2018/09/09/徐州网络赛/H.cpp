#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100005;
ll bit1[N], bit2[N];
int n;
void add(ll* bit, int i, ll x) {
    while(i <= n) {
        bit[i] += x;
        i += (-i) & i;
    }
}

ll sum(ll* bit, int i) {
    ll ret = 0;
    while(i) {
        ret += bit[i];
        i -= (-i) & i;
    }
    return ret;
}
ll a[N];
int main() {
    int q;
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; ++i) {
        scanf("%lld", a + i);
        add(bit1, i, a[i]);
        add(bit2, i, (ll)i * a[i]);
    }
    while(q--) {
        int t, l, r;
        scanf("%d %d %d", &t, &l, &r);
        if(t == 1) {
            ll L = (r - l + 1);
            ll ans = (L + l) * (sum(bit1, r) - sum(bit1, l - 1)) - (sum(bit2, r) - sum(bit2, l - 1));
            printf("%lld\n", ans);
        } else {
            ll dt = r - a[l];
            a[l] = r;
            add(bit1, l, dt);
            add(bit2, l, l * dt);
        }
    }
    return 0;
}
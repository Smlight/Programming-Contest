#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[105];

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        if(n == 0) {
            puts("*");
            break;
        }
        memset(a, 0, sizeof(a));
        int l, r, c;
        for(int i = 0; i < n; ++i) {
            scanf("%d %d %d", &l, &r, &c);
            if(l > r) swap(l, r);
            for(int j = l; j < r; ++j) {
                a[j] += c;
            }
        }
        printf("%lld\n", *max_element(a, a + 105));
    }
    return 0;
}

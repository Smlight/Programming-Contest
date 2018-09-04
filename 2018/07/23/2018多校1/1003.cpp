#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PLL = pair<ll, ll>;
const int N = 1005 * 3;
PLL a[N];
int idx[N];
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n * 3; ++i) {
            scanf("%lld %lld", &a[i].first, &a[i].second);
        }
        for(int i = 0; i < N; ++i) idx[i] = i;
        sort(idx, idx + n * 3, [&](int l, int r) { return a[l] < a[r]; });
        for(int i = 0; i < n; ++i) {
            printf("%d %d %d\n", 1 + idx[i * 3], 1 + idx[i * 3 + 1], 1 + idx[i * 3 + 2]);
        }
    }
    return 0;
}
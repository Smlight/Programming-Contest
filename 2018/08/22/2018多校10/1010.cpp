#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
using ll = long long;
constexpr ll INF = 1LL << 60;
ll sa[N], sb[N], x[N][5], y[N][5];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        for(int i = 0; i < n; ++i) {
            scanf("%lld", sa + i);
            for(int j = 0; j < k; ++j) scanf("%lld", x[i] + j);
        }
        for(int i = 0; i < m; ++i) {
            scanf("%lld", sb + i);
            for(int j = 0; j < k; ++j) scanf("%lld", y[i] + j);
        }
        ll ans = -INF;
        for(int st = 0; st < (1 << k); ++st) {
            ll mxi = -INF, mxj = -INF;
            for(int i = 0; i < n; ++i) {
                ll tmp = sa[i];
                for(int j = 0; j < k; ++j) {
                    if(st >> j & 1) tmp += x[i][j];
                    else tmp -= x[i][j];
                }
                mxi = max(tmp, mxi);
            }
            for(int i = 0; i < m; ++i) {
                ll tmp = sb[i];
                for(int j = 0; j < k; ++j) {
                    if(st >> j & 1) tmp -= y[i][j];
                    else tmp += y[i][j];
                }
                mxj = max(tmp, mxj);
            }
            ans = max(ans, mxi + mxj);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
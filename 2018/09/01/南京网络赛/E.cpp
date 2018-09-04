#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct In {
    int a, b, st;
} p[25];
ll dp[2][1 << 20];
const ll INF = 1LL << 60;
vector<int> st[21];
ll calc(int n)
{
    ll ans = 0;
    fill(dp[0], dp[0] + (1 << n), -INF);
    dp[0][0] = 0;
    for(int i = 1; i <= n; ++i) {
        fill(dp[i & 1], dp[i & 1] + (1 << n), -INF);
        for(auto j : st[i - 1]) {
            for(int k = 0; k < n; ++k) {
                if((j >> k & 1) == 0 && (p[k].st & j) == p[k].st) {
                    dp[i & 1][j | (1 << k)] = max(dp[i & 1][j | (1 << k)], dp[(i - 1) & 1][j] + (ll)i * p[k].a + p[k].b);
                    ans = max(ans, dp[i & 1][j | (1 << k)]);
                }
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &p[i].a, &p[i].b);
        p[i].st = 0;
        int s;
        scanf("%d", &s);
        while(s--) {
            int x;
            scanf("%d", &x);
            --x;
            p[i].st |= (1 << x);
        }
    }
//    for(int i = 0; i < n; ++i) {
//        printf("%d\n", p[i].st);
//    }
    for(int i = 0; i < (1 << n); ++i) {
        int ct = __builtin_popcount(i);
        st[ct].push_back(i);
    }
    printf("%lld\n", calc(n));
    return 0;
}

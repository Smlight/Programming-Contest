#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct ST {
    //1 base, query O(1)
    ll dp[50005][20];
    int n;

    void make(int _n, ll* arr) {
        n = _n;
        for(int i = 1; i <= n; ++i) {
            dp[i][0] = arr[i];
        }
        for(int j = 1; (1 << j) <= n; ++j) {
            for(int i = 1; (i + (1 << (j - 1))) <= n; ++i) {
                dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    ll query(int l, int r) {
        int k = 31 - __builtin_clz(r - l + 1);
        return max(dp[l][k], dp[r - (1 << k) + 1][k]);
    }
} st;

int a[10005], idx[10005];
ll s[40005];
const ll INF = 1LL << 60;

int n, m, k;
ll tot;

int gen(int p) {
    int c = 1;
    int pp = p - 1;
    while(idx[pp + 1] == -1) {
        s[c++] = a[pp + 1];
        idx[pp + 1] = 1;
        pp += k;
        pp %= n;
    }
    return c - 1;
}

ll gao(int cnt) {
    ll mx = 0;
    for(int i = cnt + 1; i <= cnt * 3; ++i) {
        s[i] = s[(i - 1) % cnt + 1];
    }

    for(int i = 1; i <= cnt * 3; ++i) {
        s[i] += s[i - 1];
    }
    st.make(cnt * 3, s);

    int fm = min(m, cnt);
    for(int i = 1; i <= cnt; ++i) {
        mx = max(st.query(i, i + fm - 1) - s[i - 1], mx);
    }
    if(m > cnt) {
        int sm = m % cnt, le = m / cnt;
        if(sm != 0) {
            for(int i = 1; i <= cnt; ++i) {
                mx = max(st.query(i, i + sm - 1) - s[i - 1] + le * s[cnt], mx);
            }
        }
    }
    if(m >= 2 * cnt) {
        int tm = m % cnt + cnt;
        int le = m / cnt - 1;
        if(tm != 0) {
            for(int i = 1; i <= cnt; ++i) {
                mx = max(st.query(i, i + tm - 1) - s[i - 1] + le * s[cnt], mx);
            }
        }
    }
    return mx;
}

ll solve() {
    ll ans = 0;
    memset(idx, 0xff, sizeof(idx));
    for(int i = 1; i <= n; ++i) {
        if(idx[i] == -1) {
            ans = max(ans, gao(gen(i)));
        }
    }
    return ans;
}

int main() {
    int T, cas = 1;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %lld %d %d", &n, &tot, &m, &k);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
        }

        ll le = tot - solve();
        if(le < 0) le = 0;
        printf("Case #%d: %lld\n", cas++, le);
    }
    return 0;
}
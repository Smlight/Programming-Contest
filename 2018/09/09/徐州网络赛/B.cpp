#include <bits/stdc++.h>
using namespace std;

int dp[1005][205];
int a[1005], b[1005], c[1005];
const int INF = 0x3f3f3f3f;
int n, m, k, l;
int dfs(int i, int s) {
    if(dp[i][s + 100] != INF) return dp[i][s + 100];
    if(i == n + 1) return s;
    if(i & 1) {
        int ans = -INF;
        if(a[i] != 0) ans = max(ans, dfs(i + 1, min(s + a[i], 100)));
        if(b[i] != 0) ans = max(ans, dfs(i + 1, max(s - b[i], -100)));
        if(c[i] != 0) ans = max(ans, dfs(i + 1, -s));
        return dp[i][s + 100] = ans;
    } else {
        int ans = INF;
        if(a[i] != 0) ans = min(ans, dfs(i + 1, min(s + a[i], 100)));
        if(b[i] != 0) ans = min(ans, dfs(i + 1, max(s - b[i], -100)));
        if(c[i] != 0) ans = min(ans, dfs(i + 1, -s));
        return dp[i][s + 100] = ans;
    }
}
int main() {
    scanf("%d %d %d %d", &n, &m, &k, &l);
    for(int i = 1; i <= n; ++i) {
        scanf("%d %d %d", a + i, b + i, c + i);
    }
    memset(dp, 0x3f, sizeof(dp));
    int sc = dfs(1, m);
//    printf("%d\n", sc);
    if(sc >= k) puts("Good Ending");
    else if(sc <= l) puts("Bad Ending");
    else puts("Normal Ending");
    return 0;
}
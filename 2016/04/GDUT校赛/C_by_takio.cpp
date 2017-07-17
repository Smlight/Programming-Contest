#include <cstdio>
#include <queue>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define psi pair <string, int>
using namespace std;
  
const int N = 110, INF = 0x3f3f3f3f, mod = 1000000009;
int a[N][N], vis[N][N], n;
pii d[N][N];
int dx[5] = {0, 1, 0, -1};
int dy[5] = {1, 0, -1, 0};

void spfa () {
    memset (vis, 0, sizeof vis);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = pii (INF, 0);
        }
    }
    d[1][1] = pii (a[1][1] + a[n][n], 1);
    vis[1][1] = 1;
    queue <pii> q;
    q.push (pii (1, 1));
    while (!q.empty ()) {
        pii u = q.front();
        q.pop();
        int aa = u.xx, bb = u.yy;
        vis[aa][bb] = 0;
//        , cc = n - u.a + 1, dd = n - u.b + 1
        for (int i = 0; i < 4; i++) {
            int ta = aa + dx[i], tb = bb + dy[i];
            if (1 <= ta && ta <= n && 1 <= tb && tb <= n) {
                int dis;
                if (ta + tb == n + 1) dis = a[ta][tb];
                else dis = a[ta][tb] + a[n - tb + 1][n - ta + 1];
                if (d[ta][tb].xx == d[aa][bb].xx + dis) (d[ta][tb].yy += d[aa][bb].yy) %= mod;
                if (d[ta][tb].xx > d[aa][bb].xx + dis) {
                    d[ta][tb].xx = d[aa][bb].xx + dis;
                    d[ta][tb].yy = d[aa][bb].yy;
                    if (!vis[ta][tb]) {
                        vis[ta][tb] = 1;
                        q.push (pii (ta, tb));
                    }
                }
            }
        }
    }
    int res = 0;
    int dis = INF;
    for (int i = 1; i <= n; i++) {
//        cout << d[i][n - i + 1].xx <<' ' << d[i][n - i + 1].yy << endl;
        if (dis == d[i][n - i + 1].xx) (res += d[i][n - i + 1].yy) %= mod;
        if (dis > d[i][n - i + 1].xx) res = d[i][n - i + 1].yy, dis = d[i][n - i + 1].xx;
//        res = min (res, d[i][n - i + 1]);
    }
//    cout << dis << endl;
    cout << res << endl;
}
  
int main () {
//    freopen ("in.txt", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
//        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                scanf ("%d", &a[i][j]);
            }
        }
        spfa ();
    }
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct seg_tree {
    static const int MAXN = 100005;
    struct Node {
        ll mn, tag;
    } node[MAXN << 2];
    ll arr[MAXN];

    int lson(int x) { return x << 1; }
    int rson(int x) { return (x << 1) + 1; }

    void make(int x, int xl, int xr) {
        if(xl == xr) {
            node[x].mn = arr[xl];
            node[x].tag = 0;
            return;
        }
        int mid = (xl + xr) >> 1;
        make(lson(x), xl, mid);
        make(rson(x), mid + 1, xr);
        node[x].mn = min(node[lson(x)].mn, node[rson(x)].mn);
        node[x].tag = 0;
    }

    void pushdown(int x, int xl, int xr) {
        node[x].mn += node[x].tag;
        if(xl < xr) {
            node[lson(x)].tag += node[x].tag;
            node[rson(x)].tag += node[x].tag;
        }
        node[x].tag = 0;
    }

    void pushup(int x, int xl, int xr) {
        int mid = (xl + xr) >> 1;
        if(xl != xr) {
            node[x].mn = min(node[lson(x)].mn + node[lson(x)].tag,
                             node[rson(x)].mn + node[rson(x)].tag);
        }
    }

    ll query(int x, int xl, int xr, int ql, int qr) {
        if(xl > qr || xr < ql) return 1e9+7;
        if(xl == ql && xr == qr) {
            return node[x].mn + node[x].tag;
        }
        ll ans = 1e9+7;
        int mid = (xl + xr) >> 1;
        pushdown(x, xl, xr);
        ans = min(ans, query(lson(x), xl, mid, ql, min(mid, qr)));
        ans = min(ans, query(rson(x), mid + 1, xr, max(ql, mid + 1), qr));
        return ans;
    }

    void update(int x, int xl, int xr, int cl, int cr, ll dt) {
        if(xr < cl || xl > cr) return;
        if(cl == xl && cr == xr) {
            node[x].tag += dt;
            return;
        }
        pushdown(x, xl, xr);
        int mid = (xl + xr) >> 1;
        update(lson(x), xl, mid, cl, min(mid, cr), dt);
        update(rson(x), mid + 1, xr, max(cl, mid + 1), cr, dt);
        pushup(x, xl, xr);
    }
} st;

struct Bit {
    //1 Base
    int arr[100005];
    int n;

    int lowbit(int x) { return x & (-x); }

    void add(int i, int x) {
        int pos = i;
        while(pos <= n) {
            arr[pos] += x;
            pos += lowbit(pos);
        }
    }

    int sum(int i) {
        int pos = i, ans = 0;
        while(pos) {
            ans += arr[pos];
            pos -= lowbit(pos);
        }
        return ans;
    }

    void init(int _n) {
        n = _n;
        memset(arr, 0, sizeof(arr));
    }
} bit;

int n, q;

void dfs(int l, int r) {
    if(l == r) {
        if(st.query(1, 1, n, l, l) == 0) {
            st.update(1, 1, n, l, l, st.arr[l]);
            bit.add(l, 1);
        }
        return;
    }
    int mid = (l + r) / 2;
    if(st.query(1, 1, n, l, mid) == 0) {
        dfs(l, mid);
    }
    if(st.query(1, 1, n, mid + 1, r) == 0) {
        dfs(mid + 1, r);
    }
}

int main() {
    while(scanf("%d %d", &n, &q) != EOF) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", st.arr + i);
        }
        st.make(1, 1, n);
        bit.init(n);
        int l, r;
        char cmd[5];
        while(q--) {
            scanf("%s %d %d", cmd, &l, &r);
            if(cmd[0] == 'a') {
                st.update(1, 1, n, l, r, -1);
                dfs(l, r);
            } else {
                int ans = bit.sum(r) - bit.sum(l - 1);
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
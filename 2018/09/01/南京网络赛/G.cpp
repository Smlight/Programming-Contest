#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100005;
const ll INF = 1LL << 60;
ll arr[N];
struct seg_tree {
    struct Node {
        ll sum, tag;
    } node[N << 2];

    int lson(int x) { return x << 1; }
    int rson(int x) { return (x << 1) + 1; }

    void make(int x, int xl, int xr) {
        if(xl == xr) {
            node[x].sum = arr[xl];
            node[x].tag = 0;
            return;
        }
        int mid = (xl + xr) >> 1;
        make(lson(x), xl, mid);
        make(rson(x), mid + 1, xr);
        node[x].sum = min(node[lson(x)].sum, node[rson(x)].sum);
        node[x].tag = 0;
    }

    void pushdown(int x, int xl, int xr) {
        node[x].sum += node[x].tag;
        if(xl < xr) {
            node[lson(x)].tag += node[x].tag;
            node[rson(x)].tag += node[x].tag;
        }
        node[x].tag = 0;
    }

    void pushup(int x, int xl, int xr) {
        int mid = (xl + xr) >> 1;
        node[x].sum = min(node[lson(x)].sum + node[lson(x)].tag, node[rson(x)].sum + node[rson(x)].tag);
    }

    ll query(int x, int xl, int xr, int ql, int qr) {
        if(xl > qr || xr < ql) return INF;
        if(xl == ql && xr == qr) {
            return node[x].sum + node[x].tag;
        }
        ll ans = INF;
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

int ansx[100005], ansy[100005];

int bs(int a, int n, ll x)
{
    int l=a, r=n;
    int res=-1;
    while (l<=r) {
        int m=(l+r)>>1;
        if (st.query(1,1,n,a,m)<=x) {
            res=m;
            r=m-1;
        } else {
            l=m+1;
        }
    }
    return res;
}

void write(int x)
{
	if (x==0) { putchar('0'); return; }
	if (x<0) putchar('-'),x=-x;
	char s[20];
	int i=0;
	while (x) s[i++]=x%10+'0',x/=10;
	for (i--;i>=0;i--) putchar(s[i]);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        scanf("%lld", arr + i);
    }
    st.make(1, 1, n);
    ll money = 0, cnt = 0;
    for(int i = 1; i <= 100000; ++i) {
        if(cnt < n) {
            money += m;
//        printf("INIT: %d\n", money);
            int lb = 1;
            while(true) {
                int mid = bs(lb, n, money);
                if(mid == -1) break;
                st.update(1, 1, n, mid, mid, INF);
    //            printf("%d %d\n", mid, money);
                lb = mid + 1;
                money -= arr[mid];
                ++cnt;
            }
        }
        ansx[i] = money;
        ansy[i] = cnt;
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        int x;
        scanf("%d", &x);
        write(ansy[x]);
        putchar(' ');
        write(ansx[x]);
        puts("");
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct L_B {
    long long d[61],p[61];
    int cnt;
    L_B() {
        init();
    }

    void init() {
        memset(d,0,sizeof(d));
        memset(p,0,sizeof(p));
        cnt=0;
    }

    bool insert(long long val) {
        for (int i=60;i>=0;i--)
            if (val&(1LL<<i))
            {
                if (!d[i])
                {
                    d[i]=val;
                    break;
                }
                val^=d[i];
            }
        return val>0;
    }
    long long query_max() {
        long long ret=0;
        for (int i=60;i>=0;i--)
            if ((ret^d[i])>ret)
                ret^=d[i];
        return ret;
    }
    long long query_min() {
        for (int i=0;i<=60;i++)
            if (d[i])
                return d[i];
        return 0;
    }
    void rebuild() {
        for (int i=60;i>=0;i--)
            for (int j=i-1;j>=0;j--)
                if (d[i]&(1LL<<j))
                    d[i]^=d[j];
        for (int i=0;i<=60;i++)
            if (d[i])
                p[cnt++]=d[i];
    }
    long long kthquery(long long k) {
        int ret=0;
        if (k>=(1LL<<cnt))
            return -1;
        for (int i=60;i>=0;i--)
            if (k&(1LL<<i))
                ret^=p[i];
        return ret;
    }
} b1, b2;

struct Edge {
    int to, next;
} eg[200005];
int head[100005], w[100005], tot = 0;

void init() {
    memset(head, 0xff, sizeof(head));
    b1.init(); b2.init();
    tot = 0;
}

void addedge(int from, int to) {
    eg[tot] = {to, head[from]};
    head[from] = tot++;
}

void dfs(int v, int p, int l) {
    if(l & 1) b1.insert(w[v]);
    else b2.insert(w[v]);
    for(int i = head[v]; i != -1; i = eg[i].next) {
        if(eg[i].to != p) {
            dfs(eg[i].to, v, l + 1);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        init();
        int n;
        scanf("%d", &n);
        ll s = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", w + i);
            s ^= w[i];
        }
        for(int i = 1; i < n; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            addedge(u, v);
            addedge(v, u);
        }
        dfs(1, -1, 0);
        ll qm = max(b1.query_max(), b2.query_max());
        ll tm = s ^ qm;
        if(qm == tm) puts("D");
        else if(qm > tm) puts("Q");
        else puts("T");
    }
    return 0;
}
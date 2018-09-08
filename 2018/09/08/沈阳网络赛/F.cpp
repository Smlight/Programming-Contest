#include <bits/stdc++.h>
using namespace std;

namespace dinic {
    const int inf = 1000000000;
    const int maxn = 10000, maxm = 40000;
    struct Edge {
        int v, f, nxt;
    };
    int n, src, sink, g[maxn + 10], nume;
    Edge e[maxm * 2 + 10];
    void addedge(int u, int v, int c) {
        e[++nume].v = v;
        e[nume].f = c;
        e[nume].nxt = g[u];
        g[u] = nume;
        e[++nume].v = u;
        e[nume].f = 0;
        e[nume].nxt = g[v];
        g[v] = nume;
    }
    void init() {
        memset(g, 0, sizeof(g));
        nume = 1;
    }
    queue<int> que;
    bool vis[maxn + 10];
    int dist[maxn + 10];
    void bfs() {
        memset(dist, 0, sizeof(dist));
        while(!que.empty()) que.pop();
        vis[src] = true;
        que.push(src);
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            for(int i = g[u]; i; i = e[i].nxt) {
                if(e[i].f && !vis[e[i].v]) {
                    que.push(e[i].v);
                    dist[e[i].v] = dist[u] + 1;
                    vis[e[i].v]  = true;
                }
            }
        }
    }
    int dfs(int u, int delta) {
        if(u == sink) {
            return delta;
        } else {
            int ret = 0;
            for(int i = g[u]; delta && i; i = e[i].nxt) {
                if(e[i].f && dist[e[i].v] == dist[u] + 1) {
                    int dd = dfs(e[i].v, min(e[i].f, delta));
                    e[i].f -= dd;
                    e[i ^ 1].f += dd;
                    delta -= dd;
                    ret += dd;
                }
            }
            return ret;
        }
    }
    int maxflow() {
        int ret = 0;
        while(true) {
            memset(vis, 0, sizeof(vis));
            bfs();
            if(!vis[sink]) return ret;
            ret += dfs(src, inf);
        }
    }
}

bool lowbound_flow(int n, int source, int sink,
                   vector<int>& u, vector<int>& v, vector<int>& L, vector<int>& U) {
    dinic::init();
    vector<int> tot_in(n + 1), tot_out(n + 1);
    for(int i = 0; i < u.size(); ++i) {
        if(U[i] < L[i]) return 0;
        tot_in[v[i]] += L[i];
        tot_out[u[i]] += L[i];
        dinic::addedge(u[i], v[i], U[i] - L[i]);
    }
    dinic::addedge(sink, source, 1000000000);
    int super_source = n + 1, super_sink = n + 2;
    dinic::src = super_source;
    dinic::sink = super_sink;
    for(int i = 1; i <= n; ++i) {
        dinic::addedge(super_source, i, tot_in[i]);
        dinic::addedge(i, super_sink, tot_out[i]);
    }
    int ans = dinic::maxflow();
    for(int i = dinic::g[super_source]; i; i = dinic::e[i].nxt) {
        if(dinic::e[i].f != 0) return 0;
    }
    return 1;
}

int main() {
    int ln, rn, eg, cas = 1;
    while(scanf("%d %d %d", &ln, &rn, &eg) != EOF) {
        int l, r;
        scanf("%d %d", &l, &r);
        vector<int> uv, vv, L, R;
        for(int i = 0; i < eg; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            v += ln;
            uv.push_back(u);
            vv.push_back(v);
            L.push_back(0);
            R.push_back(1);
        }
        int s = ln + rn + 1, t = ln + rn + 2;
        for(int i = 1; i <= ln; ++i) {
            uv.push_back(s);
            vv.push_back(i);
            L.push_back(l);
            R.push_back(r);
        }
        for(int i = 1; i <= rn; ++i) {
            uv.push_back(i + ln);
            vv.push_back(t);
            L.push_back(l);
            R.push_back(r);
        }
        printf("Case %d: ", cas++);
        if(lowbound_flow(ln + rn + 2, s, t, uv, vv, L, R)) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
const int INF = 0x3f3f3f3f;

int s, t, k;
bool vis[maxn];
int dist[maxn];
struct Node {
    int v, c;
    Node (int _v = 0, int _c = 0) : v(_v), c(_c) {}
    bool operator < (const Node &rhs) const {
        return c + dist[v] > rhs.c + dist[rhs.v];
    }
};
struct Edge {
    int v, cost;
    Edge (int _v = 0, int _cost = 0) : v(_v), cost(_cost) {}
};
vector<Edge>E[maxn], revE[maxn];
void Dijkstra(int n, int s) {
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    priority_queue<Node>que;
    dist[s] = 0;
    que.push(Node(s, 0));
    while (!que.empty()) {
        Node tep = que.top();
        que.pop();
        int u = tep.v;
        if (vis[u])
            continue;
        vis[u] = true;
        for (int i = 0; i < (int)E[u].size(); i++) {
            int v = E[u][i].v;
            int cost = E[u][i].cost;
            if (!vis[v] && dist[v] > dist[u] + cost) {
                dist[v] = dist[u] + cost;
                que.push(Node(v, dist[v]));
            }
        }
    }
}
int astar(int s) {
    priority_queue<Node> que;
    que.push(Node(s, 0));
    k--;
    while (!que.empty()) {
        Node pre = que.top();
        que.pop();
        int u = pre.v;
        if (u == t) {
            if (k)
                k--;
            else
                return pre.c;
        }
        for (int i = 0; i < (int)revE[u].size(); i++) {
            int v = revE[u][i].v;
            int c = revE[u][i].cost;
            que.push(Node(v, pre.c + c));
        }
    }
    return -1;
}

void addedge(int u, int v, int w) {
    revE[u].push_back(Edge(v, w));
    E[v].push_back(Edge(u, w));
}

int main() {
    int n, m, tot;
    while(scanf("%d %d", &n, &m) != EOF) {
        scanf("%d %d %d %d", &s, &t, &k, &tot);
        for(int i = 0; i <= n; ++i) {
            E[i].clear();
            revE[i].clear();
        }
        while(m--) {
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);
            addedge(u, v, c);
        }
        Dijkstra(n, t);
        if(dist[s] == INF) {
            puts("Whitesnake!");
            continue;
        }
        if(s == t) ++k;
        int need = astar(s);
        if(need > tot) puts("Whitesnake!");
        else puts("yareyaredawa");
    }
    return 0;
}
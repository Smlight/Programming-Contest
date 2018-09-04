#include <bits/stdc++.h>
using namespace std;
const int E = 400005, V = 100005;
struct Edge {
    int to, next, c;
} eg[E];
int head[V], tot, dis[V];

void init() {
    memset(head, 0xff, sizeof(head));
    memset(dis, 0xff, sizeof(dis));
    tot = 0;
}

void addedge(int from, int to, int color) {
    eg[tot] = {to, head[from], color};
    head[from] = tot++;
}

queue<int> q;
void dfs(int v, int c, int d) {
    dis[v] = d + 1;
    q.push(v);
    //printf("%d\n", v);
    for(int i = head[v]; i != -1; i = eg[i].next) {
        if(eg[i].c == c && dis[eg[i].to] == -1) {
            dfs(eg[i].to, c, d);
        }
    }
}

void bfs() {
    while(!q.empty()) q.pop();
    dis[1] = 0;
    q.push(1);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int i = head[now]; i != -1; i = eg[i].next) {
            if(dis[eg[i].to] == -1) {
                dfs(eg[i].to, eg[i].c, dis[now]);
            }
        }
    }
}

int main() {
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF) {
        init();
        int u, v, c;
        for(int i = 1; i <= m; ++i) {
            scanf("%d %d %d", &u, &v, &c);
            addedge(u, v, c);
            addedge(v, u, c);
        }
        bfs();
        printf("%d\n", dis[n]);
    }
    return 0;
}
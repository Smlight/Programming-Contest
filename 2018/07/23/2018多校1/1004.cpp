#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
const int N = 100005;
int ans[N];
PII a[N];
bool exist[N];

void exact(int m) {
    int now = 1;
    sort(a + 1, a + m + 1,
         [](PII l, PII r) { return l.first < r.first || (l.first == r.first && l.second > r.second); } );
    fill(exist + 1, exist + m + 1, true);
    for(int i = 2; i <= m; ++i) {
        if(a[i].second <= a[now].second) {
            exist[i] = false;
        } else {
            now = i;
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= m; ++i) {
            scanf("%d %d", &a[i].first, &a[i].second);
        }
        exact(m);
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 1; i <= n; ++i) pq.push(i);
        int now = 1;
        while(now <= m && !exist[now]) ++now;
        for(int i = 1; i <= n; ++i) {
            if(now > m || i < a[now].first) {
                ans[i] = 1;
                //puts("==1");
            } else if(i > a[now].second) {
                int nxt = now + 1;
                while(nxt <= m && !exist[nxt]) ++nxt;
                if(nxt > m) {
                    ans[i] = 1;
                    now = nxt;
                } else {
                    for(int j = a[now].first; j < min(a[now].second + 1, a[nxt].first); ++j) {
                        pq.push(ans[j]);
                    }
                    if(i < a[nxt].first) {
                        ans[i] = 1;
                    } else {
                        ans[i] = pq.top();
                        pq.pop();
                    }
                    now = nxt;
                }
                //puts("==2");
            } else {
                //puts("==3");
                ans[i] = pq.top();
                pq.pop();
            }
        }
        for(int i = 1; i <= n; ++i) {
            printf("%d%c", ans[i], " \n"[i == n]);
        }
    }
    return 0;
}
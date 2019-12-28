#include <bits/stdc++.h>
using namespace std;
//using ll = long long;

struct SpecItem {
    int id,sc;
    bool operator<(const SpecItem &rhs) const {
        return sc>rhs.sc || sc==rhs.sc && id<rhs.id;
    }
    bool operator>(const SpecItem &rhs) const {
        return rhs<*this;
    }
    bool operator==(const SpecItem &rhs) const {
        return sc==rhs.sc && id==rhs.id;
    }
};
struct Item {
    int tp,id,sc;
    bool operator<(const Item &rhs) const {
        if (sc!=rhs.sc) return sc>rhs.sc;
        if (tp!=rhs.tp) return tp<rhs.tp;
        return id<rhs.id;
    }
    bool operator>(const Item &rhs) const {
        return rhs<*this;
    }
    bool operator==(const Item &rhs) const {
        return !(*this<rhs) && !(rhs<*this);
    }
};
const int M=55;
set<SpecItem> sitems[M];
map<int,int> scores[M];

int main()
{
//    freopen("D.in","r",stdin);
    int n,m;
    scanf("%d%d",&m,&n);
    for (int i=1;i<=n;i++) {
        int id,sc;
        scanf("%d%d",&id,&sc);
        for (int j=0;j<m;j++) {
            sitems[j].insert({id,sc});
            scores[j][id]=sc;
        }
    }
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        int op;
        scanf("%d",&op);
        if (op==1) {
            int tp,id,sc;
            scanf("%d%d%d",&tp,&id,&sc);
            sitems[tp].insert({id,sc});
            scores[tp][id]=sc;
        } else if (op==2) {
            int tp,id;
            scanf("%d%d",&tp,&id);
            sitems[tp].erase({id,scores[tp][id]});
        } else {
            int k;
            scanf("%d",&k);
            priority_queue< Item > Q;
            for (int i=0;i<m;i++) {
                int limit;
                scanf("%d",&limit);
                limit = min(limit,k);
                auto it = sitems[i].begin();
                for (int j=1;j<=limit;j++) {
                    if (it == sitems[i].end()) break;
                    Q.push({i,it->id,it->sc});
                    ++it;
                }
                while ((int)Q.size()>k) Q.pop();
            }
            vector<int> selected[M];
            while (!Q.empty()) {
                auto u = Q.top();
                Q.pop();
                selected[u.tp].push_back(u.id);
            }
            for (int i=0;i<m;i++) {
                sort(selected[i].begin(),selected[i].end());
                int sz = (int)selected[i].size();
                if (sz == 0) {
                    puts("-1");
                } else {
                    for (int j=0;j<sz;j++) {
                        printf("%d%c",selected[i][j]," \n"[j==sz-1]);
                    }
                }
            }
        }
    }
    return 0;
}

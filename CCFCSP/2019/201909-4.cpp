#include <bits/stdc++.h>
using namespace std;
//using ll = long long;

struct SpecItem {
    int id,sc;
    bool operator>(const SpecItem &rhs) const {
        return sc>rhs.sc || sc==rhs.sc && id<rhs.id;
    }
    bool operator<(const SpecItem &rhs) const {
        return rhs>*this;
    }
    bool operator==(const SpecItem &rhs) const {
        return sc==rhs.sc && id==rhs.id;
    }
};
struct Item {
    int tp,id,sc;
    bool operator>(const Item &rhs) const {
        if (sc!=rhs.sc) return sc>rhs.sc;
        if (tp!=rhs.tp) return tp<rhs.tp;
        return id<rhs.id;
    }
    bool operator<(const Item &rhs) const {
        return rhs>*this;
    }
    bool operator==(const Item &rhs) const {
        return !(*this<rhs) && !(rhs<*this);
    }
};
const int M=55;
set< SpecItem, greater<SpecItem> > sitems[M];
unordered_map<int,int> scores[M];
vector<int> selected[M];
set< SpecItem, greater<SpecItem> >::iterator it[M];
int limit[M];

int main()
{
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
            priority_queue<Item> Q;
            int k;
            scanf("%d",&k);
            for (int i=0;i<m;i++) {
                selected[i].clear();
                scanf("%d",&limit[i]);
                limit[i]=min(limit[i],(int)sitems[i].size());
                it[i]=sitems[i].begin();
                if (limit[i]) Q.push({i,it[i]->id,it[i]->sc});
            }
            for (int i=0;i<k&&!Q.empty();i++) {
                auto item=Q.top();
                Q.pop();
                selected[item.tp].push_back(item.id);
                if (--limit[item.tp]==0) continue;
                ++it[item.tp];
                Q.push({item.tp,it[item.tp]->id,it[item.tp]->sc});
            }
            for (int i=0;i<m;i++) {
                // sort(selected[i].begin(),selected[i].end());
                int sz=(int)selected[i].size();
                if (sz==0) {
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

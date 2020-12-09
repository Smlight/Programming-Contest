#include <bits/stdc++.h>
using namespace std;

using PII = pair<int,int>;

const int N=505, M=20010;
struct Edge {
    int go,next;
} eg[M];
int last[N],tot=0;
vector< vector<int> > __goo;
int c[N];

struct Mes {
    int tp,x,y;
    bool operator<(const Mes &rhs) const {
        return y<rhs.y /*|| y==rhs.y && tp<rhs.tp*/ ;
    }
    bool operator>(const Mes &rhs) const {
        return rhs<(*this);
    }
};
queue<PII> tlk[N];

void addedge(int x,int y)
{
    eg[tot]={y,last[x]};
    last[x]=tot++;
}

void update(int x,int y)
{
    while (!tlk[x].empty() && tlk[x].front().first<=y) {
        int cc=tlk[x].front().second;
        if (__goo[cc].size() > __goo[c[x]].size() || __goo[cc].size() == __goo[c[x]].size() && __goo[cc].back() < __goo[c[x]].back()) {
            c[x]=cc;
        }
        tlk[x].pop();
    }
}

struct Task {
    int tp,x,y,z;
    bool operator<(const Task &rhs) const {
        if (y!=rhs.y) return y<rhs.y;
        if (tp!=rhs.tp) return tp<rhs.tp;
        if (z!=rhs.z) return z<rhs.z;
        return x<rhs.x;
    }
};
multiset<Task> tasks;

/*
void dfs(int u,int y,int t)
{
    if (vis[u]) return;
    for (int i=last[x];i!=-1;i=eg[i].next) {
        int v=eg[i].go;
        
        tlk[v].push(Mes(0,y+t,u));
        tasks.insert({1,v,y+t,0});
    }
}
*/

int main()
{
    memset(last,-1,sizeof(last));
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        addedge(x,y);
        addedge(y,x);
    }
    int t,k;
    scanf("%d%d",&t,&k);
    char s[1024];
    fgets(s,1024,stdin);
    while (k--) {
        fgets(s,1024,stdin);
        int x,y,z;
        if (sscanf(s,"%d%d%d",&x,&y,&z)==3) {
            tasks.insert({1,x,y,z});
        } else {
            tasks.insert({2,x,y,0});
        }
    }
    // puts("input ok!");
    // for (auto &t:tasks) {
    //     printf("%d %d %d %d\n", t.tp, t.x, t.y, t.z);
    // }
    vector<int> o;
    o.push_back(0);
    __goo.push_back(o);
    for (int i=1;i<=n;i++) c[i]=0;
    int ddl = tasks.rbegin() -> y;
    while (!tasks.empty()) {
        Task tk = *tasks.begin();
        int x = tk.x;
        int y = tk.y;
        int z = tk.z;
        if (y > ddl) break;
        /*
        printf("%d %d %d %d\n", tk.tp, x, y, z);
        system("pause");
        */
        int pre=c[x];
        update(x,y);
        if (tk.tp == 1) {
            vector<int> now(__goo[c[x]]);
            now.push_back(z);
            __goo.push_back(now);
            c[x] = __goo.size()-1;
        }
        if (c[x] != pre) {
            for (int i=last[x];i!=-1;i=eg[i].next) {
                int v=eg[i].go;
                tlk[v].push(PII(y+t,c[x]));
                tasks.insert({0,v,y+t,0});
            }
        }
        if (tk.tp == 2) {
            int sz=__goo[c[x]].size();
            printf("%d",sz);
            for (int i=0;i<sz;i++) {
                printf(" %d",__goo[c[x]][i]);
            }
            puts("");
        }
        
        tasks.erase(tasks.begin());
    }
    return 0;
}

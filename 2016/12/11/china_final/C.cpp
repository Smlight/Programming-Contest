#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=1005,MAX=1e5+5;
vector<int> p[MAX];
int a[N],dp[N][N];
bool isok[N][N];
int vis[MAX];
set<PII> ival;
multiset<int> q;

void split(int x)
{
    auto it=ival.lower_bound(PII(x+1,0));
    if (it==ival.begin()) return;
    it--;
    int a=it->first,b=it->second;
    ival.erase(it);
    q.erase(q.find(dp[a][b]));
    if (a<x) {
        ival.insert(PII(a,x-1));
        q.insert(dp[a][x-1]);
    }
    if (x<b) {
        ival.insert(PII(x+1,b));
        q.insert(dp[x+1][b]);
    }
}

int main()
{
    int T,n;
    scanf("%d",&T);
    for (int t=1;t<=T;t++) {
        scanf("%d",&n);
        memset(vis,0,sizeof(vis));
        for (int i=1;i<MAX;i++) {
            p[i].clear();
        }
        for (int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            p[a[i]].push_back(i);
        }
        for (int i=1;i<=n;i++) {
            bool f=true;
            for (int j=i;j<=n;j++) {
                if (vis[a[j]]==i) {
                    f=false;
                }
                vis[a[j]]=i;
                isok[i][j]=f;
            }
        }
        for (int len=1;len<=n;len++) {
            for (int i=1;i+len-1<=n;i++) {
                int j=i+len-1;
                if (isok[i][j]) {
                    dp[i][j]=j-i+1;
                } else {
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        int ans=-1;
        memset(vis,0,sizeof(vis));
        for (int i=1;i<=n;i++) {
            ival.clear();q.clear();
            ival.insert(PII(1,n));
            q.insert(dp[1][n]);
            for (int j=i;j<=n;j++) {
                if (vis[a[j]]==i) {
                    break;
                }
                vis[a[j]]=i;
                for (auto x:p[a[j]]) {
                    split(x);
                }
                int cur=j-i+1;
                if (!q.empty()) {
                    cur+=*q.rbegin();
                }
                ans=max(cur,ans);
            }
        }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}

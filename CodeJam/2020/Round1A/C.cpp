#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N=1e6;
int mp[N],L[N],R[N],U[N],D[N];
vector<int> pre, now;

inline void del(int x)
{
    if (!mp[x]) return;
    mp[x] = 0;
    L[R[x]] = L[x];
    R[L[x]] = R[x];
    U[D[x]] = U[x];
    D[U[x]] = D[x];
}

int main()
{
    int T,cas=0;
    scanf("%d",&T);
    while (T--) {
        printf("Case #%d: ",++cas);
        int r,c;
        scanf("%d%d",&r,&c);
        vector<vector<int>> id(r+2,vector<int>(c+2,0));
        for (int i=0;i<r+2;i++) {
            for (int j=0;j<c+2;j++) {
                int x = i*(c+2)+j; id[i][j] = x;
                if (j>0) L[x] = x-1; else L[x] = x;
                if (j<c+1) R[x] = x+1; else R[x] = x;
                if (i>0) U[x] = x-(c+2); else U[x] = x;
                if (i<r+1) D[x] = x+(c+2); else D[x] = x;
            }
        }
        memset(mp,0,sizeof(mp));
        ll sum = 0;
        pre.clear();
        for (int i=1;i<=r;i++) {
            for (int j=1;j<=c;j++) {
                int x = id[i][j];
                pre.push_back(x);
                scanf("%d",&mp[x]);
                sum += mp[x];
            }
        }
        bool end = false;
        ll ans = 0;
        while (!end) {
            end = true;
            now.clear();
            for (auto x:pre) {
                if (!mp[x]) continue;
                ll aa = 0,  bb = 0;
                if (mp[L[x]]) aa += mp[L[x]] , bb += 1;
                if (mp[R[x]]) aa += mp[R[x]] , bb += 1;
                if (mp[U[x]]) aa += mp[U[x]] , bb += 1;
                if (mp[D[x]]) aa += mp[D[x]] , bb += 1;
                if (mp[x] * bb < aa) {
                    end = false;
                    now.push_back(x);
                }
            }
            ans += sum;
            sort(now.begin(),now.end());
            now.erase(unique(now.begin(),now.end()),now.end());
            pre.clear();
            for (auto x:now) {
                pre.push_back(L[x]);
                pre.push_back(R[x]);
                pre.push_back(U[x]);
                pre.push_back(D[x]);
                sum -= mp[x];
                del(x);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
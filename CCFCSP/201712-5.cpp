#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,ll> PIL;
typedef pair<int,int> PII;

const int N=100010;
const ll MO=1000000000000000000;
vector<PIL> E[N];
int fa[N];
ll s[N],v[N],f[N];
ll ans[N];

void dfs(int u)
{
    for (int i=0;i<(int)E[u].size();i++) {
        dfs(E[u][i].first);
    }
    int x=u;
    ll d=0;
    while (fa[x]) {
        d+=s[x];
        x=fa[x];
        ans[x]=max(ans[x],ans[u]+v[x]-(f[x]-d)*(f[x]-d));
    }
}

int main()
{
    int T,n;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        memset(ans,0,sizeof(ans));
        for (int i=1;i<=n;i++) {
            E[i].clear();
        }
        for (int i=1;i<=n;i++) {
            scanf("%d%I64d%I64d%I64d",&fa[i],&s[i],&v[i],&f[i]);
            if (fa[i]) E[fa[i]].push_back(PIL(i,s[i]));
        }
        dfs(1);
        ll oo=0;
        for (int i=1;i<=n;i++) {
            oo+=ans[i];
            oo%=MO;
        }
        printf("%I64d\n",oo);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
priority_queue<int> Q;
const int N=100010;
int a[N];
PII v[N];

int main()
{
    int T,n,m;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) {
            scanf("%d",a+i);
        }
        for (int i=1;i<=m;i++) {
            scanf("%d%d",&v[i].first,&v[i].second);
        }
        sort(a+1,a+1+n);
        sort(v+1,v+1+m);
        int p=1;
        ll ans=0;
        int cnt=0;
        while (!Q.empty()) {
            Q.pop();
        }
        for (int i=1;i<=n;i++) {
            while (p<=m&&v[p].first<a[i]) {
                Q.push(v[p].second-v[p].first);
                p++;
            }
            if (!Q.empty()){
                ans+=Q.top();
                cnt++;
                Q.pop();
            }
        }
        for (int i=n-cnt+1;i<=n;i++) {
            ans+=a[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}

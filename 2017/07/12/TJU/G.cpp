#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e5+5;
ll a[N];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int n;
        ll m;
        scanf("%d%lld",&n,&m);
        for (int i=1;i<=n;i++) {
            scanf("%lld",a+i);
        }
        int ans=0;
        ll now=0;
        sort(a+1,a+n+1);
        for (int i=1;now<m;) {
            if (i>n||a[i]>now+1) {
                ans++;
                now+=now+1;
            } else {
                now+=a[i++];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

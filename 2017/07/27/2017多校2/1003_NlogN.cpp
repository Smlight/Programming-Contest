#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MO=1e9+7;
const int N=250010;
multiset<int> ss;
int a[N<<1],b[N],c[N<<1];

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF) {
        for (int i=1;i<=n;i++) {
            scanf("%d",a+i);
            c[i]=a[i]-i;
        }
        for (int i=1;i<=n;i++) {
            scanf("%d",b+i);
        }
        sort(b+1,b+n+1);
        ss.clear();
        for (int i=b[1];i<=n;i++) {
            ss.insert(c[i]);
        }
        int k=b[1];
        ll ans=0;
        for (int i=1;i<=n;i++) {
            while (k<=n&&k<b[i]) {
                ss.erase(ss.find(c[k]));
                k++;
            }
            a[n+i]=*ss.rbegin();
            ans=(ans+a[n+i])%MO;
            c[n+i]=a[n+i]-(n+i);
            ss.insert(c[n+i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
ll a[30000];

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF) {
        n<<=1;
        for (int i=1;i<=n;i++) {
            scanf("%lld",a+i);
        }
        sort(a+1,a+n+1);
        ll ans=0;
        for (int i=1;i<=n;i+=2) {
            ans+=a[i+1]-a[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}

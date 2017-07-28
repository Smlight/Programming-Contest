#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int n,m,p;
        scanf("%d%d%d",&n,&m,&p);
        int tot=n*m-1;
        ll ans=0;
        while (tot>p) {
            int t=(tot-1)/p+1;
            ans+=(ll)(p-1)*t*(t-1)/2;
            tot-=t;
        }
        puts(ans&1?"NO":"YES");
    }
    return 0;
}

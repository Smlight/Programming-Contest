#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=100010;
struct Intv {
    int s,e;
    bool operator <(const Intv& rhs) const {
        return s<rhs.s;
    }
} t[N];
multiset<int> ss;

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int n;
        ss.clear();
        scanf("%d",&n);
        for (int i=0;i<n;i++) {
            scanf("%d%d",&t[i].s,&t[i].e);
        }
        sort(t,t+n);
        ll ans=0;
        for (int i=0;i<n;i++) {
            auto it=ss.upper_bound(t[i].s);
            if (it==ss.begin()) {
                ans-=t[i].s;
            } else {
                ss.erase(--it);
            }
            ss.insert(t[i].e);
        }
        int k=0;
        for (int e:ss) {
            ans+=e;
            k++;
        }
        printf("%d %lld\n",k,ans);
    }
    return 0;
}

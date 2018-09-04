#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N=10000010;
int a[N];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        ll n,m,k,p,q,r,MO;
        scanf("%lld%lld%lld%lld%lld%lld%lld",&n,&m,&k,&p,&q,&r,&MO);
        for (int i=1;i<=k;i++) {
            scanf("%d",&a[i]);
        }
        for (int i=k+1;i<=n;i++) {
            a[i]=(p*a[i-1]+q*i+r)%MO;
        }
        deque<int> dq;
        for (int i=n;i>n-m+1;i--) {
            while (!dq.empty() && a[dq.back()]<=a[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ll A=0,B=0;
        for (int i=n-m+1;i>=1;i--) {
            if (!dq.empty() && dq.front()-i+1>m) {
                dq.pop_front();
            }
            while (!dq.empty() && a[dq.back()]<=a[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            A+=a[dq.front()]^i;
            B+=dq.size()^i;
        }
        printf("%lld %lld\n",A,B);
    }
    return 0;
}
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;
const int N=1e7+5;
ll a[N];
deque<ll> dq;

int main()
{
    ll n,k;
    while (scanf("%lld%lld",&n,&k)!=EOF) {
        for (int i=1;i<=n;i++) {
            scanf("%lld",a+i);
        }
        dq.clear();
        ld sum=0,sum2=0;
        for (int i=1;i<=k;i++) {
            sum+=a[i];
            sum2+=a[i]*a[i];
            while(!dq.empty() && a[i]>a[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        ld a1=a[dq.front()],a2=sum/k,a3=sqrt(sum2/k-(sum*sum)/(k*k));
        for (int i=k+1;i<=n;i++) {
            sum+=a[i];
            sum-=a[i-k];
            sum2+=a[i]*a[i];
            sum2-=a[i-k]*a[i-k];
            while(!dq.empty() && a[i]>a[dq.back()])
                dq.pop_back();
            if(!dq.empty() && dq.front() <= i-k)
                dq.pop_front();
            dq.push_back(i);
            a1+=a[dq.front()];
            a2=max(a2,sum/k);
            a3=min(a3,sqrt((sum2-sum*sum/k)/k));
//            printf("SUM: %f\n",sum);
        }
        double o1=a1/(n-k+1),o2=a2,o3=a3;
        printf("%.1f %.1f %.1f\n",o1,o2,o3);
    }
    return 0;
}

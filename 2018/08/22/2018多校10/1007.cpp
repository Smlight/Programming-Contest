#include <bits/stdc++.h>
using namespace std;

const int N=100005;
const int MO=998244353;
long long a[N];

int main()
{
    a[1]=0;
    a[2]=0;
    a[3]=1;
    for (int i=4;i<N;i++) {
        a[i]=(i-3)*a[i-1]%MO+(i-2)*(2*a[i-2]+a[i-3])%MO;
        a[i]%=MO;
    }
    int T,n;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        printf("%lld\n",a[n]);
    }
    return 0;
}
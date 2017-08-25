#include  <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MO=998244353;
ll h[100],a[100],b[100],p[100];

void test()
{
    h[0]=2;h[1]=3;h[2]=6;
    for (int i=3;i<=16;i++) {
        h[i]=4*h[i-1] +17*h[i-2] -12*h[i-3] -16;
    }
    for (int i=1;i<=15;i++) {
        b[i]=3*h[i+1]*h[i]+9*h[i+1]*h[i-1]+9*h[i]*h[i]+27*h[i]*h[i-1]-18*h[i+1]-126*h[i]-81*h[i-1]+192;
    }
    p[0]=1;
    for (int i=1;i<=15;i++) {
        p[i]=p[i-1]*4;
        a[i]=b[i]+p[i];
    }
    for (int i=2;i<=15;i++) {
        printf("%lld,",(ll)sqrt(a[i]));
    }
    puts("");
}

int main()
{
    test();
    int T;
    scanf("%d",&T);
    while (T--) {

    }
    return 0;
}

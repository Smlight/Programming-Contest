#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1000000;
ll s[N+10];

inline ll cubes(ll x)
{
    return x*x*x;
}

int main()
{
    for (int i=1;i<=N;i++) {
        s[i]=cubes(i)-cubes(i-1);
    }
    int T;
    scanf("%d",&T);
    while (T--) {
        ll p;
        scanf("%lld",&p);
        if (*lower_bound(s+1,s+N+1,p)==p) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}

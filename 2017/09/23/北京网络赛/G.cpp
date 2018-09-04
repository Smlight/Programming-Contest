#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n,m;
    while (scanf("%lld%lld",&n,&m)!=EOF) {
        n--;m--;
        ll g=__gcd(n,m);
        ll nn=n/g,mm=m/g;
        printf("%lld\n",nn+mm+(g-1)*nn*mm);
    }
    return 0;
}

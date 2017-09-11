#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n,k;
    while (scanf("%lld%lld",&n,&k)!=EOF) {
        printf("%lld\n",(n-k+1)*k);
    }
    return 0;
}

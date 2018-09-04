#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll li[] = {0, 1, 8, 49, 288, 1681, 9800, 57121, 332928, 1940449, 11309768, 65918161, 384199200, 2239277041L, 13051463048L, 76069501249L, 443365544448L, 2584123765441L, 15061377048200L, 87784138523761L, 511643454094368L, 2982076586042449L, 17380816062160328L};

int main() {
    int T;
    scanf("%d", &T);
    int all = sizeof(li) / sizeof(ll);
    for(int i = 0; i != T; ++i) {
        ll n;
        scanf("%lld", &n);
        int idx = 0;
        while(li[idx] < n) ++idx;
        printf("Case #%d: %lld\n", i + 1, li[idx]);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int n,x;
        scanf("%d",&n);
        int odd=0,even=0;
        for (int i=1;i<=n;i++) {
            int x;
            scanf("%d",&x);
            if (x&1) odd++;
            else even++;
        }
        if (odd>=even) {
            puts("2 1");
        } else {
            puts("2 0");
        }
    }
    return 0;
}

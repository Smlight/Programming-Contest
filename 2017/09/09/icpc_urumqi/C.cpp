#include <bits/stdc++.h>
using namespace std;

int c[1005], d[1005];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--) {
        int n, b;
        scanf("%d %d", &n, &b);
        for(int i = 0; i < n; ++i) {
            scanf("%d", c + i);
        }
        for(int i = 1; i < n; ++i) {
            scanf("%d", d + i);
        }
        int cap = c[0];
        int f = 1;
        for(int i = 1; i < n; ++i) {
            cap -= b * d[i];
            if(cap < 0) {
                f = 0;
                break;
            }
            cap += c[i];
        }
        if(f) puts("Yes");
        else puts("No");
    }
    return 0;
}

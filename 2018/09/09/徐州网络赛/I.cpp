#include <bits/stdc++.h>
using namespace std;
char buf[1000006];
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, ans = 0;
        char seed[3];
        scanf("%d%s", &n, seed);
        scanf("%s", buf);
        bool flag = true;
        for(int i = 0; buf[i]; ++i) {
            int val = abs((int)seed[0] - buf[i]);
            if(flag) {
                if(val != 0) {
                    if(val < 10) ++ans;
                    else ans += 2;
                    flag = false;
                }
            } else {
                ans += 2;
            }
        }
        if(ans == 0) ans = 1;
        printf("%d\n", ans);
    }
    return 0;
}
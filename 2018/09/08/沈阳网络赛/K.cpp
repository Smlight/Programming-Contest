#include <bits/stdc++.h>
using namespace std;

int nn[] = {1, 2, 3, 5, 7, 11, 13, 17, 23, 31, 37, 53, 71, 73, 113, 131, 137, 173, 311, 317};

int main() {
    int T, cas = 1;
    scanf("%d", &T);
    while(T--) {
        char s[105];
        scanf("%s", s);
        printf("Case #%d: ", cas++);
        if(strlen(s) >= 4) puts("317");
        else {
            int x;
            stringstream ss;
            ss << s;
            ss >> x;
            int ans = 0;
            for(auto i : nn) {
                if(i <= x) {
                    ans = i;
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
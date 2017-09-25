#include <bits/stdc++.h>
using namespace std;

using ll = long long;
char s[20];
int line[64];

int main()
{
    memset(line, -1, sizeof(line));
    int hcnt = 0, acnt = 0;
    while(scanf("%s", s) != EOF) {
        if(strcmp(s, "END") == 0) break;
        ll ans = 0;
        int len = strlen(s);
        for(int i = 0; i < len; ++i) {
            ll x;
            if(s[i] >= '0' && s[i] <= '9') {
                x = s[i] - '0';
            } else {
                x = s[i] - 'A' + 10;
            }
            ans = ans * 16 + x;
        }
        ll id = ans / 16;
        ll l = id % 64;
        if(line[l] == id) {
            puts("Hit");
            ++hcnt;
        } else {
            puts("Miss");
            line[l] = id;
        }
        ++acnt;
    }
    printf("Hit ratio = %.2f%%", 100.0 * hcnt / acnt);
    return 0;
}

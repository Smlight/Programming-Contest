#include <bits/stdc++.h>
using namespace std;

const char s[][20] = {
    "rat", "ox", "tiger", "rabbit", "dragon", "snake", "horse", "sheep", "monkey", "rooster", "dog", "pig"
};

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        char l[20], r[20];
        scanf("%s %s", l, r);
        int lidx = -1, ridx = -1;
        for(int i = 0; i != 12; ++i) {
            if(strcmp(l, s[i]) == 0) {
                lidx = i;
            }
            if(strcmp(r, s[i]) == 0) {
                ridx = i;
            }
        }
        assert(lidx != -1 && ridx != -1);
        if(lidx == ridx) puts("12");
        else {
            if(lidx > ridx) ridx += 12;
            printf("%d\n", ridx - lidx);
        }
    }
    return 0;
}

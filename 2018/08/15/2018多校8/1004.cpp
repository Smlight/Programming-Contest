#include <bits/stdc++.h>
using namespace std;
char mp[250][250];
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int h, w;
        scanf("%d %d", &h, &w);
        if((h & 1) && (w & 1)) {
            for(int i = 1; i <= h; ++i) {
                for(int j = 1; j <= w; ++j) {
                    printf("(");
                }
                puts("");
            }
        } else if((h & 1) && !(w & 1)) {
            for(int i = 1; i <= h; ++i) {
                for(int j = 1; j <= w; ++j) {
                    if(j & 1) printf("(");
                    else printf(")");
                }
                puts("");
            }
        } else if(!(h & 1) && (w & 1)) {
            for(int i = 1; i <= h; ++i) {
                for(int j = 1; j <= w; ++j) {
                    if(i & 1) printf("(");
                    else printf(")");
                }
                puts("");
            }
        } else {
            memset(mp, 0, sizeof(mp));
            if (min(w,h) > 6) {
                for(int j = 1; j <= w; ++j) mp[1][j] = '(';
                for(int j = 1; j <= w; ++j) mp[h][j] = ')';
                for (int i=1;i<=h;i++) mp[i][1]='(';
                for (int i=1;i<=h;i++) mp[i][w]=')';
                for (int i=2;i<h;i++) {
                    for (int j=2;j<w;j++) {
                        mp[i][j]= ((i + j) & 1) ? ')' : '(';
                    }
                }
            } else {
                if(w >= h) {
                    for(int j = 1; j <= w; ++j) mp[1][j] = '(';
                    for(int j = 1; j <= w; ++j) mp[h][j] = ')';
                    for(int i = 2; i < h; ++i) {
                        for(int j = 1; j <= w; ++j) {
                            mp[i][j] = ((i + j) & 1) ? '(' : ')';
                        }
                    }
                } else {
                    for(int i = 1; i <= h; ++i) {
                        mp[i][1] = '(';
                        mp[i][w] = ')';
                    }
                    for(int i = 1; i <= h; ++i) {
                        for(int j = 2; j < w; ++j) {
                            mp[i][j] = ((i + j) & 1) ? '(' : ')';
                        }
                    }
                }
            }
            for(int i = 1; i <= h; ++i) {
                puts(mp[i] + 1);
            }
        }
    }
    return 0;
}
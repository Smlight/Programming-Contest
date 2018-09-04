#include <bits/stdc++.h>
using namespace std;

char mp[20][20];
const int INF = 1e9;
int ans = INF;

void rotate(int ii, int ij) {
    int tmp[17];
    int li = (ii - 1) * 4 + 1, lj  = (ij - 1) * 4 + 1;
    tmp[4] = mp[li][lj]; tmp[8] = mp[li][lj + 1];
    tmp[12] = mp[li][lj + 2]; tmp[16] = mp[li][lj + 3];
    //--------------------------------------------------
    tmp[3] = mp[li + 1][lj]; tmp[7] = mp[li + 1][lj + 1];
    tmp[11] = mp[li + 1][lj + 2]; tmp[15] = mp[li + 1][lj + 3];
    //--------------------------------------------------
    tmp[2] = mp[li + 2][lj]; tmp[6] = mp[li + 2][lj + 1];
    tmp[10] = mp[li + 2][lj + 2]; tmp[14] = mp[li + 2][lj + 3];
    //--------------------------------------------------
    tmp[1] = mp[li + 3][lj]; tmp[5] = mp[li + 3][lj + 1];
    tmp[9] = mp[li + 3][lj + 2]; tmp[13] = mp[li + 3][lj + 3];
    //---------------------------------------------------
    int cnt = 1;
    for(int i = li; i < li + 4; ++i) {
        for(int j = lj; j < lj + 4; ++j) {
            mp[i][j] = tmp[cnt++];
        }
    }
}

int idx(int i, int j) {
    int ii = (i - 1) / 4, jj = (j - 1) / 4;
    return ii * 4 + jj + 1;
}

bool judge(int index) {
    if(index == 0) return true;
    int li = ((index - 1) / 4) * 4 + 1, lj = ((index - 1) % 4) * 4 + 1;
    int ri = li + 3, rj = lj + 3;
    if(index == INF) {
        li = 1; ri = 16;
        lj = 1; rj = 16;
    }
    //printf("==%d %d %d %d %d\n", index, li, ri, lj, rj);

    for(int i = li; i <= ri; ++i) {
        int cnt[20] = {0};
        for(int j = 1; j <= rj; ++j) {
            if(++cnt[mp[i][j]] > 1) {
                return false;
            }
        }
    }
    for(int j = lj; j <= rj; ++j) {
        int cnt[20] = {0};
        for(int i = 1; i <= ri; ++i) {
            if(++cnt[mp[i][j]] > 1) {
                return false;
            }
        }
    }
    return true;
}

//void show() {
//    for(int i = 1; i <= 16; ++i) {
//        for(int j = 1; j <= 16; ++j) {
//            char c;
//            if(mp[i][j] >= 0 && mp[i][j] <= 9) c = mp[i][j] + '0';
//            else c = mp[i][j] + 'A' - 10;
//            printf("%c", c);
//        }
//        puts("");
//    }
//    puts("+++++++++++++++++++++++++++++++++++++++");
//}

void dfs(int index, int now) {

    if(judge(INF)) {
        ans = now;
        //printf("+++%d\n", ans);
        return;
    }

    if(index > 16) return;
    if(now >= ans) return;

    int f = (index - 1) / 4 + 1, s = (index - 1) % 4 + 1;
    for(int i = 0; i < 4; ++i) {
        if(judge(index)) {
            dfs(index + 1, now + i);
        }
        //show();
        rotate(f, s);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        for(int i = 1; i <= 16; ++i) scanf("%s", mp[i] + 1);
        for(int i = 1; i <= 16; ++i) {
            for(int j = 1; j <= 16; ++j) {
                if(mp[i][j] >= '0' && mp[i][j] <= '9') mp[i][j] -= '0';
                else mp[i][j] -= 'A' - 10;
            }
        }
        //printf("%d\n", judge(3));
        ans = INF;
        dfs(1, 0);
        printf("%d\n", ans);
    }
    return 0;
}
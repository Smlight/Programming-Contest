#include <bits/stdc++.h>
using namespace std;

int cnt[201][16];
int st[20005];
int sum[201];
int find_min(int p) {
    for(int i = 3; i < 16; ++i) {
        if(cnt[p][i] > 0) return i;
    }
    return -1;
}

int nxt(int p, int x) {
    if(x == 2 + 13) return -1;
    if(cnt[p][x + 1] > 0) return x + 1;
    if(cnt[p][2 + 13] > 0) return 2 + 13;
    return -1;
}
int real(int x) {
    if(x == 14) return 1;
    if(x == 15) return 2;
    return x;
}

void out(int n) {
    for(int i = 1; i <= n; ++i) {
        if(sum[i] != 0) printf("%d\n", sum[i]);
        else puts("Winner");
    }
}

void init() {
    memset(st, 0, sizeof(st));
    memset(cnt, 0, sizeof(cnt));
    memset(sum, 0, sizeof(sum));
}

int main() {
    int T, cas = 1;
    scanf("%d", &T);
    int n, m;
    while(T--) {
        init();
        printf("Case #%d:\n", cas++);
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= m; ++i) {
            scanf("%d", st + i);
            if(st[i] < 3) st[i] += 13;
        }
        int pos = 1;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < 5; ++j) {
                if(pos <= m) {
                    ++cnt[i][st[pos]];
                    sum[i] += real(st[pos]);
                    ++pos;
                }
            }
        }
        int nowp = 1, pre, failcnt = 0;
        bool flag = true;
        while(1) {
            if(flag) {
                failcnt = 0;
                pre = find_min(nowp);
                sum[nowp] -= real(pre);
                --cnt[nowp][pre];
//                printf("%d %d %d\n", nowp, pre, sum[nowp]);
                flag = false;
            } else {
                int val = nxt(nowp, pre);
                if(val > 0) {
                    failcnt = 0;
                    pre = val;
                    --cnt[nowp][val];
                    sum[nowp] -= real(val);
//                    printf("%d %d %d\n", nowp, val, sum[nowp]);
                } else {
                    ++failcnt;
//                    printf("%d %d %d\n", nowp, -1, sum[nowp]);
                }
            }
            if(sum[nowp] == 0) break;

            if(++nowp > n) nowp = 1;
            if(failcnt == n - 1) {
                int p = nowp;
//                puts("ADD");
                do {
//                    printf("%d ", p);
                    if(pos <= m) {
                        ++cnt[p][st[pos]];
                        sum[p] += real(st[pos]);
//                        printf("get %d\n", real(st[pos]));
                        ++pos;
                    }
                    if(++p > n) p = 1;
                } while(p != nowp && pos <= m);
                flag = true;
//                puts("\nSUM:");
//                for(int i = 1; i <= 3; ++i) {
//                    printf("%d ", sum[i]);
//                }
//                puts("**************\n");
            }
        }
        out(n);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

char s[100005], t[100005];
int b[100005];
struct Bit {
    //1 Base
    int arr[100005];
    int n;

    int lowbit(int x) { return x & (-x); }

    void add(int i, int x) {
        int pos = i;
        while(pos <= n) {
            arr[pos] += x;
            pos += lowbit(pos);
        }
    }

    int sum(int i) {
        int pos = i, ans = 0;
        while(pos) {
            ans += arr[pos];
            pos -= lowbit(pos);
        }
        return ans;
    }

    void init(int _n) {
        n = _n;
        for(int i = 1; i <= n; ++i) {
            arr[i] += sum(i - 1) - sum(i - lowbit(i));
        }
    }
} bit;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        memset(b, 0, sizeof(b));
        scanf("%d", &n);
        scanf("%s", s + 1);
        scanf("%s", t + 1);
        int tlen = strlen(t + 1);
        int slen = strlen(s + 1);
        for(int i = 1; i <= slen - tlen + 1; ++i) {
            for(int j = 0; j < tlen; ++j) {
                if(s[i + j] == t[j + 1]) b[i] |= (1 << j);
            }
        }
        int can = 0;
        for(int j = 0; j < tlen; ++j) {
            can |= (1 << j);
        }
        memset(bit.arr, 0, sizeof(bit.arr));
        for(int i = 1; i <= slen - tlen + 1; ++i) {
            if(b[i] == can) {
                bit.arr[i] = 1;
                //printf("%d\n", i);
            }
        }
        bit.init(slen - tlen + 1);
        while(n--) {
            char cmd[2];
            scanf("%s", cmd);
            if(cmd[0] == 'Q') {
                int l, r;
                scanf("%d %d", &l, &r);
                printf("%d\n", bit.sum(r - tlen + 1) - bit.sum(l - 1));
            } else {
                int idx;
                char ccc[2];
                scanf("%d %s", &idx, ccc);
                s[idx] = ccc[0];
                int cnt = tlen;
                for(int i = idx - tlen + 1; i <= idx; ++i) {
                    int pre = b[i];
                    int mv = cnt - 1;
                    if(s[idx] != t[cnt]) {
                        b[i] &= (~(1 << mv));
                    } else {
                        b[i] |= (1 << mv);
                    }
                    if(pre != can && b[i] == can) bit.add(i, 1);
                    if(pre == can && b[i] != can) bit.add(i, -1);
                    --cnt;
                }
                assert(cnt == 0);
            }
        }
        puts("");
    }
    return 0;
}

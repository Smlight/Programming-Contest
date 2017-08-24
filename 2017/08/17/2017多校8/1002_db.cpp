#include <bits/stdc++.h>
using namespace std;

const int len = 100;
int ans[len];
int sum[len];

void init() {
    for(int i = 1; i < len; ++i) {
        for(int j = 1; j <= i; ++j) {
            if(__gcd(i, j) == 1) {
                ans[i] += (int)ceil(1.0 * i / j);
            }
        }
    }
    for(int i = 1; i < len; ++i) {
        sum[i] += sum[i - 1] + ans[i];
    }
}

void show(int n) {
    for(int i = 1; i <= n; ++i) {
        printf("%d ", (int)ceil(1.0 * n / i));
    }
    puts("");
}

int main() {
    init();
    for(int i = 1; i < 20; ++i) {
        printf("%d ", ans[i]);
    }
    puts("");
    for(int i = 1; i < 20; ++i) {
        printf("%d ", sum[i]);
    }
    puts("");
    int n;
    while(scanf("%d", &n) != EOF) {
        show(n);
    }
    return 0;
}

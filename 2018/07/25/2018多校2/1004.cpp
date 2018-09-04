#include <bits/stdc++.h>
using namespace std;

bool used[505];
int count(int n) {
    int cnt = 0;
    memset(used, 0, sizeof(used));
    for(int i = n; i >= 1; --i) {
        if(!used[i]) {
            ++cnt;
            used[i] = true;
            for(int j = 1; j < n; ++j) {
                if(i % j == 0) used[j] = true;
            }
        }
    }
    return cnt;
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        puts("Yes");
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int li[55];
int tmp[21];
int main() {
    int n;
    double a;
    scanf("%d %lf", &n, &a);
    cin.get();
    ll con = a * 1000000;
    int licnt = 0;
    int x; char c;
    string s;
    while(getline(cin, s)) {
        stringstream ss(s);
        while(ss >> x) {
            ++tmp[x];
        }
        for(int i = n; i >= 1; --i) {
            li[licnt] = li[licnt] * 2 + tmp[i];
        }
        ++licnt;
        memset(tmp, 0, sizeof(tmp));
    }
    int ans = 0;
    for(int i = 1; i < (1 << n); ++i) {
        ll cnt = 0;
        for(int j = 0; j < licnt; ++j) {
            if((i & li[j]) == i) {
                ++cnt;
            }
        }
        if(cnt * 1000000 >= con * licnt) {
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}

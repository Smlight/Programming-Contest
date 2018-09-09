#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
map<PII, vector<int>> mp;

int calc(vector<int>& iv) {
    int pre = iv[0], cnt = 1, ans = 0;
    for(int i = 1; i < iv.size(); ++i) {
        if(iv[i] == pre + 1) {
            if(++cnt > ans) ans = cnt;
        } else {
            cnt = 1;
        }
        pre = iv[i];
    }
    return ans == 1 ? 0 : ans;
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        mp.clear();
        for(int i = 0; i < n; ++i) {
            int k;
            scanf("%d", &k);
            while(k--) {
                int x, y;
                scanf("%d %d", &x, &y);
                mp[{x, y}].push_back(i);
            }
        }
        int ans = 0;
        for(auto& i : mp) {
            i.second.erase(unique(i.second.begin(), i.second.end()), i.second.end());
            ans = max(ans, calc(i.second));
        }
        printf("%d\n", ans);
    }
    return 0;
}
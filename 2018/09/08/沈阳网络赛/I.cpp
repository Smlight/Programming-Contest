#include <bits/stdc++.h>
using namespace std;

string mp[257];
char buf[200005];
map<string, int> mpp;
map<char, string> toBin = {
    {'0', "0000"}, {'1', "0001"}, {'2', "0010"}, {'3', "0011"},
    {'4', "0100"}, {'5', "0101"}, {'6', "0110"}, {'7', "0111"},
    {'8', "1000"}, {'9', "1001"}, {'A', "1010"}, {'B', "1011"},
    {'C', "1100"}, {'D', "1101"}, {'E', "1110"}, {'F', "1111"},
};

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        mpp.clear();
        int m, n;
        scanf("%d %d", &m, &n);
        char ccc[16];
        int ddd;
        for(int i = 0; i < n; ++i) {
            scanf("%d %s", &ddd, ccc);
            mp[ddd] = string(ccc);
            mpp[string(ccc)] = ddd;
        }
        scanf("%s", buf);
        for(int i = 0; buf[i]; ++i) {
            buf[i] = toupper(buf[i]);
        }
        string res;
        for(int i = 0; buf[i]; ++i) {
            res += toBin[buf[i]];
        }
        int duan = res.size() / 9;
        string res2;
        for(int i = 0; i < duan; ++i) {
            int st = i * 9, cnt = 0;
            for(int j = 0; j < 8; ++j) {
                if(res[st++] == '1') ++cnt;
            }
            if(cnt & 1) {
                if(res[st++] == '0') {
                    st = i * 9;
                    for(int j = 0; j < 8; ++j) {
                        res2 += res[st++];
                    }
                }
            } else {
                if(res[st++] == '1') {
                    st = i * 9;
                    for(int j = 0; j < 8; ++j) {
                        res2 += res[st++];
                    }
                }
            }
        }
        string tmp, ans;
        for(auto i : res2) {
            tmp += i;
            auto it = mpp.find(tmp);
            if(it != mpp.end()) {
                ans += char(it->second);
                tmp.clear();
            }
            if(ans.size() == m) break;
        }
        printf("%s\n", ans.c_str());
    }
    return 0;
}
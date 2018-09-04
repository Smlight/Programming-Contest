#include <bits/stdc++.h>
using namespace std;

char s[100005];
bool judge() {
    vector<string> seq;
    string tmp;
    for(int i = 0; s[i]; ++i) {
        if(s[i] == '+' || s[i] == '*') {
            if(!tmp.empty()) seq.push_back(tmp);
            seq.push_back("+");
            tmp.clear();
        } else if(s[i] == '?') {
            if(tmp == "0") {
                seq.push_back("0");
                seq.push_back("+");
                s[i] = '+';
                tmp.clear();
            } else {
                s[i] = '1';
                tmp += "1";
            }
        } else {
            tmp += s[i];
        }
    }
    if(!tmp.empty()) seq.push_back(tmp);
    bool num = true;
    for(auto& i : seq) {
        if(num && i == "+") return false;
        if(num && i[0] == '0' && i.size() > 1) return false;
        num = !num;
    }
    return !num;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", s);
        if(judge()) puts(s);
        else puts("IMPOSSIBLE");
    }
    return 0;
}
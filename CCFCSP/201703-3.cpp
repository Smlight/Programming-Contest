#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
    std::ios::sync_with_stdio(false);
    bool same=true;
    vector<string> ve;
    while (getline(cin,s)) {
        if (s=="") {
            same=false;
            ve.clear();
            continue;
        }
        int title=0;
        while (s[title]=='#') ++title;
        if (title) {
            char c=title+'0';
            string tmp("h");
            tmp+=c;
            ve.push_back(tmp);
        }
        int p=title;
        while (s[p]==' ') ++p;
        string text,link;
        if (s[p]=='`') {
            ve.push_back("em");
            ++p;
            while (s[p]!='`') text+=s[p++];
        } else if (s[p]=='[') {

        } else {
            while (s[p]!='`') text+=s[p++];
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

string s;
vector<string> pwd,npath;

void init()
{
    int a=0;
    while (a<(int)s.length()) {
        int b=a+1;
        while (b<(int)s.length()&&s[b]!='/') ++b;
        pwd.push_back(s.substr(a+1,b-a-1));
        a=b;
    }
}

void parse()
{
    if (s.length()&&s[0]=='/') {
        npath.clear();
    } else {
        npath=pwd;
    }
    int a=0;
    while (true) {
        while (a<(int)s.length()&&s[a]=='/') ++a;
        if (a>=(int)s.length()) break;
        int b=a;
        while (b<(int)s.length()&&s[b]!='/') ++b;
        string tmp(s.substr(a,b-a));
//        cout<<tmp<<endl;
        if (tmp=="..") {
            if (npath.size()) npath.pop_back();
        } else if (tmp==".") {
        } else {
            npath.push_back(tmp);
        }
        a=b;
    }
}

void print(vector<string> ve)
{
    for (int i=0;i<(int)ve.size();i++) {
        cout<<"/"<<ve[i];
    }
    cout<<endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int q;
    cin>>q>>s;
    init();
//    print(pwd);
    getline(cin,s);
    while (q--) {
        getline(cin,s);
        parse();
        if (npath.size()) {
            print(npath);
        } else {
            cout<<"/\n";
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int L=1024;
char buf[L];

int to_int(string s)
{
    stringstream ss;
    ss<<s;
    int x;
    ss>>x;
    return x;
}

map<string,int> multi(int k, const map<string,int> &now)
{
    map<string,int> res;
    for (auto &p:now) {
        res[p.first]=p.second*k;
    }
    return res;
}

void add(map<string,int> &res, const map<string,int> &now)
{
    for (auto &p:now) {
        res[p.first]+=p.second;
    }
}

map<string,int> item_parse(const string &s)
{
//	cout << s << endl;
    int p=0;
    int len=s.length();
    map<string,int> res;
    if (isdigit(s[p])) {
        while (isdigit(s[p])) ++p;
        string tmp(s.begin(),s.begin()+p);
        return multi(to_int(tmp),item_parse(string(s.begin()+p,s.end())));
    } else if (s[p]=='(') {
        int cnt=1;
        ++p;
        while (cnt) {
            if (s[p]=='(') ++cnt;
            else if (s[p]==')') --cnt;
            ++p;
        }
        int st = p;
        int k = 1;
        if (isdigit(s[p])) {
            while (isdigit(s[p]) && p<len) ++p;
            string tmp(s.begin()+st, s.begin()+p);
            k = to_int(tmp);
        }
        auto now = multi(k, item_parse(string(s.begin()+1,s.begin()+st-1)));
        add(res, now);
        if (p<len) {
            now = item_parse(string(s.begin()+p,s.end()));
            add(res, now);
        }
        return res;
    } else {
        if (len==1) {
            res[s]=1;
            return res;
        }
        string ele;
        ele += s[p];
        if (s[p+1]>='a' && s[p+1]<='z') {
            ele+=s[++p];
        }
        int st=++p;
        int k=1;
        if (isdigit(s[p])) {
            while (isdigit(s[p]) && p<len) ++p;
            string tmp(s.begin()+st,s.begin()+p);
            k=to_int(tmp);
        }
        res[ele]+=k;
        if (p<len) {
            auto now = item_parse(string(s.begin()+p, s.end()));
            add(res, now);
        }
        return res;
    }
}

map<string,int> parse(string s)
{
    map<string,int> res;
    int pre=0;
    int len=s.length();
    int pos=s.find('+',pre);
    while (pos != string::npos) {
        string tmp(s.begin()+pre,s.begin()+pos);
        //cout<<tmp<<endl;
        auto now = item_parse(tmp);
        add(res, now);
        pre=pos+1;
        pos=s.find('+',pre);
    }
    string tmp(s.begin()+pre,s.end());
    //cout<<tmp<<endl;
    auto now = item_parse(tmp);
    add(res, now);
    return res;
}

bool is_eq(map<string,int> &a, map<string,int> &b)
{
    for (auto &p:a) {
        if (p.second!=b[p.first]) return false;
    }
    return true;
}

int main()
{
//	cout << string("H2O").find('+') << endl;
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%s",buf);
        int d=0;
        while (buf[d]!='=') ++d;
        buf[d]=0;
        auto left=parse(buf);
        auto right=parse(buf+d+1);
        /*
        puts("==============LEFT==============");
        for (auto &p:left) {
            printf("%s: %d\n", p.first.c_str(), p.second);
        }
        puts("==============RIGHT==============");
        for (auto &p:right) {
            printf("%s: %d\n", p.first.c_str(), p.second);
        }
        */
        if (left.size()==right.size() && is_eq(left,right)) {
            puts("Y");
        } else {
            puts("N");
        }
    }
    return 0;
}

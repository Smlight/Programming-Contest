#include <bits/stdc++.h>
using namespace std;

map<char,int> op;
map<char,string> args;

int main()
{
    std::ios::sync_with_stdio(false);
    string s;
    cin>>s;
    for (int i=0;i<(int)s.length();++i) {
        if (s[i]==':') {
            op[s[i-1]]=1;
        } else {
            op[s[i]]=0;
        }
    }
    int T,cas=0;
    cin>>T;
    getline(cin,s);
    while (T--) {
        getline(cin,s);
        stringstream ss(s);
        args.clear();
        string t;
        ss>>t;
        while (ss>>t) {
            if (t.length()==2&&t[0]=='-'&&op.find(t[1])!=op.end()) {
                char c=t[1];
                if (args.find(c)==args.end()) args[c]="";
                if (op[c]) {
                    string r;
                    ss>>r;
                    if (r!="") args[c]=r;
                }
            } else {
                break;
            }
        }
        cout<<"Case "<<++cas<<":";
        for (map<char,string>::iterator it=args.begin();it!=args.end();++it) {
            cout<<" -"<<it->first;
            if (it->second!="") cout<<" "<<it->second;
        }
        cout<<endl;
    }
    return 0;
}

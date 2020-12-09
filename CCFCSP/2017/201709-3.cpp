#include <bits/stdc++.h>
using namespace std;

const int N=8010;
string s,t,key[N],val[N];
int tot=0;
vector<int> E[8010];

int newNode(string a)
{
    key[++tot]=a;
    return tot;
}

void dfs(int rt,int l,int r)
{
//A:    cout<<s.substr(l,r-l)<<endl;
    int p=l;
    while (p<r&&s[p]!='{') ++p;
    if (p==r) return;
    while (true) {
        while (p<r&&s[p]!='"') ++p;
        if (p==r) break;
        string tmp;
        ++p;
        while (true) {
            if (s[p]!='\\') {
                if (s[p]=='"') break;
                tmp+=s[p];
                p+=1;
            } else {
                tmp+=s[p+1];
                p+=2;
            }
        }
//B:        cout<<tmp<<endl;
        int x=newNode(tmp);
        E[rt].push_back(x);
        ++p;
        while (s[p]!='"'&&s[p]!='{') ++p;
        if (s[p]=='{') {
            val[x]="OBJECT";
            int nl=p,nr=p;
            int cnt=0;
            while (true) {
                if (s[nr]=='{') {
                    cnt+=1;
                } else if (s[nr]=='}') {
                    cnt-=1;
                }
                ++nr;
                if (cnt==0) break;
            }
            dfs(x,nl,nr);
            p=nr;
        } else {
            val[x]="STRING ";
            string tmp;
            ++p;
            while (true) {
                if (s[p]!='\\') {
                    if (s[p]=='"') break;
                    tmp+=s[p];
                    p+=1;
                } else {
                    tmp+=s[p+1];
                    p+=2;
                }
            }
            val[x]+=tmp;
            ++p;
//C:        cout<<tmp<<endl;
        }
    }

}

string query(int rt)
{
    int p=0;
    while (p<(int)t.length()&&t[p]!='.') ++p;
    string pa(t.substr(0,p));
//C:  cout<<pa<<endl;
    for (int i=0;i<(int)E[rt].size();i++) {
        if (key[E[rt][i]]==pa) {
            if (p==(int)t.length()) return val[E[rt][i]];
            if (val[E[rt][i]]!="OBJECT") return "NOTEXIST";
            p+=1;
            t=t.substr(p,t.length()-p);
            return query(E[rt][i]);
        }
    }
    return "NOTEXIST";
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    string tmp;
    getline(cin,tmp);
    for (int i=1;i<=n;i++) {
        getline(cin,tmp);
        s+=tmp;
        s+=" ";
    }
//D:    puts("RD CPLETE!");
    dfs(++tot,0,s.length());
//E:    puts("PS CPLETE!");
    for (int i=1;i<=m;i++) {
        cin>>t;
        cout<<query(1)<<"\n";
    }
    return 0;
}

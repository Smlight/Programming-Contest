#include<bits/stdc++.h>
using namespace std;

char s[11];
string a[11];

struct Cmp {
    bool operator()(const string &L,const string &R) const {
        if (L.length()!=R.length()) return L.length()>R.length();
        return L<R;
    }
};

bool check(const string &s,const int n)
{
    int len=s.length();
    for (int i=1;i<n;i++) {
        int k=a[i].length()/2;
        bool good=false;
        for (int st=0;st<k;st++) {
            int p=0;
            for (int j=0;j<k;j++) {
                if (a[i][st+j]==s[p]) {
                    if (++p==len) {
                        break;
                    }
                }
            }
            if (p==len) {
                good=true;
                break;
            }
        }
        if (!good) return false;
    }
    return true;
}

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF) {
        for (int i=0;i<n;i++) {
            scanf("%s",s);
            a[i]=s;
            a[i]+=a[i];
        }
        set<string,Cmp> s;
        int k=a[0].length()/2;
        for (int i=0;i<k;i++) {
            for (int j=1;j<(1<<k);j+=2) {
                string tmp;
                for (int p=0;p<k;p++) {
                    if (j>>p&1) {
                        tmp+=a[0][i+p];
                    }
                }
                s.insert(tmp);
            }
        }
        bool good=false;
        for (auto &p:s) {
            if (check(p,n)) {
                puts(p.c_str());
                good=true;
                break;
            }
        }
        if (!good) puts("0");
    }
    return 0;
}

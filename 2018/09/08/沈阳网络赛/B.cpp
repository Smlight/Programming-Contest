#include <bits/stdc++.h>
using namespace std;
using PII = pair<int,int>;

const int MAXN=110;
char s[MAXN];

PII dfs(int l,int r)
{
    list<char> optr;
    list<PII> opnd;
    for (int i=l;i<r;i++) {
        if (s[i]=='(') {
            int j=i,cnt=0;
            while (j<r) {
                if (s[j]=='(') ++cnt;
                else if (s[j]==')') {
                    if (--cnt==0) {
                        opnd.push_back(dfs(i+1,j));
                        break;
                    }
                }
                ++j;
            }
            i=j;
        } else if (isdigit(s[i])) {
            int x=0,j=i;
            while (j<r&&isdigit(s[j])) {
                x=x*10+s[j++]-'0';
            }
            opnd.push_back({x,x});
//            printf("IN OPND: %d\n",x);
            i=j-1;
        } else {
            optr.push_back(s[i]);
        }
    }
//    for (auto itnd=opnd.begin();itnd!=opnd.end();++itnd) {
//        printf("%d %d\n",itnd->first,itnd->second);
//    }
    while (true) {
        auto itnd=opnd.begin(),pnd=opnd.end();
        auto ptr=optr.end();
        for (auto ittr=optr.begin();ittr!=optr.end();++itnd,++ittr) {
            if (*ittr=='d') {
                ptr=ittr;
                pnd=itnd;
            }
        }
        if (ptr==optr.end()) break;
        auto nnd=pnd;
        ++nnd;
//        printf("%d %d %d %d\n",pnd->first,pnd->second,nnd->first,nnd->second);
        *pnd={pnd->first,pnd->second*nnd->second};
        opnd.erase(nnd);
        optr.erase(ptr);
    }
    while (true) {
        auto itnd=opnd.begin(),pnd=opnd.end();
        auto ptr=optr.end();
        for (auto ittr=optr.begin();ittr!=optr.end();++itnd,++ittr) {
            if (*ittr=='*') {
                ptr=ittr;
                pnd=itnd;
                break;
            }
        }
        if (ptr==optr.end()) break;
        auto nnd=pnd;
        ++nnd;
//        printf("%d %d %d %d\n",pnd->first,pnd->second,nnd->first,nnd->second);
        vector<int> ve{pnd->first*nnd->first,pnd->first*nnd->second,pnd->second*nnd->first,pnd->second*nnd->second};
        sort(begin(ve),end(ve));
        *pnd={ve.front(),ve.back()};
        opnd.erase(nnd);
        optr.erase(ptr);
    }
    while (true) {
        auto itnd=opnd.begin(),pnd=opnd.end();
        auto ptr=optr.end();
        for (auto ittr=optr.begin();ittr!=optr.end();++itnd,++ittr) {
            if (*ittr=='+'||*ittr=='-') {
                ptr=ittr;
                pnd=itnd;
                break;
            }
        }
        if (ptr==optr.end()) break;
        auto nnd=pnd;
        ++nnd;
//        printf("%d %d %d %d\n",pnd->first,pnd->second,nnd->first,nnd->second);
        if (*ptr=='+') {
            *pnd={pnd->first+nnd->first,pnd->second+nnd->second};
        } else {
            *pnd={pnd->first-nnd->second,pnd->second-nnd->first};
        }
        opnd.erase(nnd);
        optr.erase(ptr);
    }
    return opnd.front();
}

int main()
{
    while (scanf("%s",s)!=EOF) {
        int len=strlen(s);
        PII ans(dfs(0,len));
        printf("%d %d\n",ans.first,ans.second);
    }
    return 0;
}

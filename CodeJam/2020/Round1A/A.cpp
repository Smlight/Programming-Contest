#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N=55;
char p[N][N*2];
int l[N],r[N];
int len[N];

bool check(const vector<string> &ve, string &s)
{
    s = "";
    for (int i=0;i<ve.size();i++) {
        if (ve[i].length()>s.length()) s = ve[i];
    }
    for (int i=0;i<ve.size();i++) {
        for (int j=0;j<ve[i].length();j++) {
            if (ve[i][j]!=s[j]) return false;
        }
    }
    return true;
}

int main()
{
    int T,cas=0;
    scanf("%d",&T);
    while (T--) {
        int n;
        scanf("%d",&n);
        printf("Case #%d: ",++cas);
        memset(l,-1,sizeof(l));
        memset(r,-1,sizeof(r));
        vector<string> suf,pre;
        for (int i=0;i<n;i++) {
            scanf("%s",p[i]);
            len[i]=strlen(p[i]);
            int x=0;
            while (x<len[i] && p[i][x]!='*') ++x;
            l[i]=x;
            if (0<x) {
                pre.push_back(string(p[i],p[i]+x));
            }
            int y=len[i]-1;
            while (y>x && p[i][y]!='*') --y;
            r[i]=y;
            if (y+1<len[i]) {
                string tmp(p[i]+y+1,p[i]+len[i]);
                // cout<<"tmp:" << tmp<<endl;
                reverse(tmp.begin(),tmp.end());
                suf.push_back(tmp);
            }
        }
        // puts("stage1");
        string pref, suff;
        if (!check(pre,pref)) {
            puts("*");
            continue;
        }
        if (!check(suf,suff)) {
            puts("*");
            continue;
        }
        reverse(suff.begin(),suff.end());
        // cout<<pref<<endl;
        // cout<<suff<<endl;
        // puts("stage2");
        string mid;
        for (int i=0;i<n;i++) {
            for (int j=l[i]+1;j<r[i];j++) {
                if (p[i][j]!='*') mid+=p[i][j];
            }
        }
        string ans(pref+mid+suff);
        puts(ans.c_str());
        // puts("stage3");
    }
    return 0;
}
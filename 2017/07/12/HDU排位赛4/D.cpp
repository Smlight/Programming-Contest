#include <bits/stdc++.h>
using namespace std;

vector<string> ds[4];
char s[100];

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF) {
        getchar();
        for (int i=0;i<4;i++) {
            ds[i].clear();
        }
        ds[0].push_back("C:");
        ds[1].push_back("D:");
        ds[2].push_back("E:");
        ds[3].push_back("F:");
        int nowd=0;
        ds[0].push_back("users");
        ds[0].push_back("godle");
        for (int i=1;i<=n;i++) {
            gets(s);
            if (s[0]=='c') {
                if (strcmp(s+3,"..")==0) {
                    if (ds[nowd].size()>1) {
                        ds[nowd].pop_back();
                    }
                } else {
                    ds[nowd].push_back(s+3);
                }
            } else {
                nowd=s[0]-'C';
            }
            for (int j=0;j<ds[nowd].size();j++) {
                printf("%s",ds[nowd][j].c_str());
                if (j==ds[nowd].size()-1) puts("");
                else putchar('\\');
            }
        }
    }
    return 0;
}

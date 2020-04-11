#include <bits/stdc++.h>
using namespace std;

const int N=105;
char s[N];

int main()
{
    int T,cas=0;
    scanf("%d",&T);
    while (T--) {
        scanf("%s",s);
        printf("Case #%d: ",++cas);
        int n=strlen(s);
        s[n++]='0';
        int dep=0;
        for (int i=0;i<n;i++) {
            while (dep<s[i]-'0') {
                putchar('(');
                ++dep;
            }
            while (dep>s[i]-'0') {
                putchar(')');
                --dep;
            }
            if (i<n-1) putchar(s[i]);
        }
        puts("");
    }
    return 0;
}
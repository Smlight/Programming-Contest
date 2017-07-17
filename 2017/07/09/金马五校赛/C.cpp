#include <bits/stdc++.h>
using namespace std;

char s[100010];
int c[30];

int main()
{
    while (scanf("%s",s)!=EOF) {
        memset(c,0,sizeof(c));
        for (int i=0;s[i];i++) {
            if (s[i]>'a') {
                c[s[i]-'a']++;
            } else {
                c[s[i]-'A']++;
            }
        }
        int ans=c['i'-'a'];
        ans=min(ans,c['l'-'a']);
        ans=min(ans,c['o'-'a']);
        ans=min(ans,c['v'-'a']);
        ans=min(ans,c['c'-'a']);
        ans=min(ans,c['s'-'a']);
        ans=min(ans,c['e'-'a']/2);
        printf("%d\n",ans);
    }
    return 0;
}

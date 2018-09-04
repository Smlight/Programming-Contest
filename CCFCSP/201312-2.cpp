#include <bits/stdc++.h>
using namespace std;

char s[22];

int main()
{
    scanf("%s",s);
    int n=strlen(s),t=0,ans=0;
    for (int i=0;i<n;i++) {
        if ('0'<=s[i]&&s[i]<='9') {
            ans+=(++t)*(s[i]-'0');
            if (t==9) break;
        }
    }
    ans%=11;
    char c=(ans<10)?'0'+ans:'X';
    if (s[n-1]==c) {
        puts("Right");
    } else {
        s[n-1]=c;
        puts(s);
    }
    return 0;
}

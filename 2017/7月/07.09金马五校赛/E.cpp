#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int ans[100];
char s[100];

int main()
{
    int m;
    while (scanf("%s %d",s,&m)!=EOF) {
        ll x=0;
        for (int i=0;s[i];i++) {
            x=x*26+s[i]-'a';
        }
        int top=0;
        do {
            ans[top++]=x%m;
            x/=m;
        } while (x);
        for (int i=top-1;i>=0;i--) {
            printf("%d",ans[i]);
        }
        puts("");
    }
    return 0;
}

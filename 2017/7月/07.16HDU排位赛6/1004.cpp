#include <bits/stdc++.h>
using namespace std;

int n;
char s[400];

bool check(char *a,char *b)
{
    for (int i=0;i<n;i++) {
        if (a[i]<=b[i]) return false;
    }
    return true;
}

int main()
{
    while (scanf("%d",&n)!=EOF) {
        scanf("%s",s);
        sort(s,s+n);
        sort(s+n,s+n*2);
        if (check(s,s+n)||check(s+n,s)) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}

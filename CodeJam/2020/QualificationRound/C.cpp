#include <bits/stdc++.h>
using namespace std;

const int N=1024;
int s[N],e[N],p[N];
char ans[N];

bool ok(int n)
{
    for (int i=1;i<=n;i++) {
        p[i]=i;
    }
    sort(p+1,p+n+1,[&](const int &i,const int &j){ return s[i]<s[j]; });
    int edt0=0,edt1=0;
    for (int i=1;i<=n;i++) {
        int j=p[i];
        if (edt0<=s[j]) {
            edt0=e[j];
            ans[j]='C';
        } else if (edt1<=s[j]) {
            edt1=e[j];
            ans[j]='J';
        } else {
            return false;
        }
    }
    ans[n+1]=0;
    return true;
}

int main()
{
    int T,cas=0;
    scanf("%d",&T);
    while (T--) {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++) {
            scanf("%d%d",&s[i],&e[i]);
        }
        printf("Case #%d: ",++cas);
        if (ok(n)) {
            puts(ans+1);
        } else {
            puts("IMPOSSIBLE");
        }
    }
    return 0;
}
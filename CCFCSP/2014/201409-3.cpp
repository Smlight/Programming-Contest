#include <bits/stdc++.h>
using namespace std;

const int N=105;
char s[N],d[N][N],o[N][N];

int main()
{
    scanf("%s",s);
    int k,n;
    scanf("%d",&k);
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf("%s",d[i]);
        strcpy(o[i],d[i]);
    }
    if (k==0) {
        for (int i=0;s[i];i++) {
            if (s[i]<'a') {
                s[i]-='A'-'a';
            }
        }
        for (int i=0;i<n;i++) {
            for (int j=0;d[i][j];j++) {
                if (d[i][j]<'a') {
                    d[i][j]-='A'-'a';
                }
            }
        }
    }
    for (int i=0;i<n;i++) {
        if (strstr(d[i],s)) {
            puts(o[i]);
        }
    }
    return 0;
}

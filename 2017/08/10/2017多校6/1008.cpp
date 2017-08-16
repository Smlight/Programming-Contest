#include <bits/stdc++.h>
using namespace std;

int T,n,m;
char s[5010];

int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&m);
        scanf("%s",s);
        n=strlen(s);
        int ans=0;
        for (int i=0;i<n;i++) {
            int q=0,co=0;
            for (int p=1;i-p+1>=0&&i+p<n;p++) {
                co+=abs(s[i-p+1]-s[i+p]);
                while (co>m) {
                    ++q;
                    co-=abs(s[i-q+1]-s[i+q]);
                }
                ans=max(ans,p-q);
            }
        }
        for (int i=1;i<n;i++) {
            int q=0,co=0;
            for (int p=1;i-p>=0&&i+p<n;p++) {
                co+=abs(s[i-p]-s[i+p]);
                while (co>m) {
                    ++q;
                    co-=abs(s[i-q]-s[i+q]);
                }
                ans=max(ans,p-q);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T,x;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&x);
        int len=0;
        while (x) {
            len++;
            x/=10;
        }
        char p[10]={0};
        for (int i=0;i<len;i++) {
            p[i]='0';
        }
        p[len-1]='1';
        string ans;
        for (int i=1;i<=233;i++) {
            if (i==1) {
                ans+="1";
            } else {
                ans+=p;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
